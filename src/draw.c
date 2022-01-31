/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 23:33:41 by vkuklys           #+#    #+#             */
/*   Updated: 2022/01/31 13:45:41 by tblaase          ###   ########.fr       */
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
		if (wall->type == EAST && wall->door && (wall->direction == SOUTH
				|| wall->direction == NORTH))
			pixel = img->textures.gates[wall->x][wall_y];
		else if (wall->type == SOUTH && wall->door && (wall->direction == EAST
				|| wall->direction == WEST))
			pixel = img->textures.gates[wall->x][wall_y];
		else if (wall->direction == EAST)
			pixel = img->textures.east_wall[wall->x][wall_y];
		else if (wall->direction == WEST)
			pixel = img->textures.west_wall[wall->x][wall_y];
		else if (wall->direction == NORTH)
			pixel = img->textures.north_wall[wall->x][wall_y];
		else
			pixel = img->textures.south_wall[wall->x][wall_y];
		if (wall->direction != WEST) // shadow
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

int	draw_ceiling(t_data *data, int x, int up_to)
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
	return (0);
}

int	draw_floor(t_data *data, int x, int from)
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
	return (0);
}
