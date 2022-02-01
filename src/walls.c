/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 17:46:42 by vkuklys           #+#    #+#             */
/*   Updated: 2022/02/01 03:26:59 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	get_wall_data(t_data *data)
{
	t_wall	*wall;
	int		line_height;
	double	hit_point;

	wall = &data->wall;
	line_height = (int)(HEIGHT / data->ray.length);
	wall->top = -line_height / 1.5 + HEIGHT / 2 + 0;
	if (wall->top < 0)
		wall->top = 0;
	wall->bottom = line_height / 1.5 + HEIGHT / 2 + 0;
	if (wall->bottom >= HEIGHT)
		wall->bottom = HEIGHT - 1;
	if (data->ray.side == 0)
		hit_point = data->p_y + data->ray.length * data->ray.dir_y;
	else
		hit_point = data->p_x + data->ray.length * data->ray.dir_x;
	hit_point -= floor((hit_point));
	wall->x = (int)(hit_point * (double)(64));
	if ((data->ray.side == 0 && data->ray.dir_x > 0)
		|| (data->ray.side == 1 && data->ray.dir_y < 0))
		wall->x = 64 - wall->x - 1;
	wall->step = (1.0 * 64 / line_height) * 0.75;
	wall->position
		= (wall->top - 0 - HEIGHT / 2 + line_height / 1.5) * wall->step;
}
