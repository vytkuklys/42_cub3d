/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 01:50:07 by vkuklys           #+#    #+#             */
/*   Updated: 2022/01/31 19:54:30 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	get_door_data(t_data *data, t_door *door)
{
	t_wall	*wall;
	int		line_height;
	double	hit_point;

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
	if ((door->side == 0 && door->dir_x > 0)
		|| (door->side == 1 && door->dir_y < 0))
		wall->x = 64 - wall->x - 1;
	wall->step = (1.0 * 64 / line_height) * 0.75;
	wall->position = (wall->top - 0 - HEIGHT / 2
			+ line_height / 1.5) * wall->step;
}

void	prepare_door_drawing(t_data *data, int x)
{
	t_door	*door;
	t_door	*last;
	t_door	*prev;
	int		size;

	door = &data->door;
	size = ft_door_lstsize(door);
	while (size-- > 1)
	{
		last = ft_door_lstlast(&data->door);
		get_door_data(data, last);
		draw_doors(&data->wall, &data->img, x);
		prev = last->prev;
		free(last);
		prev->next = NULL;
		last = NULL;
	}
	get_door_data(data, &data->door);
	draw_doors(&data->wall, &data->img, x);
}

void	set_door_data(t_data *data, int x)
{
	t_door	*tmp;

	if (data->door.found) // in case one rays goes through more than one door
	{
		tmp = (t_door *)malloc(sizeof(t_door));
		tmp->found = true;
		tmp->length = count_ray_length(data);
		tmp->x = x;
		tmp->side = data->ray.side;
		tmp->dir_x = data->ray.dir_x;
		tmp->dir_y = data->ray.dir_y;
		tmp->next = NULL;
		tmp->prev = ft_door_lstlast(&data->door);
		ft_door_lstlast(&data->door)->next = tmp;
		return;
	}
	data->door.found = true;
	data->door.length = count_ray_length(data);
	data->door.x = x;
	data->door.side = data->ray.side;
	data->door.dir_x = data->ray.dir_x;
	data->door.dir_y = data->ray.dir_y;
}

void	init_door(t_door *door)
{
	door->found = false;
	door->open_s_n[0] = -1;
	door->open_s_n[1] = -1;
	door->open_e_w[0] = -1;
	door->open_e_w[1] = -1;
	door->length = 0;
	door->x = 0;
	door->side = 0;
	door->dir_x = 0;
	door->dir_y = 0;
	door->next = NULL;
	door->prev = NULL;
}

int	close_south_north_door(t_data *data)
{
	int x;

	x = data->door.open_s_n[0];
	if (x == -1)
		return (EXIT_SUCCESS);
	else
	{
		if (data->p_x <= (double)x - 0.3 || data->p_x >= (double)x + 1.3)
		{
			data->map.map[data->door.open_s_n[0]][data->door.open_s_n[1]] = '2';
			data->map.map[data->door.open_s_n[0]][data->door.open_s_n[1] - 1] = '1';
			data->map.map[data->door.open_s_n[0]][data->door.open_s_n[1] + 1] = '1';
			data->wall.type = '\0';
			data->door.open_s_n[0] = -1;
			data->door.open_s_n[1] = -1;
		}
	}
	return (EXIT_FAILURE);
}

int	close_east_west_door(t_data *data)
{
	int	y;

	y = data->door.open_e_w[1];
	if (y == -1)
		return (EXIT_SUCCESS);
	else
	{
		if (data->p_y <= (double)y - 0.3 || data->p_y >= (double)y + 1.3)
		{
			data->map.map[data->door.open_e_w[0]][data->door.open_e_w[1]] = '2';
			data->map.map[data->door.open_e_w[0] - 1][data->door.open_e_w[1]] = '1';
			data->map.map[data->door.open_e_w[0] + 1][data->door.open_e_w[1]] = '1';
			data->wall.type = '\0';
			data->door.open_e_w[0] = -1;
			data->door.open_e_w[1] = -1;
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
		data->door.open_s_n[0] = y;
		data->door.open_s_n[1] = x;
		data->map.map[y][x - 1] = '3';
		data->map.map[y][x + 1] = '3';
		data->map.map[y][x] = '0';
		data->wall.type = SOUTH;
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
		data->door.open_e_w[0] = x;
		data->door.open_e_w[1] = y;
		data->map.map[x - 1][y] = '3';
		data->map.map[x + 1][y] = '3';
		data->wall.type = EAST;
		data->map.map[x][y] = '0';
		return (EXIT_SUCCESS);
	}
	return (1);
}
