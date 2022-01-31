/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 00:04:20 by vkuklys           #+#    #+#             */
/*   Updated: 2022/01/31 18:41:11 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	my_mlx_pixel_get(t_img *img, int x, int y, int direction)
{
	int		color;
	char	*dst;

	if (direction == EAST)
		dst = img->textures.east_addr + (y * img->sl + x * (img->bpp / 8));
	else if (direction == WEST)
		dst = img->textures.west_addr + (y * img->sl + x * (img->bpp / 8));
	else if (direction == NORTH)
		dst = img->textures.north_addr + (y * img->sl + x * (img->bpp / 8));
	else if (direction == SOUTH)
		dst = img->textures.south_addr + (y * img->sl + x * (img->bpp / 8));
	else
		dst = img->textures.gates_addr + (y * img->sl + x * (img->bpp / 8));
	color = *(unsigned int *)dst;
	return (color);
}

int	get_east_pixels(t_img *img)
{
	int	i;
	int	j;

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

int	get_west_pixels(t_img *img)
{
	int	i;
	int	j;

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

int	get_north_pixels(t_img *img)
{
	int	i;
	int	j;

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

int	get_south_pixels(t_img *img)
{
	int	i;
	int	j;

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

int	get_door_pixels(t_img *img)
{
	int	i;
	int	j;

	i = 0;
	if (img == NULL)
		return (1);
	while (i < 64)
	{
		j = 0;
		while (j < 64)
		{
			img->textures.gates[i][j] = my_mlx_pixel_get(img, i, j, DOOR);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int init_textures(t_data *data)//add protection
{
	int width;
	int height;
	t_img *img;

	img = &data->img;
//this will reaplace all the stuff below
	// int	i;

	// i = 0;
	// img->textures.tex_addr = ft_calloc(7 + 1, sizeof(char *));
	// while (i < 6)
	// {
	// 	img->textures.tex_ptr = mlx_xpm_file_to_image(data->mlx_ptr, img->tex_paths[i], &width, &height);
	// 	if (img->textures.tex_ptr == NULL)
	// 		return (error_texture(img->tex_paths[i]));
	// 	img->textures.tex_addr[i] = mlx_get_data_addr(img->textures.tex_ptr, &img->bpp, &img->sl, &img->endian);
	// 	free(img->textures.tex_ptr);
	// 	img->textures.tex_ptr = NULL;
	// 	i++;
	// }
//
	// img->textures.tex_ptr = NULL;
	img->textures.east_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "images/2.xpm", &width, &height); //img path has to be replaced
	img->textures.east_addr = mlx_get_data_addr(img->textures.east_ptr, &img->bpp, &img->sl, &img->endian);
	// img->textures.tex_addr[east] = img->textures.east_addr;
	get_east_pixels(img);

	img->textures.west_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "images/1.xpm", &width, &height); //img path has to be replaced
	img->textures.west_addr = mlx_get_data_addr(img->textures.west_ptr, &img->bpp, &img->sl, &img->endian);
	// img->textures.tex_addr[west] = img->textures.west_addr;
	get_west_pixels(img);

	img->textures.south_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "images/3.xpm", &width, &height); //img path has to be replaced
	img->textures.south_addr = mlx_get_data_addr(img->textures.south_ptr, &img->bpp, &img->sl, &img->endian);
	// img->textures.tex_addr[south] = img->textures.south_addr;
	get_south_pixels(img);

	img->textures.north_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "images/4.xpm", &width, &height); //img path has to be replaced
	img->textures.north_addr = mlx_get_data_addr(img->textures.north_ptr, &img->bpp, &img->sl, &img->endian);
	// img->textures.tex_addr[north] = img->textures.north_addr;
	get_north_pixels(img);

	img->textures.gates_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "images/5.xpm", &width, &height); //img path has to be replaced
	img->textures.gates_addr = mlx_get_data_addr(img->textures.gates_ptr, &img->bpp, &img->sl, &img->endian);
	// img->textures.tex_addr[door] = img->textures.gates_addr;
	get_door_pixels(img);
	// this should work, but doesn't
	// printf("%p\n", img->textures.tex_ptr);
	// img->textures.tex_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "images/left_hand.xpm", &width, &height);
	// printf("%p\n", img->textures.tex_ptr);
	// img->textures.tex_addr[left_hand] = mlx_get_data_addr(img->textures.tex_ptr, &img->bpp, &img->sl, &img->endian);
	// free(img->textures.tex_ptr);
	// img->textures.tex_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "images/right_hand.xpm", &width, &height);
	// printf("%p\n\n", img->textures.tex_ptr);
	// img->textures.tex_addr[right_hand] = mlx_get_data_addr(img->textures.tex_ptr, &img->bpp, &img->sl, &img->endian);
	// while (img->textures.tex_addr[i] != NULL)
	// 	printf("%p\n", img->textures.tex_addr[i++]);
	//
	img->textures.left_hand = mlx_xpm_file_to_image(data->mlx_ptr, "images/left_hand.xpm", &width, &height);
	img->textures.left_hand_addr = mlx_get_data_addr(img->textures.left_hand, &img->bpp, &img->sl, &img->endian);
	img->textures.right_hand = mlx_xpm_file_to_image(data->mlx_ptr, "images/right_hand.xpm", &width, &height);
	img->textures.left_hand_addr = mlx_get_data_addr(img->textures.right_hand, &img->bpp, &img->sl, &img->endian);
	return (EXIT_SUCCESS);
}
