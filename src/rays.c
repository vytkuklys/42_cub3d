/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 00:00:33 by vkuklys           #+#    #+#             */
/*   Updated: 2022/01/28 23:21:59 by vkuklys          ###   ########.fr       */
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
void set_cardinal_direction(t_data *data, t_ray *ray)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (data->p_x - (int)data->p_x) * ray->delta_x;
		data->wall.vertical = NORTH;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = ((int)data->p_x + 1.0 - data->p_x) * ray->delta_x;
		data->wall.vertical = SOUTH;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (data->p_y - (int)data->p_y) * ray->delta_y;
		data->wall.horizontal = WEST;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = ((int)data->p_y + 1.0 - data->p_y) * ray->delta_y;
		data->wall.horizontal = EAST;
	}
} 

void find_a_wall(t_data *data, t_ray *ray)
{
	int wall;
	int x;
	int y;

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
		// fprintf(stderr, "x- %d, y- %d, (%c), ", x, y, data->map.map[x][y]);
		if (data->map.map[x][y] == '2')
		{
			data->wall.door = 1;
		}
		if (data->map.map[x][y] != '0')
			wall = true;
	}
}

double count_ray_length(t_data *data)
{
	t_ray *ray;
	double length;

	find_a_wall(data, &data->ray);
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
	if (length == 0) // segfault fix
	{
		length += 0.01;
	}
	return (length);
}

int get_ray_data(t_data *data, int x)
{
	t_ray *ray;

	data->wall.door = 0;
	ray = &data->ray;
	ray->camera = 2 * x / (double)data->width - 1;
	ray->dir_x = data->dir_x + data->plane_x * ray->camera;
	ray->dir_y = data->dir_y + data->plane_y * ray->camera;
	ray->delta_x = (ray->dir_x == 0) ? 1e30 : fabs(1 / ray->dir_x);
	ray->delta_y = (ray->dir_y == 0) ? 1e30 : fabs(1 / ray->dir_y);
	set_cardinal_direction(data, &data->ray);
	ray->length = count_ray_length(data);
	return (0);
}
