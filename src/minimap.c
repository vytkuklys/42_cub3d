/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 21:22:53 by vkuklys           #+#    #+#             */
/*   Updated: 2022/02/01 03:19:04 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_25px(t_img *img, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			my_mlx_pixel_put(img, (x * 5) + i, (y * 5) + j, color);
			j++;
		}
		i++;
	}
}

void	draw_player(t_data *data, int flag)
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = -1;
		while (j < 3)
		{
			if (flag == PARTIAL_MINIMAP)
				my_mlx_pixel_put(&data->img, (10 * 5) + i,
					(10 * 5) + j, 0xDC143C);
			else
				my_mlx_pixel_put(&data->img, (data->p_y * 5) + i,
					(data->p_x * 5) + j, 0xDC143C);
			j++;
		}
		i++;
	}
}

int	draw_partial_minimap(t_data *data)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	while (i < 20)
	{
		j = 0;
		while (j < 20)
		{
			color = get_minimap_color(data, i, j);
			if (color)
				draw_25px(&data->img, i, j, color);
			j++;
		}
		i++;
	}
	draw_player(data, PARTIAL_MINIMAP);
	return (0);
}

int	draw_minimap(t_data *data)
{
	int	rows;
	int	columns;
	int	i;
	int	j;
	int	color;

	rows = data->map.rows;
	columns = data->map.columns;
	if (rows * columns >= MINIMAP_MAX && !draw_partial_minimap(data))
		return (0);
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < columns)
		{
			color = get_color(data->map.map[j][i]);
			if (color)
				draw_25px(&data->img, i, j, color);
			j++;
		}
		i++;
	}
	draw_player(data, 0);
	return (0);
}
