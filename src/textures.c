/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 00:04:20 by vkuklys           #+#    #+#             */
/*   Updated: 2022/02/01 12:25:11 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	call_pixels_function(t_img *img, int i)
{
	if (i == north)
		get_north_pixels(img);
	else if (i == east)
		get_east_pixels(img);
	else if (i == west)
		get_west_pixels(img);
	else if (i == south)
		get_south_pixels(img);
	else if (i == door)
		get_door_pixels(img);
}

int	init_hand_textures(t_data *data)
{
	int		width;
	int		height;
	t_img	*img;

	img = &data->img;
	img->textures.left_hand = mlx_xpm_file_to_image(data->mlx_ptr,
			img->tex_paths[left_hand], &width, &height);
	img->textures.right_hand = mlx_xpm_file_to_image(data->mlx_ptr,
			img->tex_paths[right_hand], &width, &height);
	if (!img->textures.left_hand || !img->textures.right_hand)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

// freeing tex_ptr causes infinite loop or seg fault

int	init_textures(t_data *data)
{
	int		width;
	int		height;
	t_img	*img;
	int		i;

	img = &data->img;
	i = 0;
	while (i < 5)
	{
		img->textures.tex_ptr = mlx_xpm_file_to_image(data->mlx_ptr,
				img->tex_paths[i], &width, &height);//before using the tex_paths they need to be checked if valid xpm, segfaults with box.cub map and fuller.cub
		img->textures.tex_addr = mlx_get_data_addr(img->textures.tex_ptr,
				&img->bpp, &img->sl, &img->endian);
		if (img->textures.tex_addr == NULL)
			return (EXIT_FAILURE);
		call_pixels_function(img, i);
		free(img->textures.tex_addr);
		img->textures.tex_addr = NULL;
		i++;
	}
	if (init_hand_textures(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
