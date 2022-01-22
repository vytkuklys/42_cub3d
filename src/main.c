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

int worldMap[MAPWIDTH][MAPHEIGHT] =
	{
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 2, 2, 0, 2, 2, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 4, 0, 4, 4, 4, 4, 4, 4, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 4, 0, 4, 0, 0, 0, 0, 4, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 4, 0, 0, 0, 0, 5, 0, 4, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 4, 0, 4, 0, 0, 0, 0, 4, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 4, 0, 4, 4, 4, 4, 4, 4, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

void my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char *dst;

	dst = img->addr + (y * img->sl + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void init_data(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx_ptr, 1024, 512, "Cub3d");
	data->p_x = 22;
	data->p_y = 13;
	data->plane_x = 0;
	data->plane_y = 0.66;
	data->dir_x = -1;
	data->dir_y = 0;
	data->pressed_key = -1;
	data->pressed_key2 = -1;
	data->wall_y = -1;
	data->wall_x = -1;
	init_textures(data);
}

int createRGB(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

int draw_game(t_data *data)
{
	int w = 1024;
	int h = 512;
	int wall_type = 0;

	data->img.img_ptr = mlx_new_image(data->mlx_ptr, 1024, 512);
	data->img.addr = mlx_get_data_addr(data->img.img_ptr, &data->img.bpp, &data->img.sl, &data->img.endian);

	if (data->pressed_key > -1 && data->pressed_key2 != data->pressed_key)
	{
		update_game(data->pressed_key, data);
	}
	if (data->pressed_key2 > -1 && data->pressed_key2 != data->pressed_key)
	{
		update_game(data->pressed_key2, data);
	}
	for (int x = 0; x < w; x++)
	{
		//calculate ray position and direction
		double cameraX = 2 * x / (double)w - 1; //x-coordinate in camera space
		double rayDirX = data->dir_x + data->plane_x * cameraX;
		double rayDirY = data->dir_y + data->plane_y * cameraX;
		//which box of the map we're in
		int mapX = (int)data->p_x;
		int mapY = (int)data->p_y;

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;

		//length of ray from one x or y-side to next x or y-side
		//these are derived as:
		//deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX))
		//deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY))
		//which can be simplified to fabs(|rayDir| / rayDirX) and fabs(|rayDir| / rayDirY)
		//where |rayDir| is the length of the vector (rayDirX, rayDirY). Its length,
		//unlike (dirX, data->dir_y) is not 1, however this does not matter, only the
		//ratio between deltaDistX and deltaDistY matters, due to the way the DDA
		//stepping further below works. So the values can be computed as below.
		// Division through zero is prevented, even though technically that's not
		// needed in C++ with IEEE 754 floating point values.
		double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
		double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);

		double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side;	 //was a NS or a EW wall hit?
		//calculate step and initial sideDist
		int color;
		int x_color;
		int y_color;

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (data->p_x - mapX) * deltaDistX;
			x_color = 0x00FF00;
			data->wall_x = NORTH;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - data->p_x) * deltaDistX;
			x_color = 0x0000FF;
			data->wall_x = SOUTH;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (data->p_y - mapY) * deltaDistY;
			y_color = 0xFFFFFF;
			data->wall_y = WEST;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - data->p_y) * deltaDistY;
			y_color = 0xFF0000;
			data->wall_y = EAST;
		}
		//perform DDA
		while (hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if (worldMap[mapX][mapY] > 0)
				hit = 1;
		}
		//Calculate distance projected on camera direction. This is the shortest distance from the point where the wall is
		//hit to the camera plane. Euclidean to center camera point would give fisheye effect!
		//This can be computed as (mapX - posX + (1 - stepX) / 2) / rayDirX for side == 0, or same formula with Y
		//for size == 1, but can be simplified to the code below thanks to how sideDist and deltaDist are computed:
		//because they were left scaled to |rayDir|. sideDist is the entire length of the ray above after the multiple
		//steps, but we subtract deltaDist once because one step more into the wall was taken above.
		if (side == 0)
		{
			color = x_color;
			wall_type = data->wall_x;
			perpWallDist = (sideDistX - deltaDistX);
		}
		else
		{
			wall_type = data->wall_y;
			color = y_color;
			perpWallDist = (sideDistY - deltaDistY);
		}

		//Calculate height of line to draw on screen
		int lineHeight = (int)(h / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 1.5 + h / 2 + 0;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 1.5 + h / 2 + 0;
		if (drawEnd >= h)
			drawEnd = h - 1;


	// int texNum = worldMap[mapX][mapY] - 1; //1 subtracted from it so that texture 0 can be used!

      //calculate value of wallX
      double wallX; //where exactly the wall was hit
      if(side == 0) wallX = data->p_y + perpWallDist * rayDirY;
      else          wallX = data->p_x + perpWallDist * rayDirX;
      wallX -= floor((wallX));

      //x coordinate on the texture
      int texX = (int)(wallX * (double)(64));
      if(side == 0 && rayDirX > 0) texX = 64 - texX - 1;
      if(side == 1 && rayDirY < 0) texX = 64 - texX - 1;

      // How much to increase the texture coordinate per screen pixel
      double step = (1.0 * 64 / lineHeight) * 0.75;
      // Starting texture coordinate
      double texPos = (drawStart - 0 - h / 2 + lineHeight / 1.5) * step;
      for(int y = drawStart; y < drawEnd; y++)
      {
        // Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
        int texY = (int)texPos & (64 - 1);
        texPos += step;
		int color;
		if (wall_type == EAST)
		{
        	color = data->img.textures.east_wall[texX][texY];
		}
		else if (wall_type == WEST)
		{
        	color = data->img.textures.west_wall[texX][texY];
		}
		else if (wall_type == NORTH)
		{
        	color = data->img.textures.north_wall[texX][texY];
		}
		else
		{
        	color = data->img.textures.south_wall[texX][texY];
		}
		if (wall_type != WEST)color = (color >> 1) & 8355711;
		my_mlx_pixel_put(&data->img, x, y, color);
      }

	// 	//choose wall color
		int tmp = createRGB(105, 105, 105);
		for (int k = 0; k < drawStart; k++)
		{
			my_mlx_pixel_put(&data->img, x, k, tmp);
		}
			tmp = createRGB(195, 195, 195);
			for (int k = drawEnd; k < 512; k++)
			{
				my_mlx_pixel_put(&data->img, x, k, tmp);
			}
	}
	draw_minimap(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.img_ptr, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	return 0;
}
// int test(int key, t_data *data)
// {
// 	if (data->pressed_key == -1 && data->pressed_key2 != key)
// 		data->pressed_key = key;
// 	else if (data->pressed_key != key)
// 	{
// 		data->pressed_key2 = key;
// 	}
// 	return (1);
// }
// int test2(int key, t_data *data)
// {
// 	if (data->pressed_key == key)
// 	{
// 		data->pressed_key = -1;
// 	}
// 	if (data->pressed_key2 == key)
// 	{
// 		data->pressed_key2 = -1;
// 	}
// 	return (key);
// }
int main(void)
{
	t_data data;

	init_data(&data);
	init_map("maps/test.cub", &data);
	is_map_valid(&data);
	mlx_loop_hook(data.mlx_ptr, draw_game, &data);
	mlx_hook(data.mlx_win, 2, 1L << 0, test, &data);
	mlx_hook(data.mlx_win, 3, 1L << 0, test2, &data);
	// mlx_hook(data.mlx_win, 2, 1L << 0, update_game, &data);
	mlx_loop(data.mlx_ptr);
}
