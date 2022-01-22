/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 17:46:42 by vkuklys           #+#    #+#             */
/*   Updated: 2022/01/22 20:56:07 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int draw_east_wall(t_img *img, int x, int start, int end)
{
    start = start > 0 ? start : 0;

    int i = 0;
    int j = x % 64;
    for (int k = start; i < 64 && k < end && k < 512; k++)
    {
        my_mlx_pixel_put(img, x, k, img->textures.east_wall[j][i]);
        i++;
    }
    for (int k = start + 64; k < end && k < 512; k++)
    {
        my_mlx_pixel_put(img, x, k, 0x00FFF1);
    }
    return (0);
}

int draw_west_wall(t_img *img, int x, int start, int end)
{
    start = start > 0 ? start : 0;

    int i = 0;
    int j = x % 64;
    for (int k = start; i < 64 && k < end && k < 512; k++)
    {
        my_mlx_pixel_put(img, x, k, img->textures.west_wall[j][i]);
        i++;
    }
    for (int k = start + 64; k < end && k < 512; k++)
    {
        my_mlx_pixel_put(img, x, k, 0x00FFF1);
    }
    return (0);
}