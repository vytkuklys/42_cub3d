/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:40:39 by vkuklys           #+#    #+#             */
/*   Updated: 2022/01/27 19:48:52 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	worldMap[MAPWIDTH][MAPHEIGHT] = // needs to be removed
	{
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 2, 2, 0, 2, 2, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 4, 0, 4, 4, 4, 4, 4, 4, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 4, 0, 4, 0, 0, 0, 0, 4, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 4, 0, 0, 0, 0, 5, 0, 4, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 4, 0, 4, 0, 0, 0, 0, 4, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 4, 0, 4, 4, 4, 4, 4, 4, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

void my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char *dst;

	dst = img->addr + (y * img->sl + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void init_img(t_img *img)
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

void init_data(t_data *data)
{
	data->width = 1024;
	data->height = 512;
	data->mlx_ptr = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx_ptr, data->width, data->height, "Cub3d");
	data->p_x = 22.4;
	data->p_y = 11;
	data->plane_x = 0;
	data->plane_y = 0.71;
	data->dir_x = -1;
	data->dir_y = 0;
	data->pressed_key = -1;
	data->pressed_key2 = -1;
	data->tmp_str = NULL;
	data->map.map = NULL;
	init_textures(data);
	init_img(&data->img);
}

int draw_game(t_data *data)
{
	int			x;
	static int	left;
	static bool	up;

	data->img.img_ptr = mlx_new_image(data->mlx_ptr, data->width, data->height);
	data->img.addr = mlx_get_data_addr(data->img.img_ptr, &data->img.bpp, &data->img.sl, &data->img.endian);
	check_events(data);
	x = 0;
	while (x < data->width)
	{
		get_ray_data(data, x);
		get_wall_data(data);
		draw_walls(&data->wall, &data->img, x);
		draw_ceiling(data, x, data->wall.top);
		draw_floor(data, x, data->wall.bottom);
		x++;
	}
	draw_minimap(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.img_ptr, 0, 0);
	if (left == - 30)
		up = true;
	else if (left == 30)
		up = false;
	if (up == true && (data->pressed_key != -1 || data->pressed_key2 != -1))
		left += 2;
	else if (data->pressed_key != -1 || data->pressed_key2 != -1)
		left -= 2;
	if (data->pressed_key == -1 && data->pressed_key2)
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.textures.left_hand, 0, left + 30);
	else
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.textures.left_hand, 0, left + 30);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.textures.right_hand, 0, left * -1 + 30);
	mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	return 0;
}

int main(int argc, char **argv)
{
	t_data data;

	(void)argc;
	(void)argv;
	// if (argc != 2)
	// 	return (error_input());
	init_data(&data);
	if (init_map("maps/fuller.cub", &data))
		return (EXIT_FAILURE);
	if (is_map_valid(&data))
		return (EXIT_FAILURE);
	mlx_loop_hook(data.mlx_ptr, draw_game, &data);
	mlx_hook(data.mlx_win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.mlx_win, 3, 1L << 0, key_release, &data);
	mlx_hook(data.mlx_win, 17, 1L << 17, exit_maze, &data);
	mlx_loop(data.mlx_ptr);
}
