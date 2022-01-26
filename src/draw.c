/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 23:33:41 by vkuklys           #+#    #+#             */
/*   Updated: 2022/01/23 21:42:42 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void draw_walls(t_wall *wall, t_img *img, int x)
{
	int wall_y;
	int pixel;
	int y;
	y = wall->top;
	while (y < wall->bottom)
	{
		wall_y = (int)wall->position & (64 - 1);
		wall->position += wall->step;
		if (wall->direction == EAST)
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

int draw_sky(t_data *data, int x, int up_to)
{
	int i;
	int color = createRGB(105, 105, 105); //has to be replaced

	i = 0;
	while (i < up_to && i < data->height)
	{
		my_mlx_pixel_put(&data->img, x, i, color);
		i++;
	}
	return (0);
}

int draw_ground(t_data *data, int x, int from)
{
	int i;
	int color = createRGB(195, 195, 195); //has to be replaced

	i = from;
	while (i < data->height)
	{
		my_mlx_pixel_put(&data->img, x, i, color);
		i++;
	}
	return (0);
}
