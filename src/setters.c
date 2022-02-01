/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 01:49:41 by vkuklys           #+#    #+#             */
/*   Updated: 2022/02/01 03:24:24 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_player_to_north(t_data *data)
{
	data->plane_x = 0;
	data->plane_y = 0.71;
	data->dir_x = -1;
	data->dir_y = 0;
}

void	set_player_to_south(t_data *data)
{
	data->plane_x = 0;
	data->plane_y = -0.71;
	data->dir_x = 1;
	data->dir_y = 0;
}

void	set_player_to_east(t_data *data)
{
	data->plane_x = 0.71;
	data->plane_y = 0;
	data->dir_x = 0;
	data->dir_y = 1;
}

void	set_player_to_west(t_data *data)
{
	data->plane_x = -0.71;
	data->plane_y = 0;
	data->dir_x = 0;
	data->dir_y = -1;
}

int	set_player_direction(t_data *data, char direction)
{
	if (direction == 'S')
		set_player_to_south(data);
	else if (direction == 'N')
		set_player_to_north(data);
	else if (direction == 'E')
		set_player_to_east(data);
	else if (direction == 'W')
		set_player_to_west(data);
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
