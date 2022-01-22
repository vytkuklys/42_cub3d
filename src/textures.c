/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 00:04:20 by vkuklys           #+#    #+#             */
/*   Updated: 2022/01/22 21:39:14 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int my_mlx_pixel_get(t_img *img, int x, int y, int direction)
{
    int color;
    char *dst;

    if (direction == EAST)
        dst = img->textures.east_addr + (y * img->sl + x * (img->bpp / 8));
    else if (direction == WEST)
        dst = img->textures.west_addr + (y * img->sl + x * (img->bpp / 8));
    else if (direction == NORTH)
        dst = img->textures.north_addr + (y * img->sl + x * (img->bpp / 8));
    else if (direction == SOUTH)
        dst = img->textures.south_addr + (y * img->sl + x * (img->bpp / 8));
    else
        dst = NULL;
    color = *(unsigned int *)dst;
    return (color);
}

int get_east_pixels(t_img *img)
{
    int i;
    int j;

    i = 0;
    while (i < 64)
    {
        j = 0;
        while (j < 64)
        {
            img->textures.east_wall[i][j] = my_mlx_pixel_get(img, i, j, EAST);
            j++;
        }
        i++;
    }
    return (0);
}

int get_west_pixels(t_img *img)
{
    int i;
    int j;

    i = 0;
    while (i < 64)
    {
        j = 0;
        while (j < 64)
        {
            img->textures.west_wall[i][j] = my_mlx_pixel_get(img, i, j, WEST);
            j++;
        }
        i++;
    }
    return (0);
}

int get_north_pixels(t_img *img)
{
    int i;
    int j;

    i = 0;
    while (i < 64)
    {
        j = 0;
        while (j < 64)
        {
            img->textures.north_wall[i][j] = my_mlx_pixel_get(img, i, j, NORTH);
            j++;
        }
        i++;
    }
    return (0);
}

int get_south_pixels(t_img *img)
{
    int i;
    int j;

    i = 0;
    while (i < 64)
    {
        j = 0;
        while (j < 64)
        {
            img->textures.south_wall[i][j] = my_mlx_pixel_get(img, i, j, SOUTH);
            j++;
        }
        i++;
    }
    return (0);
}

int init_textures(t_data *data)
{
    int width;
    int height;
    t_img *img;

    img = &data->img;

    img->textures.east_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "images/2.xpm", &width, &height);
    img->textures.east_addr = mlx_get_data_addr(img->textures.east_ptr, &img->bpp, &img->sl, &img->endian);
    get_east_pixels(img);

    img->textures.west_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "images/1.xpm", &width, &height);
    img->textures.west_addr = mlx_get_data_addr(img->textures.west_ptr, &img->bpp, &img->sl, &img->endian);
    get_west_pixels(img);

    img->textures.south_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "images/3.xpm", &width, &height);
    img->textures.south_addr = mlx_get_data_addr(img->textures.south_ptr, &img->bpp, &img->sl, &img->endian);
    get_south_pixels(img);

    img->textures.north_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "images/4.xpm", &width, &height);
    img->textures.north_addr = mlx_get_data_addr(img->textures.north_ptr, &img->bpp, &img->sl, &img->endian);
    get_north_pixels(img);
    return (0);
}
