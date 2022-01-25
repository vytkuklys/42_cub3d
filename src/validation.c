/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 23:28:11 by vkuklys           #+#    #+#             */
/*   Updated: 2022/01/25 00:53:44 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// 2 rules of map validation:

// 1. Outer most borders need to be space or 1
// 2. Each space has to be surounded (vertically, diagonally, horizontally) by space or 1

int are_outer_borders_valid(t_data *data)
{
	int x;
	int y;

	y = 0;
	while (data->map.map[y] != NULL)
	{
		x = 0;
		while (data->map.map[y][x] != '\0' && data->map.map[y][x] != '\n')
		{
			if (y == 0 || y == data->map.columns - 1)
				if (data->map.map[y][x] != '1' && data->map.map[y][x] != ' ')
					return (1);
			if (x == 0 || x == data->map.rows - 2)
				if (data->map.map[y][x] != '1' && data->map.map[y][x] != ' ')
					return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int are_spaces_valid(t_data *data, int y_val, int x_val)
{
	int y[3];
	int x[3];
	int i;
	int j;

	y[0] = y_val - 1;
	y[1] = y_val;
	y[2] = y_val + 1;
	x[0] = x_val - 1;
	x[1] = x_val;
	x[2] = x_val + 1;
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if (y[i] > 0 && x[j] > 0 && y[i] < data->map.columns - 1 && x[j] < data->map.rows - 2)
			{
				if (data->map.map[y[i]][x[j]] != '1' && data->map.map[y[i]][x[j]] != ' ')
				{
					return (1);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

int are_inner_borders_valid(t_data *data)
{
	int x;
	int y;
	int flag;

	y = 0;
	flag = 0;
	while (data->map.map[y] != NULL)
	{
		x = 0;
		while (data->map.map[y][x] != '\0' && data->map.map[y][x] != '\n')
		{
			if (data->map.map[y][x] == ' ' && are_spaces_valid(data, y, x))
				return (1);
			else if (!strchr(" 01SNWE", data->map.map[y][x]))
				return (1);
			else if (strchr("SNWE", data->map.map[y][x]) && flag++ > 0)
				return (1);
			x++;
		}
		y++;
	}
	if (!flag)
		return (1);
	return (0);
}

int is_map_valid(t_data *data)
{
	if (are_outer_borders_valid(data) || are_inner_borders_valid(data))
	{
		fprintf(stderr, "Not valid,");
		return (1);
	}
	fprintf(stderr, "Valid,\n");
	return (0);
}