/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 03:32:21 by vkuklys           #+#    #+#             */
/*   Updated: 2022/02/01 03:36:58 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	get_number(char *el)
{
	int	num;
	int	minus;

	minus = 1;
	while (*el && ft_strchr(" \t\r", *el))
		el++;
	if (*el == '-')
	{
		el++;
		minus = -1;
	}
	num = 0;
	while (ft_isdigit(*el))
	{
		num = num * 10;
		num += *el - '0';
		el++;
	}
	while (*el && ft_strchr(" \t\r\n", *el))
		el++;
	if (*el != '\0')
		return (-1);
	return (num * minus);
}

int	set_floor_color(t_img *img, int tmp[3])
{
	int	i;

	i = -1;
	while (++i < 3)
		img->floor_rgb[i] = tmp[i];
	return (0);
}

int	set_ceiling_color(t_img *img, int tmp[3])
{
	int	i;

	i = -1;
	while (++i < 3)
		img->ceiling_rgb[i] = tmp[i];
	return (0);
}

int	is_rgb_valid(char **split, int tmp[3])
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		tmp[i] = get_number(split[i]);
		if (tmp[i] < 0 || tmp[i] > 255)
			return (1);
	}
	return (0);
}

int	is_color_valid(t_img *img, char *el, char flag)
{
	char	**split;
	int		tmp[3];

	split = ft_split(el, ',');
	if (split == NULL || ft_strlen_2d(split) != 3 || el[ft_strlen(el) - 1]
		== ',')
	{
		ft_free_2d_array(&split, ft_strlen_2d(split));
		return (1);
	}
	if ((flag != 'F' && flag != 'C') || (flag == 'C' && img->ceiling_rgb[0]
			!= -1) || (flag == 'F' && img->floor_rgb[0] != -1)
		|| is_rgb_valid(split, tmp))
	{
		ft_free_2d_array(&split, ft_strlen_2d(split));
		return (1);
	}
	if (flag == 'F')
		set_floor_color(img, tmp);
	else
		set_ceiling_color(img, tmp);
	ft_free_2d_array(&split, ft_strlen_2d(split));
	return (0);
}
