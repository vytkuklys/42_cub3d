/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 23:39:17 by vkuklys           #+#    #+#             */
/*   Updated: 2022/01/30 00:48:47 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int createRGB(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

int get_minimap_color(t_data *data, int x, int y)
{
	char c;

	x = x - 10 + data->p_y;
	y = y - 10 + data->p_x;
	if (x < 0 || y < 0 || x >= data->map.rows || y >= data->map.columns)
		return 0x000000;
	c = data->map.map[y][x];
	if (c == '0')
		return 0xf0f8ff;
	else if (c == '1')
		return 0x1E90FF;
	else if (c == ' ' || c == '\0')
		return 0x000000;
	else
		return 0x00FF00;
}

int get_color(char c)
{
	int color;

	if (c == '0')
		color = 0xf0f8ff;
	else if (c == '2')
		color = 0x00FF00;
	else if (c == '1')
		color = 0x1E90FF;
	else
		color = 0;
	return (color);
}


int ft_strlen_2d(char **s)
{
	int len;

	len = 0;
	while (s && s[len] != NULL)
		len++;
	return (len);
}

char *ft_free_2d_array(char ***arr, unsigned int allocated)
{
	unsigned int i;
	unsigned int current;

	current = 1;
	if (*arr == NULL)
		return (NULL);
	i = 0;
	while (i < allocated + current)
	{
		free((*arr)[i]);
		i++;
	}
	free(*arr);
	*arr = NULL;
	return (NULL);
}
