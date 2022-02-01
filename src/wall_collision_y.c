/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collision_y.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:37:08 by vkuklys           #+#    #+#             */
/*   Updated: 2022/02/01 03:53:30 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	is_y_forwards_wall(t_data *data)
{
	int			y;
	int			x;
	static int	door_bumps = 0;

	if (data->dir_y > 0)
		y = (int)(data->p_y + data->dir_y * SPEED + WALL_DISTANCE);
	else
		y = (int)(data->p_y + data->dir_y * SPEED - WALL_DISTANCE);
	x = (int)(data->p_x);
	if (open_east_west_door(data) == EXIT_SUCCESS && ++door_bumps < 7)
	{
		close_east_west_door(data);
		return (true);
	}
	door_bumps = 0;
	if (data->p_x - (int)data->p_x == 0 && ((data->map.map[x - 1][y] != '0'
			&& (1 - (data->p_y - (int)data->p_y) < CORNER_DISTANCE))
		|| (data->map.map[x - 1][y] != '0' && (data->p_y - (int)data->p_y)
		< CORNER_DISTANCE) || (data->map.map[x + 1][y] != '0'
		&& sqrt(pow(1 - (data->p_x - (int)data->p_x), 2)
		+ pow(1 - (data->p_y - (int)data->p_y), 2)) < CORNER_DISTANCE)))
		return (true);
	if (data->map.map[x][y] == '0')
		return (false);
	return (true);
}

int	is_y_backwards_wall(t_data *data)
{
	int	y;
	int	x;

	if (data->dir_y > 0)
		y = (int)(data->p_y - data->dir_y * SPEED - WALL_DISTANCE);
	else
		y = (int)(data->p_y - data->dir_y * SPEED + WALL_DISTANCE);
	x = (int)(data->p_x);
	if ((data->p_x - (int)data->p_x) == 0 && ((data->map.map[x - 1][y] != '0'
			&& sqrt(pow(data->p_x - (int)data->p_x, 2) + pow(data->p_y
					- (int)data->p_y, 2)) < CORNER_DISTANCE)
		|| (data->map.map[x - 1][y] != '0' && sqrt(pow(data->p_x
				- (int)data->p_x, 2) + pow(1 - (data->p_y
					- (int)data->p_y), 2)) < CORNER_DISTANCE)
		|| (data->map.map[x + 1][y] != '0' && sqrt(pow(1 - (data->p_x
	- (int)data->p_x), 2) + pow((data->p_y - (int)data->p_y), 2))
	< CORNER_DISTANCE)))
		return (true);
	if (data->map.map[x][y] == '0')
		return (false);
	return (true);
}

int	is_y_right_wall(t_data *data)
{
	int	y;
	int	x;

	if (data->dir_x > 0)
		y = (int)(data->p_y - WALL_DISTANCE);
	else
		y = (int)(data->p_y + WALL_DISTANCE);
	x = (int)(data->p_x + data->dir_x * SPEED);
	if (data->ray.step_y == 1)
	{
		if (data->p_x - (int)data->p_x == 0 && data->map.map[x + 1][y] != '0'
				&& sqrt(pow(data->p_x - (int)data->p_x, 2)
			+ pow(1 - (data->p_y - (int)data->p_y), 2)) < CORNER_DISTANCE)
			return (true);
	}
	else
	{
		if (data->p_x - (int)data->p_x == 0 && data->map.map[x - 1][y] != '0'
				&& sqrt(pow(data->p_x - (int)data->p_x, 2)
			+ pow((data->p_y - (int)data->p_y), 2)) < CORNER_DISTANCE)
			return (true);
	}
	if (data->map.map[x][y] == '0')
		return (false);
	return (true);
}

int	is_y_left_wall(t_data *data)
{
	int	y;
	int	x;

	if (data->dir_x > 0)
		y = (int)(data->p_y + WALL_DISTANCE);
	else
		y = (int)(data->p_y - WALL_DISTANCE);
	x = (int)(data->p_x + data->dir_x * SPEED);
	if (data->ray.step_y == 1)
	{
		if (data->p_x - (int)data->p_x == 0 && data->map.map[x + 1][y] != '0'
				&& sqrt(pow((data->p_x - (int)data->p_x), 2)
			+ pow((data->p_y - (int)data->p_y), 2)) < CORNER_DISTANCE)
			return (true);
	}
	else
	{
		if (data->p_x - (int)data->p_x == 0 && data->map.map[x - 1][y] != '0'
			&& sqrt(pow((data->p_x - (int)data->p_x), 2) + pow(1 - (data->p_y
				- (int)data->p_y), 2)) < CORNER_DISTANCE)
			return (true);
	}
	if (data->map.map[x][y] == '0')
		return (false);
	return (true);
}
