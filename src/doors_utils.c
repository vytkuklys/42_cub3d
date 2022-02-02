/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 04:18:58 by vkuklys           #+#    #+#             */
/*   Updated: 2022/02/02 18:20:58 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	close_south_north_door(t_data *data)
{
	int	x;

	x = data->door->open_s_n[0];
	if (x == -1)
		return (EXIT_SUCCESS);
	else
	{
		if (data->p_x <= (double)x - 0.3 || data->p_x >= (double)x + 1.3)
		{
			data->map.map[data->door->open_s_n[0]][data->door->open_s_n[1]]
				= '2';
			data->map.map[data->door->open_s_n[0]][data->door->open_s_n[1] - 1]
				= '1';
			data->map.map[data->door->open_s_n[0]][data->door->open_s_n[1] + 1]
				= '1';
			data->wall.type = '\0';
			data->door->open_s_n[0] = -1;
			data->door->open_s_n[1] = -1;
		}
	}
	return (EXIT_FAILURE);
}

int	close_east_west_door(t_data *data)
{
	int	y;

	y = data->door->open_e_w[1];
	if (y == -1)
		return (EXIT_SUCCESS);
	else
	{
		if (data->p_y <= (double)y - 0.3 || data->p_y >= (double)y + 1.3)
		{
			data->map.map[data->door->open_e_w[0]][data->door->open_e_w[1]]
				= '2';
			data->map.map[data->door->open_e_w[0] - 1][data->door->open_e_w[1]]
				= '1';
			data->map.map[data->door->open_e_w[0] + 1][data->door->open_e_w[1]]
				= '1';
			data->wall.type = '\0';
			data->door->open_e_w[0] = -1;
			data->door->open_e_w[1] = -1;
		}
	}
	return (EXIT_FAILURE);
}

int	open_south_north_door(t_data *data)
{
	int	y;
	int	x;

	if (close_south_north_door(data) == EXIT_FAILURE)
	{
		return (1);
	}
	if (data->dir_x > 0)
		y = (int)((data->p_x + data->dir_x * SPEED) + WALL_DISTANCE);
	else
		y = (int)((data->p_x + data->dir_x * SPEED) - WALL_DISTANCE);
	x = (int)(data->p_y);
	if (data->map.map[y][x] == '2')
	{
		data->door->open_s_n[0] = y;
		data->door->open_s_n[1] = x;
		data->map.map[y][x - 1] = '3';
		data->map.map[y][x + 1] = '3';
		data->map.map[y][x] = '0';
		data->wall.type = south;
		return (EXIT_SUCCESS);
	}
	return (1);
}

int	open_east_west_door(t_data *data)
{
	int	y;
	int	x;

	if (close_east_west_door(data) == EXIT_FAILURE)
	{
		return (1);
	}
	if (data->dir_y > 0)
		y = (int)(data->p_y + data->dir_y * SPEED + WALL_DISTANCE);
	else
		y = (int)(data->p_y + data->dir_y * SPEED - WALL_DISTANCE);
	x = (int)(data->p_x);
	if (data->map.map[x][y] == '2')
	{
		data->door->open_e_w[0] = x;
		data->door->open_e_w[1] = y;
		data->map.map[x - 1][y] = '3';
		data->map.map[x + 1][y] = '3';
		data->wall.type = east;
		data->map.map[x][y] = '0';
		return (EXIT_SUCCESS);
	}
	return (1);
}
