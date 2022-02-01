/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 00:01:52 by vkuklys           #+#    #+#             */
/*   Updated: 2022/02/01 03:15:53 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_texture_paths(t_img *img)
{
	int	i;

	i = -1;
	while (img && ++i < TOTAL_PATHS)
	{
		if (img->tex_paths[i] != NULL)
		{
			free(img->tex_paths[i]);
			img->tex_paths[i] = NULL;
		}
	}
}

char	*ft_free_2d_array(char ***arr, unsigned int allocated)
{
	unsigned int	i;
	unsigned int	current;

	current = 1;
	if (*arr == NULL)
		return (NULL);
	i = 0;
	while (i < allocated + current)
	{
		if ((*arr)[i] != NULL)
		{
			free((*arr)[i]);
			(*arr)[i] = NULL;
		}
		i++;
	}
	free(*arr);
	*arr = NULL;
	return (NULL);
}

int	free_all(t_data *data, int flag)
{
	free_texture_paths(&data->img);
	ft_free_2d_array(&data->map.map, data->map.columns);
	if (flag)
		ft_putstr_fd("Error\n", 2);
	return (EXIT_SUCCESS);
}
