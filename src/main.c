/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:40:39 by vkuklys           #+#    #+#             */
/*   Updated: 2022/02/01 03:12:08 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2 && write(2, "Wrong number of arguments!\n", 28))
		return (EXIT_FAILURE);
	if (init_data(&data) == EXIT_FAILURE && !free_all(&data, 1))
		return (EXIT_FAILURE);
	if (init_map(argv[1], &data) == EXIT_FAILURE && !free_all(&data, 1))
		return (EXIT_FAILURE);
	if (is_map_valid(&data) == EXIT_FAILURE && !free_all(&data, 1))
		return (EXIT_FAILURE);
	mlx_loop_hook(data.mlx_ptr, draw_game, &data);
	mlx_hook(data.mlx_win, 6, 1L << 0, mouse_hook, &data);
	mlx_hook(data.mlx_win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.mlx_win, 3, 1L << 0, key_release, &data);
	mlx_hook(data.mlx_win, 17, 1L << 17, exit_maze, &data);
	mlx_loop(data.mlx_ptr);
	free_all(&data, 0);
	return (EXIT_SUCCESS);
}
