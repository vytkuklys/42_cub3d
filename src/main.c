// // /* ************************************************************************** */
// // /*                                                                            */
// // /*                                                        :::      ::::::::   */
// // /*   main.c                                             :+:      :+:    :+:   */
// // /*                                                    +:+ +:+         +:+     */
// // /*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
// // /*                                                +#+#+#+#+#+   +#+           */
// // /*   Created: 2022/01/18 22:40:39 by vkuklys           #+#    #+#             */
// // /*   Updated: 2022/01/19 17:09:09 by vkuklys          ###   ########.fr       */
// // /*                                                                            */
// // /* ************************************************************************** */

// // Copyright (c) 2004-2021, Lode Vandevenne

// // All rights reserved.

// // Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

// //     * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
// //     * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

// // THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// // "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// // LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// // A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
// // CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// // EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// // PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// // PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// // LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// // NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// // SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// // */

#include "../includes/cub3d.h"
#include <time.h>

void my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char *dst;

	dst = img->addr + (y * img->sl + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void init_img(t_img *img)
{
	img->north_path = NULL;
	img->south_path = NULL;
	img->west_path = NULL;
	img->east_path = NULL;
	img->ceiling_rgb[0] = -1;
	img->floor_rgb[0] = -1;
}

void init_controls(t_controls *controls)
{
	controls->up = -1;
	controls->left = -1;
	controls->down = -1;
	controls->right = -1;
	controls->escape = -1;
	controls->rotate_left = -1;
	controls->rotate_right = -1;
}

void init_data(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "Cub3d");
	data->p_x = 4;
	data->p_y = 7;
	data->plane_x = 0;
	data->plane_y = -0.71;
	data->dir_x = 1;
	data->dir_y = 0;
	data->tmp_str = NULL;
	data->map.map = NULL;
	init_textures(data);
	init_img(&data->img);
	init_controls(&data->controls);
	init_door(&data->door);
}

int draw_game(t_data *data)
{
	int x;

	data->img.img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img_ptr, &data->img.bpp, &data->img.sl, &data->img.endian);
	check_events(data);
	x = 0;
	usleep(3750);
	while (x < WIDTH)
	{
		get_ray_data(data, x);
		get_wall_data(data);
		draw_walls(&data->wall, &data->img, x);
		draw_ceiling(data, x, data->wall.top);
		draw_floor(data, x, data->wall.bottom);
		if (data->door.found)
		{
			get_door_data(data, &data->door);
			draw_doors(&data->wall, &data->img, x);
		}
		x++;
	}
	draw_minimap(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.img_ptr, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
 	return 0;
}

int main(void)
{
	t_data data;

	init_data(&data);
	if (init_map("maps/doors.cub", &data))
		return (1);
	if (is_map_valid(&data))
		return (1);
	mlx_loop_hook(data.mlx_ptr, draw_game, &data);
	mlx_hook(data.mlx_win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.mlx_win, 3, 1L << 0, key_release, &data);
	mlx_hook(data.mlx_win, 17, 1L << 17, exit_maze, &data);
	mlx_loop(data.mlx_ptr);
}
