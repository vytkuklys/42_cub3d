/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 04:06:46 by vkuklys           #+#    #+#             */
/*   Updated: 2022/02/02 22:36:29 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	createRGB(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

void	set_coordinates(int *x, int *y, int x_val, int y_val)
{
	y[0] = y_val - 1;
	y[1] = y_val;
	y[2] = y_val + 1;
	x[0] = x_val - 1;
	x[1] = x_val;
	x[2] = x_val + 1;
}

int	is_null(char *str)
{
	if (str == NULL)
		return (1);
	return (0);
}

int	ft_strlen_2d(char **s)
{
	int	len;

	len = 0;
	while (s && s[len] != NULL)
		len++;
	return (len);
}

int	are_doors_valid(t_data *data, int y, int x)
{
	if (data->map.map[y + 1][x] == '1' && data->map.map[y - 1][x] == '1')
		return (0);
	if (data->map.map[y][x + 1] == '1' && data->map.map[y][x - 1] == '1')
		return (0);
	write(2, "Invalid doors\n", 15);
	return (1);
}
