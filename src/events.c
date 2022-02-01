/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 23:13:32 by vkuklys           #+#    #+#             */
/*   Updated: 2022/02/01 19:36:40 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	rotate_left(t_data *data)
{
	double	old_dir;
	double	old_plane;

	old_dir = data->dir_x;
	data->dir_x = data->dir_x * cos(ROTATION) - data->dir_y * sin(ROTATION);
	data->dir_y = old_dir * sin(ROTATION) + data->dir_y * cos(ROTATION);
	old_plane = data->plane_x;
	data->plane_x = data->plane_x * cos(ROTATION) - data->plane_y
		* sin(ROTATION);
	data->plane_y = old_plane * sin(ROTATION) + data->plane_y
		* cos(ROTATION);
}

int	rotate_view(int key, t_data *data)
{
	double	old_dir;
	double	old_plane;

	if (key == ROTATE_RIGHT)
	{
		old_dir = data->dir_x;
		data->dir_x = data->dir_x * cos(-ROTATION) - data->dir_y
			* sin(-ROTATION);
		data->dir_y = old_dir * sin(-ROTATION) + data->dir_y * cos(-ROTATION);
		old_plane = data->plane_x;
		data->plane_x = data->plane_x * cos(-ROTATION) - data->plane_y
			* sin(-ROTATION);
		data->plane_y = old_plane * sin(-ROTATION) + data->plane_y
			* cos(-ROTATION);
	}
	else if (key == ROTATE_LEFT)
	{
		rotate_left(data);
	}
	return (1);
}

int	exit_left(int key, t_data *data)
{
	if (key == MOVE_LEFT)
	{
		if (is_x_left_wall(data) == false)
			data->p_x -= data->dir_y * SPEED;
		if (is_y_left_wall(data) == false)
			data->p_y += data->dir_x * SPEED;
		return (1);
	}
	else if (key == ESCAPE)
	{
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
		data->img.img_ptr = NULL;
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		data->mlx_win = NULL;//check if both set NULL are needed
		data->mlx_ptr = NULL;
		free_all(data, 0);
		exit(EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}

void	update_game(int key, t_data *data)
{
	if (key == MOVE_UP)
	{
		if (is_x_forwards_wall(data) == false)
			data->p_x += data->dir_x * SPEED;
		if (is_y_forwards_wall(data) == false)
			data->p_y += (data->dir_y * SPEED);
	}
	else if (key == MOVE_DOWN)
	{
		if (is_x_backwards_wall(data) == false)
			data->p_x -= data->dir_x * SPEED;
		if (is_y_backwards_wall(data) == false)
			data->p_y -= (data->dir_y * SPEED);
	}
	else if (key == MOVE_RIGHT)
	{
		if (is_x_right_wall(data) == false)
			data->p_x += data->dir_y * SPEED;
		if (is_y_right_wall(data) == false)
			data->p_y -= data->dir_x * SPEED;
	}
	else if (exit_left(key, data) || rotate_view(key, data))
		return ;
}

void	check_events(t_data *data)
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
