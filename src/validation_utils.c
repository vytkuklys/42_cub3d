/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 04:06:46 by vkuklys           #+#    #+#             */
/*   Updated: 2022/02/01 04:58:54 by vkuklys          ###   ########.fr       */
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
