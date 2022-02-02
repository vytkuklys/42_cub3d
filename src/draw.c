/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 23:33:41 by vkuklys           #+#    #+#             */
/*   Updated: 2022/02/02 17:56:27 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_walls(t_wall *wall, t_img *img, int x)
{
	int	wall_y;
	int	pixel;
	int	y;

	y = wall->top;
	while (y < wall->bottom)
	{
		wall_y = (int)wall->position & (64 - 1);
		wall->position += wall->step;
		pixel = get_pixel(wall, img, wall_y);
		if (wall->direction != WEST)
			pixel = (pixel >> 1) & 8355711;
		my_mlx_pixel_put(img, x, y, pixel);
		y++;
	}
}

void	draw_doors(t_wall *wall, t_img *img, int x)
{
	int	wall_y;
	int	pixel;
	int	y;

	y = wall->top;
	while (y < wall->bottom)
	{
		wall_y = (int)wall->position & (64 - 1);
		wall->position += wall->step;
		pixel = img->textures.gates[wall->x][wall_y];
		my_mlx_pixel_put(img, x, y, pixel);
		y++;
	}
}

void	draw_ceiling(t_data *data, int x, int up_to)
{
	int	i;
	int	red;
	int	green;
	int	blue;
	int	color;

	red = data->img.ceiling_rgb[0];
	green = data->img.ceiling_rgb[1];
	blue = data->img.ceiling_rgb[2];
	color = createRGB(red, green, blue);
	i = 0;
	while (i < up_to && i < HEIGHT)
	{
		my_mlx_pixel_put(&data->img, x, i, color);
		i++;
	}
}

void	draw_floor(t_data *data, int x, int from)
{
	int	i;
	int	red;
	int	green;
	int	blue;
	int	color;

	red = data->img.floor_rgb[0];
	green = data->img.floor_rgb[1];
	blue = data->img.floor_rgb[2];
	color = createRGB(red, green, blue);
	i = from;
	while (i < HEIGHT)
	{
		my_mlx_pixel_put(&data->img, x, i, color);
		i++;
	}
}

int	draw_game(t_data *data)
{
	int	x;

	data->img.img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	if (data->img.img_ptr == NULL)
	{
		ft_putstr_fd("creating img_ptr failed\n", 2);
		return (exit_maze(data, EXIT_FAILURE));
	}
	data->img.addr = mlx_get_data_addr(data->img.img_ptr, &data->img.bpp,
			&data->img.sl, &data->img.endian);
	if (data->img.addr == NULL)
	{
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
		ft_putstr_fd("creating img.addr failed\n", 2);
		return (exit_maze(data, EXIT_FAILURE));
	}
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
		if (data->door->found)
			prepare_door_drawing(data, x);
		x++;
	}
	draw_minimap(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->img.img_ptr, 0, 0);
	animate_hands(data);
	mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	return (EXIT_SUCCESS);
}
