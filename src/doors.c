/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 01:50:07 by vkuklys           #+#    #+#             */
/*   Updated: 2022/02/02 22:09:34 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_door	*ft_door_lstlast(t_door *lst)
{
	t_door	*tmp;

	tmp = lst;
	while (tmp != NULL)
	{
		if (tmp->next == NULL)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

int	ft_door_lstsize(t_door *lst)
{
	t_door	*tmp;
	int		i;

	tmp = lst;
	i = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

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

	door = data->door;
	size = ft_door_lstsize(door);
	while (size-- > 1)
	{
		last = ft_door_lstlast(data->door);
		get_door_data(data, last);
		draw_doors(&data->wall, &data->img, x);
		prev = last->prev;
		free(last);
		prev->next = NULL;
		last = NULL;
	}
	get_door_data(data, data->door);
	draw_doors(&data->wall, &data->img, x);
}

void	set_door_data(t_data *data, int x)
{
	t_door	*tmp;

	if (data->door->found)
	{
		tmp = (t_door *)ft_calloc(1, sizeof(t_door));
		if (tmp == NULL && write(2, "Memory allocation\n", 19))
			exit_maze(data, false);
		tmp->found = true;
		tmp->length = count_ray_length(data);
		tmp->x = x;
		tmp->side = data->ray.side;
		tmp->dir_x = data->ray.dir_x;
		tmp->dir_y = data->ray.dir_y;
		tmp->next = NULL;
		tmp->prev = ft_door_lstlast(data->door);
		ft_door_lstlast(data->door)->next = tmp;
		return ;
	}
	data->door->found = true;
	data->door->length = count_ray_length(data);
	data->door->x = x;
	data->door->side = data->ray.side;
	data->door->dir_x = data->ray.dir_x;
	data->door->dir_y = data->ray.dir_y;
}
