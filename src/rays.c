/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 00:00:33 by vkuklys           #+#    #+#             */
/*   Updated: 2022/02/02 18:20:58 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_cardinal_direction(t_data *data, t_ray *ray)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (data->p_x - (int)data->p_x) * ray->delta_x;
		data->wall.vertical = north;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = ((int)data->p_x + 1.0 - data->p_x) * ray->delta_x;
		data->wall.vertical = south;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (data->p_y - (int)data->p_y) * ray->delta_y;
		data->wall.horizontal = west;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = ((int)data->p_y + 1.0 - data->p_y) * ray->delta_y;
		data->wall.horizontal = east;
	}
}

bool	is_wall(t_data *data, int x, int y, int px)
{
	if (data->map.map[x][y] == '3' && (((data->wall.horizontal == east
		&& data->map.map[x][y - 2] == '3')
		|| (data->wall.horizontal == west && data->map.map[x][y + 2] == '3'))
		|| ((data->wall.vertical == south && data->map.map[x - 2][y] == '3')
		|| (data->wall.vertical == north && data->map.map[x + 2][y] == '3'))))
		data->wall.door = 1;
	if (data->map.map[x][y] == '2')
		set_door_data(data, px);
	if (data->map.map[x][y] != '0' && data->map.map[x][y] != '2')
		return (true);
	return (false);
}

void	find_a_wall(t_data *data, t_ray *ray, int px)
{
	int	wall;
	int	x;
	int	y;

	x = (int)data->p_x;
	y = (int)data->p_y;
	wall = false;
	while (wall == false)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_x;
			x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_y;
			y += ray->step_y;
			ray->side = 1;
		}
		wall = is_wall(data, x, y, px);
	}
}

double	count_ray_length(t_data *data)
{
	t_ray	*ray;
	double	length;

	ray = &data->ray;
	if (ray->side == 0)
	{
		data->wall.direction = data->wall.vertical;
		length = (ray->side_dist_x - ray->delta_x);
	}
	else
	{
		data->wall.direction = data->wall.horizontal;
		length = (ray->side_dist_y - ray->delta_y);
	}
	if (length == 0)
	{
		length += 0.01;
	}
	return (length);
}

int	get_ray_data(t_data *data, int x)
{
	t_ray	*ray;

	data->door->found = false;
	data->wall.door = 0;
	ray = &data->ray;
	ray->camera = 2 * x / (double)WIDTH - 1;
	ray->dir_x = data->dir_x + data->plane_x * ray->camera;
	ray->dir_y = data->dir_y + data->plane_y * ray->camera;
	if (ray->dir_x == 0)
		ray->delta_x = 1e30;
	else
		ray->delta_x = fabs(1 / ray->dir_x);
	if (ray->dir_y == 0)
		ray->delta_y = 1e30;
	else
		ray->delta_y = fabs(1 / ray->dir_y);
	set_cardinal_direction(data, &data->ray);
	find_a_wall(data, &data->ray, x);
	ray->length = count_ray_length(data);
	return (0);
}
