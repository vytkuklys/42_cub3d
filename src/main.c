// // /* ************************************************************************** */
// // /*                                                                            */
// // /*                                                        :::      ::::::::   */
// // /*   main.c                                             :+:      :+:    :+:   */
// // /*                                                    +:+ +:+         +:+     */
// // /*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
// // /*                                                +#+#+#+#+#+   +#+           */
// // /*   Created: 2022/01/18 22:40:39 by vkuklys           #+#    #+#             */
// // /*   Updated: 2022/01/19 17:09:09 by random_          ###   ########.fr       */
// // /*                                                                            */
// // /* ************************************************************************** */

#include "../include/cub3d.h"
#include <time.h>

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->sl + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	init_img(t_img *img)
{
	//
	img->tex_paths = ft_calloc(TOTAL_ELEMENTS + 1, sizeof(char *));
	// if (img->tex_paths == NULL)
	// 	return (error_init_img());
	img->tex_paths[4] = ft_strdup("images/left_hand.xpm");
	img->tex_paths[5] = ft_strdup("images/right_hand.xpm");
	//
	img->north_path = NULL;
	img->south_path = NULL;
	img->west_path = NULL;
	img->east_path = NULL;
	img->ceiling_rgb[0] = -1;
	img->floor_rgb[0] = -1;
}

void	init_controls(t_controls *controls)
{
	controls->up = -1;
	controls->left = -1;
	controls->down = -1;
	controls->right = -1;
	controls->escape = -1;
	controls->rotate_left = -1;
	controls->rotate_right = -1;
}

void	init_data(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "Cub3d");
	data->p_x = 4;
	data->p_y = 7;
	data->plane_x = 0;
	data->plane_y = -0.71;
	data->dir_x = 1;
	data->dir_y = 0;
	data->tmp_str = NULL;
	data->map.map = NULL;
	data->wall.type = '\0';
	init_textures(data);
	init_img(&data->img);
	init_controls(&data->controls);
	init_door(&data->door);
}

bool	is_movement(t_data *data)
{
	if (data->controls.down != -1 || data->controls.left != -1 || data->controls.right != -1 || data->controls.up != -1)
		return (true);
	return (false);
}

int	draw_game(t_data *data)//think about void
{
	int	x;
	static int	left;
	static bool	up;

	data->img.img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img_ptr, &data->img.bpp,
			&data->img.sl, &data->img.endian);
	check_events(data);
	x = 0;
	usleep(3750);
	while (x < WIDTH)
	{
		get_ray_data(data, x);
		get_wall_data(data);
		draw_walls(&data->wall, &data->img, x);
		draw_ceiling(data, x, data->wall.top);
		draw_floor(data, x, data->wall.bottom);
		if (data->door.found)
			prepare_door_drawing(data, x);
		x++;
	}
	draw_minimap(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->img.img_ptr, 0, 0);
	if (left == - 30)
		up = true;
	else if (left == 30)
		up = false;
	if (up == true && is_movement(data) == true)
		left += 2;
	else if (is_movement(data) == true)
		left -= 2;
	// mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.textures.tex_addr[left_hand], 0, left + 30);
	// mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.textures.tex_addr[right_hand], 0, left + 30);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.textures.left_hand, 0, left + 30);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.textures.right_hand, 0, left * -1 + 30);
	mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	return (0);
}

int	test(int x, int y, t_data *data) // mouse hook
{
	static int	prev;
	int			current;

	current = x;
	if (current > prev)
	{
		update_game(ROTATE_RIGHT, data);
	}
	else if (current < prev)
	{
		update_game(ROTATE_LEFT, data);
	}
	prev = current;
	return (y);
}

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argc;//implement the use argc and argv
	(void)argv;
	// if (argc != 2)
	// 	return (error_input());
	init_data(&data);
	if (init_map("maps/doors.cub", &data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (is_map_valid(&data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	mlx_loop_hook(data.mlx_ptr, draw_game, &data);
	mlx_hook(data.mlx_win, 6, 1L << 0, test, &data);
	mlx_hook(data.mlx_win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.mlx_win, 3, 1L << 0, key_release, &data);
	mlx_hook(data.mlx_win, 17, 1L << 17, exit_maze, &data);
	mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
}
