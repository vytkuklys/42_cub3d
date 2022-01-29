/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:37:08 by vkuklys           #+#    #+#             */
/*   Updated: 2022/01/28 23:13:08 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// int data->map.map[MAPWIDTH][MAPHEIGHT] =
// 	{
// 		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
// 		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 		{1, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
// 		{1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
// 		{1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1},
// 		{1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 		{1, 0, 0, 0, 0, 0, 2, 2, 0, 2, 2, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
// 		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 		{1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 11, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 		{1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 		{1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 		{1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 		{1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 		{1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 		{1, 4, 0, 4, 4, 4, 4, 4, 4, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 		{1, 4, 0, 4, 0, 0, 0, 0, 4, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 		{1, 4, 0, 0, 0, 0, 5, 0, 4, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 		{1, 4, 0, 4, 0, 0, 0, 0, 4, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 		{1, 4, 0, 4, 4, 4, 4, 4, 4, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 		{1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 		{1, 0, 0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

int is_corner_backwards(float x, float y)
{
	float x1;
	float y1;

	x1 = x - (int)x;
	y1 = y - (int)y;
	if (y1 == 0 && x1 != 0 && x1 > 0.9)
		return (0);
	return (1);
}

int is_y_forwards_wall(t_data *data)
{
	int y;
	int x;

	if (data->dir_y > 0)
		y = (int)(data->p_y + data->dir_y * SPEED + WALL_DISTANCE);
	else
		y = (int)(data->p_y + data->dir_y * SPEED - WALL_DISTANCE);
	x = (int)(data->p_x);
	if (data->p_x - (int)data->p_x == 0 && ((data->map.map[x - 1][y] != '0' && sqrt(pow(data->p_x - (int)data->p_x, 2) + pow(data->p_y - (int)data->p_y, 2)) < CORNER_DISTANCE) || (data->map.map[x + 1][y] != '0' && sqrt(pow(1 - (data->p_x - (int)data->p_x), 2) + pow(1 - (data->p_y - (int)data->p_y), 2)) < CORNER_DISTANCE)))
	{
		return (true);
	}
	if (data->map.map[x][y] == '0')
	{
		return (false);
	}
	return (true);
}

int is_x_forwards_wall(t_data *data)
{
	int y;
	int x;

	if (data->dir_x > 0)
		y = (int)((data->p_x + data->dir_x * SPEED) + WALL_DISTANCE);
	else
		y = (int)((data->p_x + data->dir_x * SPEED) - WALL_DISTANCE);
	x = (int)(data->p_y);
	if (data->p_y - (int)data->p_y == 0 && ((data->map.map[y][x - 1] != '0' && sqrt(pow(data->p_x - (int)data->p_x, 2) + pow(data->p_y - (int)data->p_y, 2)) < CORNER_DISTANCE) || (data->map.map[y][x + 1] != '0' && sqrt(pow((data->p_x - (int)data->p_x), 2) + pow(1 - (data->p_y - (int)data->p_y), 2)) < CORNER_DISTANCE)))
	{
		return (true);
	}
	if (data->map.map[y][x] == '0')
	{
		return (false);
	}
	return (true);
}

int is_x_backwards_wall(t_data *data)
{
	int y;
	int x;

	if (data->dir_x > 0)
		y = (int)(data->p_x - data->dir_x * SPEED - WALL_DISTANCE);
	else
		y = (int)(data->p_x - data->dir_x * SPEED + WALL_DISTANCE);
	x = (int)(data->p_y);
	if (data->p_y - (int)data->p_y == 0 && ((data->map.map[y][x - 1] != '0' && sqrt(pow(1 - (data->p_x - (int)data->p_x), 2) + pow(data->p_y - (int)data->p_y, 2)) < CORNER_DISTANCE) || (data->map.map[y][x + 1] != '0' && sqrt(pow(1 - (data->p_x - (int)data->p_x), 2) + pow(1 - (data->p_y - (int)data->p_y), 2)) < CORNER_DISTANCE)))
	{
		return (true);
	}
	if (data->map.map[y][x] == '0')
	{
		return (false);
	}
	return (true);
}

int is_y_backwards_wall(t_data *data)
{
	int y;
	int x;

	if (data->dir_y > 0)
		y = (int)(data->p_y - data->dir_y * SPEED - WALL_DISTANCE);
	else
		y = (int)(data->p_y - data->dir_y * SPEED + WALL_DISTANCE);
	x = (int)(data->p_x);
	if ((data->p_x - (int)data->p_x) == 0 && ((data->map.map[x - 1][y] != '0' && sqrt(pow(data->p_x - (int)data->p_x, 2) + pow(data->p_y - (int)data->p_y, 2)) < 0.05) || (data->map.map[x + 1][y] != '0' && sqrt(pow(1 - (data->p_x - (int)data->p_x), 2) + pow((data->p_y - (int)data->p_y), 2)) < 0.05)))
		return (true);
	if (data->map.map[x][y] == '0')
		return (false);
	return (true);
}

int is_x_right_wall(t_data *data)
{
	int y;
	int x;

	if (data->dir_y > 0)
		y = (int)(data->p_x + WALL_DISTANCE);
	else
		y = (int)(data->p_x - WALL_DISTANCE);
	x = (int)(data->p_y - data->dir_y * SPEED);
	if (data->map.map[y][x] == '0')
	{
		return (false);
	}
	return (true);
}

int is_y_right_wall(t_data *data)
{
	int y;
	int x;

	if (data->dir_x > 0)
		y = (int)(data->p_y - WALL_DISTANCE);
	else
		y = (int)(data->p_y + WALL_DISTANCE);
	x = (int)(data->p_x + data->dir_x * SPEED);
	if (data->p_x - (int)data->p_x == 0 && data->map.map[x + 1][y] != '0' && sqrt(pow(data->p_x - (int)data->p_x, 2) + pow(1 - (data->p_y - (int)data->p_y), 2)) < CORNER_DISTANCE)
		return (true);
	if (data->map.map[x][y] == '0')
	{
		return (false);
	}
	return (true);
}

int is_x_left_wall(t_data *data)
{
	int y;
	int x;

	if (data->dir_y > 0)
		y = (int)(data->p_x - WALL_DISTANCE);
	else
		y = (int)(data->p_x + WALL_DISTANCE);
	x = (int)(data->p_y - data->dir_y * SPEED);
	if (data->map.map[y][x] == '0')
	{
		return (false);
	}
	return (true);
}

int is_y_left_wall(t_data *data)
{
	int y;
	int x;

	if (data->dir_x > 0)
		y = (int)(data->p_y + WALL_DISTANCE);
	else
		y = (int)(data->p_y - WALL_DISTANCE);
	x = (int)(data->p_x + data->dir_x * SPEED);
	if (data->p_x - (int)data->p_x == 0 && data->map.map[x + 1][y] != '0' && sqrt(pow((data->p_x - (int)data->p_x), 2) + pow((data->p_y - (int)data->p_y), 2)) < CORNER_DISTANCE)
		return (true);
	if (data->map.map[x][y] == '0')
		return (false);
	return (true);
}
