/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 01:50:07 by vkuklys           #+#    #+#             */
/*   Updated: 2022/01/30 05:20:19 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void get_door_data(t_data *data, t_door *door)
{
	t_wall *wall;
	int line_height;
	double hit_point;

	wall = &data->wall;
	line_height = (int)(HEIGHT / door->length);
	wall->top = -line_height / 1.5 + HEIGHT / 2 + 0;
	if (wall->top < 0)
		wall->top = 0;
	wall->bottom = line_height / 1.5 + HEIGHT / 2 + 0;
	if (wall->bottom >= HEIGHT)
		wall->bottom = HEIGHT - 1;
	if (door->side == 0)
		hit_point = data->p_y + door->length * door->dir_y;
	else
		hit_point = data->p_x + door->length * door->dir_x;
	hit_point -= floor((hit_point));
	wall->x = (int)(hit_point * (double)(64));
	if ((door->side == 0 && door->dir_x > 0) || (door->side == 1 && door->dir_y < 0))
		wall->x = 64 - wall->x - 1;
	wall->step = (1.0 * 64 / line_height) * 0.75;
	wall->position = (wall->top - 0 - HEIGHT / 2 + line_height / 1.5) * wall->step;
}

void set_door_data(t_data *data, int x)
{
	data->door.found = true;
	data->door.length = count_ray_length(data);
	data->door.x = x;
	data->door.side = data->ray.side;
	data->door.dir_x = data->ray.dir_x;
	data->door.dir_y = data->ray.dir_y;
}

void init_door(t_door *door)
{
	door->found = false;
	door->open[0] = -1;
	door->open[1] = -1;
	door->length = 0;
	door->x = 0;
	door->side = 0;
	door->dir_x = 0;
	door->dir_y = 0;
}

int close_door(t_data *data)
{
	int x;
	if (data->door.open[0] == -1)
		return (EXIT_SUCCESS);
	else
	{
		x = data->door.open[0];
		if (data->p_x <= (double)x - 0.3 || data->p_x >= (double)x + 1.3)
		{
			data->map.map[data->door.open[0]][data->door.open[1]] = '2';
			data->door.open[0] = -1;
			data->door.open[1] = -1;
		}
	}
	return (EXIT_FAILURE);
}

int open_door(t_data *data)
{
	int y;
	int x;

	if (close_door(data) == EXIT_FAILURE)
	{
		return (0);
	}
	if (data->dir_x > 0)
		y = (int)((data->p_x + data->dir_x * SPEED) + WALL_DISTANCE);
	else
		y = (int)((data->p_x + data->dir_x * SPEED) - WALL_DISTANCE);
	x = (int)(data->p_y);
	if (data->map.map[y][x] == '2')
	{
		data->door.open[0] = y;
		data->door.open[1] = x;
		data->map.map[y][x] = '0';
	}
	return (EXIT_SUCCESS);
}