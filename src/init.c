/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:41:42 by vkuklys           #+#    #+#             */
/*   Updated: 2022/02/01 04:14:21 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	init_img(t_img *img)
{
	int	i;

	i = -1;
	while (++i < TOTAL_PATHS)
		img->tex_paths[i] = NULL;
	img->tex_paths[door] = ft_strdup("images/5.xpm");
	img->tex_paths[left_hand] = ft_strdup("images/left_hand.xpm");
	img->tex_paths[right_hand] = ft_strdup("images/right_hand.xpm");
	if (img->tex_paths[door] == NULL || img->tex_paths[left_hand] == NULL
		|| img->tex_paths[right_hand] == NULL)
	{
		return (EXIT_FAILURE);
	}
	img->ceiling_rgb[0] = -1;
	img->floor_rgb[0] = -1;
	return (EXIT_SUCCESS);
}

void	init_controls(t_controls *controls)
{
	controls->up = -1;
	controls->left = -1;
	controls->down = -1;
	controls->right = -1;
	controls->escape = -1;
	controls->rotate_left = -1;
	controls->rotate_right = -1;
}

void	init_map_data(t_map *map)
{
	map->columns = -1;
	map->rows = -1;
	map->map = NULL;
}

void	init_door(t_door *door)
{
	door->found = false;
	door->open_s_n[0] = -1;
	door->open_s_n[1] = -1;
	door->open_e_w[0] = -1;
	door->open_e_w[1] = -1;
	door->length = 0;
	door->x = 0;
	door->side = 0;
	door->dir_x = 0;
	door->dir_y = 0;
	door->next = NULL;
	door->prev = NULL;
}

int	init_data(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (EXIT_FAILURE);
	data->mlx_win = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "Cub3d");
	if (data->mlx_win == NULL)
		return (EXIT_FAILURE);
	data->p_x = 4;
	data->p_y = 7;
	data->plane_x = 0;
	data->plane_y = -0.71;
	data->dir_x = 1;
	data->dir_y = 0;
	data->tmp_str = NULL;
	data->map.map = NULL;
	data->wall.type = '\0';
	if (init_img(&data->img) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	init_controls(&data->controls);
	init_door(&data->door);
	init_map_data(&data->map);
	return (EXIT_SUCCESS);
}
