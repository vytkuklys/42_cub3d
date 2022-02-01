/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:40:39 by vkuklys           #+#    #+#             */
/*   Updated: 2022/02/01 19:39:18 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_all_empty(t_data *data)
{
	int	i;

	i = 0;
	data->mlx_ptr = NULL;
	data->mlx_win = NULL;
	data->tmp_str = NULL;
	data->img.img_ptr = NULL;
	data->img.addr = NULL;
	while (i < TOTAL_PATHS)
		data->img.tex_paths[i++] = NULL;
	data->img.textures.tex_ptr = NULL;
	data->img.textures.tex_addr = NULL;
	data->img.textures.right_hand = NULL;
	data->img.textures.left_hand = NULL;
	data->map.map = NULL;
	data->door = (t_door *)ft_calloc(1, sizeof(t_door));
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2 && write(2, "Wrong number of arguments!\n", 28))
		return (EXIT_FAILURE);
	init_all_empty(&data);
	if (init_data(&data) == EXIT_FAILURE)
		return (free_all(&data, EXIT_FAILURE));//don't free all stuff, leads to conditional jump because of uninitialised values or add a new function at the start which sets all void * and char * to NULL
	if (init_map(argv[1], &data) == EXIT_FAILURE)
		return (free_all(&data, EXIT_FAILURE));
	if (is_map_valid(&data) == EXIT_FAILURE)
		return (free_all(&data, EXIT_FAILURE));
	mlx_loop_hook(data.mlx_ptr, draw_game, &data);
	mlx_hook(data.mlx_win, 6, 1L << 0, mouse_hook, &data);
	mlx_hook(data.mlx_win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.mlx_win, 3, 1L << 0, key_release, &data);
	mlx_hook(data.mlx_win, 17, 1L << 17, exit_maze, &data);
	mlx_loop(data.mlx_ptr);
	free_all(&data, 0);//check if needed
	return (EXIT_SUCCESS);
}
