/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 23:13:32 by vkuklys           #+#    #+#             */
/*   Updated: 2022/01/29 02:17:05 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int exit_maze(t_data *data, int flag)
{
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	if (flag)
		exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
}

int key_press(int key, t_data *data)
{
	if (key == MOVE_UP)
		data->controls.up = MOVE_UP;
	else if (key == MOVE_DOWN)
		data->controls.down = MOVE_DOWN;
	else if (key == MOVE_LEFT)
		data->controls.left = MOVE_LEFT;
	else if (key == MOVE_RIGHT)
		data->controls.right = MOVE_RIGHT;
	else if (key == ROTATE_LEFT)
		data->controls.rotate_left = ROTATE_LEFT;
	else if (key == ROTATE_RIGHT)
		data->controls.rotate_right = ROTATE_RIGHT;
	else if (key == ESCAPE)
		data->controls.escape = ESCAPE;
	return (EXIT_SUCCESS);
}
int key_release(int key, t_data *data)
{
	if (key == MOVE_UP)
		data->controls.up = -1;
	else if (key == MOVE_DOWN)
		data->controls.down = -1;
	else if (key == MOVE_LEFT)
		data->controls.left = -1;
	else if (key == MOVE_RIGHT)
		data->controls.right = -1;
	else if (key == ROTATE_LEFT)
		data->controls.rotate_left = -1;
	else if (key == ROTATE_RIGHT)
		data->controls.rotate_right = -1;
	else if (key == ESCAPE)
		data->controls.escape = -1;
	return (EXIT_SUCCESS);
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
	if (data->controls.up == MOVE_UP)
		update_game(MOVE_UP, data);
	if (data->controls.down == MOVE_DOWN)
		update_game(MOVE_DOWN, data);
	if (data->controls.left == MOVE_LEFT)
		update_game(MOVE_LEFT, data);
	if (data->controls.right == MOVE_RIGHT)
		update_game(MOVE_RIGHT, data);
	if (data->controls.rotate_left == ROTATE_LEFT)
		update_game(ROTATE_LEFT, data);
	if (data->controls.rotate_right == ROTATE_RIGHT)
		update_game(ROTATE_RIGHT, data);
	if (data->controls.escape == ESCAPE)
		update_game(ESCAPE, data);
}
