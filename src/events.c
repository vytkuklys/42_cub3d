/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 23:13:32 by vkuklys           #+#    #+#             */
/*   Updated: 2022/01/27 00:31:29 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	exit_maze(t_data *data, int flag)
{
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	if (flag)
		exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
}

int key_press(int key, t_data *data)
{
	if (data->pressed_key == -1 && data->pressed_key2 != key)
		data->pressed_key = key;
	else if (data->pressed_key != key)
	{
		data->pressed_key2 = key;
	}
	return (1);
}
int key_release(int key, t_data *data)
{
	if (data->pressed_key == key)
	{
		data->pressed_key = -1;
	}
	if (data->pressed_key2 == key)
	{
		data->pressed_key2 = -1;
	}
	return (key);
}

int rotate_view(int key, t_data *data)
{
	double old_dir;
	double old_plane;

	if (key == ROTATE_RIGHT)
	{
		old_dir = data->dir_x;
		data->dir_x = data->dir_x * cos(-ROTATION) - data->dir_y * sin(-ROTATION);
		data->dir_y = old_dir * sin(-ROTATION) + data->dir_y * cos(-ROTATION);
		old_plane = data->plane_x;
		data->plane_x = data->plane_x * cos(-ROTATION) - data->plane_y * sin(-ROTATION);
		data->plane_y = old_plane * sin(-ROTATION) + data->plane_y * cos(-ROTATION);
	}
	else if (key == ROTATE_LEFT)
	{
		old_dir = data->dir_x;
		data->dir_x = data->dir_x * cos(ROTATION) - data->dir_y * sin(ROTATION);
		data->dir_y = old_dir * sin(ROTATION) + data->dir_y * cos(ROTATION);
		old_plane = data->plane_x;
		data->plane_x = data->plane_x * cos(ROTATION) - data->plane_y * sin(ROTATION);
		data->plane_y = old_plane * sin(ROTATION) + data->plane_y * cos(ROTATION);
	}
	return (0);
}

int exit_left(int key, t_data *data)
{
	if (key == MOVE_LEFT)
	{
		if (!is_x_left_wall(data))
			data->p_x -= data->dir_y * SPEED;
		if (!is_y_left_wall(data))
			data->p_y += data->dir_x * SPEED;
		return (1);
	}
	else if (key == ESCAPE)
	{
		exit(0);
	}
	return (0);
}

int update_game(int key, t_data *data)
{
	if (key == MOVE_UP)
	{
		if (!is_x_forwards_wall(data))
			data->p_x += data->dir_x * SPEED;
		if (!is_y_forwards_wall(data))
			data->p_y += (data->dir_y * SPEED);
	}
	else if (key == MOVE_DOWN)
	{
		if (!is_x_backwards_wall(data))
			data->p_x -= data->dir_x * SPEED;
		if (!is_y_backwards_wall(data))
			data->p_y -= (data->dir_y * SPEED);
	}
	else if (key == MOVE_RIGHT)
	{
		if (!is_x_right_wall(data))
			data->p_x += data->dir_y * SPEED;
		if (!is_y_right_wall(data))
			data->p_y -= data->dir_x * SPEED;
	}
	else if (exit_left(key, data) || rotate_view(key, data))
		;
	return (0);
}

void check_events(t_data *data)
{
	if (data->pressed_key > -1 && data->pressed_key2 != data->pressed_key)
	{
		update_game(data->pressed_key, data);
	}
	if (data->pressed_key2 > -1 && data->pressed_key2 != data->pressed_key)
	{
		update_game(data->pressed_key2, data);
	}
}
