/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 04:34:51 by vkuklys           #+#    #+#             */
/*   Updated: 2022/02/01 19:34:09 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	exit_maze(t_data *data, int flag)
{
	// free(data->img.addr);data->img.addr=NULL;//should be done by destroy_img
	// free(data->mlx_win);free(data->mlx_ptr);data->mlx_win=NULL;data->mlx_ptr=NULL;// check if needed
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	data->mlx_win=NULL;
	data->mlx_ptr=NULL;
	free_all(data, 0);
	if (flag) // is this really set up the right way round?
		exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
}

int	key_press(int key, t_data *data)
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

int	key_release(int key, t_data *data)
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

int	mouse_hook(int x, int y, t_data *data)
{
	static int	prev;
	int			current;

	current = x;
	if (current > prev)
	{
		update_game(ROTATE_RIGHT, data);
	}
	else if (current < prev)
	{
		update_game(ROTATE_LEFT, data);
	}
	prev = current;
	return (y);
}
