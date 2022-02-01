/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 23:39:17 by vkuklys           #+#    #+#             */
/*   Updated: 2022/02/01 04:57:53 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	get_minimap_color(t_data *data, int x, int y)
{
	char	c;

	x = x - 10 + data->p_y;
	y = y - 10 + data->p_x;
	if (x < 0 || y < 0 || x >= data->map.rows || y >= data->map.columns)
		return (0x000000);
	c = data->map.map[y][x];
	if (c == '0')
		return (0xf0f8ff);
	else if (c == '1' || c == '3')
		return (0x1E90FF);
	else if (c == ' ' || c == '\0')
		return (0x000000);
	else
		return (0x00FF00);
}

int	get_color(char c)
{
	int	color;

	if (c == '0')
		color = 0xf0f8ff;
	else if (c == '2')
		color = 0x00FF00;
	else if (c == '1' || c == '3')
		color = 0x1E90FF;
	else
		color = 0;
	return (color);
}

int	get_pixel(t_wall *wall, t_img *img, int y)
{
	int	pixel;

	if (wall->type == EAST && wall->door && (wall->direction == SOUTH
			|| wall->direction == NORTH))
		pixel = img->textures.gates[wall->x][y];
	else if (wall->type == SOUTH && wall->door && (wall->direction == EAST
			|| wall->direction == WEST))
		pixel = img->textures.gates[wall->x][y];
	else if (wall->direction == EAST)
		pixel = img->textures.east_wall[wall->x][y];
	else if (wall->direction == WEST)
		pixel = img->textures.west_wall[wall->x][y];
	else if (wall->direction == NORTH)
		pixel = img->textures.north_wall[wall->x][y];
	else
		pixel = img->textures.south_wall[wall->x][y];
	return (pixel);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->sl + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	my_mlx_pixel_get(t_img *img, int x, int y)
{
	int		color;
	char	*dst;

	dst = img->textures.tex_addr + (y * img->sl + x * (img->bpp / 8));
	color = *(unsigned int *)dst;
	return (color);
}
