/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 04:48:34 by vkuklys           #+#    #+#             */
/*   Updated: 2022/02/01 04:56:47 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	get_east_pixels(t_img *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < 64)
	{
		j = 0;
		while (j < 64)
		{
			img->textures.east_wall[i][j] = my_mlx_pixel_get(img, i, j);
			j++;
		}
		i++;
	}
}

void	get_west_pixels(t_img *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < 64)
	{
		j = 0;
		while (j < 64)
		{
			img->textures.west_wall[i][j] = my_mlx_pixel_get(img, i, j);
			j++;
		}
		i++;
	}
}

void	get_north_pixels(t_img *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < 64)
	{
		j = 0;
		while (j < 64)
		{
			img->textures.north_wall[i][j] = my_mlx_pixel_get(img, i, j);
			j++;
		}
		i++;
	}
}

void	get_south_pixels(t_img *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < 64)
	{
		j = 0;
		while (j < 64)
		{
			img->textures.south_wall[i][j] = my_mlx_pixel_get(img, i, j);
			j++;
		}
		i++;
	}
}

void	get_door_pixels(t_img *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < 64)
	{
		j = 0;
		while (j < 64)
		{
			img->textures.gates[i][j] = my_mlx_pixel_get(img, i, j);
			j++;
		}
		i++;
	}
}
