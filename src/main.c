/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:40:39 by vkuklys           #+#    #+#             */
/*   Updated: 2022/01/18 23:28:04 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Copyright (c) 2004-2021, Lode Vandevenne

All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "../includes/cub3d.h"

int worldMap[mapWidth][mapHeight] =
    {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 3, 0, 3, 0, 3, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 2, 2, 0, 2, 2, 0, 0, 0, 0, 3, 0, 3, 0, 3, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 4, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 4, 0, 0, 0, 0, 5, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 4, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 4, 0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

int update_game(int key, t_data *data)
{
  // double data->plane_x = 0, data->plane_y = 0.66;             //the 2d raycaster version of camera plane
  // double time = 0;                              //time of current frame
  // double oldTime = 0;                           //time of previous frame
  // double frameTime = (time - oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
  double frameTime = 0.08; //frameTime is the time this frame has taken, in seconds

  // double data->dir_x = -1, data->dir_y = 0;         //initial direction vector
  double moveSpeed = frameTime * 5.0; //the constant value is in squares/second
  double rotSpeed = frameTime * 3.0;  //the constant value is in radians/second
  if (key == MOVE_UP)
  {
    if (worldMap[(int)(data->p_x + data->dir_x * moveSpeed)][(int)(data->p_y)] == false)
    {

      data->p_x += data->dir_x * moveSpeed;
    }
    if (worldMap[(int)(data->p_x)][(int)(data->p_y + data->dir_y * moveSpeed)] == false)
    {
      data->p_y += data->dir_y * moveSpeed;
    }
    // data->p_x -=1;
  }
  //move backwards if no wall behind you
  else if (key == MOVE_DOWN)
  {
    if (worldMap[(int)(data->p_x - data->dir_x * moveSpeed)][(int)(data->p_y)] == false)
      data->p_x -= data->dir_x * moveSpeed;
    if (worldMap[(int)(data->p_x)][(int)(data->p_y - data->dir_y * moveSpeed)] == false)
      data->p_y -= data->dir_y * moveSpeed;
    // data->p_x +=1;
  }
  //rotate to the right
  else if (key == MOVE_RIGHT)
  {
    //both camera direction and camera plane must be rotated
    double oldDirX = data->dir_x;
    data->dir_x = data->dir_x * cos(-rotSpeed) - data->dir_y * sin(-rotSpeed);
    data->dir_y = oldDirX * sin(-rotSpeed) + data->dir_y * cos(-rotSpeed);
    double oldPlaneX = data->plane_x;
    data->plane_x = data->plane_x * cos(-rotSpeed) - data->plane_y * sin(-rotSpeed);
    data->plane_y = oldPlaneX * sin(-rotSpeed) + data->plane_y * cos(-rotSpeed);
  }
  //rotate to the left
  else if (key == MOVE_LEFT)
  {
    // both camera direction and camera plane must be rotated
    double oldDirX = data->dir_x;
    data->dir_x = data->dir_x * cos(rotSpeed) - data->dir_y * sin(rotSpeed);
    data->dir_y = oldDirX * sin(rotSpeed) + data->dir_y * cos(rotSpeed);
    double oldPlaneX = data->plane_x;
    data->plane_x = data->plane_x * cos(rotSpeed) - data->plane_y * sin(rotSpeed);
    data->plane_y = oldPlaneX * sin(rotSpeed) + data->plane_y * cos(rotSpeed);
    // data->plane_y = 1;
  }
  else if (key == ESCAPE)
  {
    exit(0);
  }
  return (0);
}

void my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
  char *dst;

  dst = img->addr + (y * img->sl + x * (img->bpp / 8));
  *(unsigned int *)dst = color;
}

void init_data(t_data *data)
{
  data->mlx_ptr = mlx_init();
  data->mlx_win = mlx_new_window(data->mlx_ptr, 512, 512, "Cub3d");
  data->p_x = 22;
  data->p_y = 12;
  data->angle = 60;
  data->plane_x = 0;
  data->plane_y = 0.66;
  data->dir_x = -1;
  data->dir_y = 0;
}

int draw_game(t_data *data)
{
  int w = 1024;
  int h = 512;
  data->img.img_ptr = mlx_new_image(data->mlx_ptr, 1024, 512);
  data->img.addr = mlx_get_data_addr(data->img.img_ptr, &data->img.bpp, &data->img.sl, &data->img.endian);
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
    int side;    //was a NS or a EW wall hit?
    //calculate step and initial sideDist
    // int color;
    // color = 0xFF0000;

    if (rayDirX < 0)
    {
      stepX = -1;
      sideDistX = (data->p_x - mapX) * deltaDistX;
      // color = 0x00FF00;
    }
    else
    {
      stepX = 1;
      sideDistX = (mapX + 1.0 - data->p_x) * deltaDistX;
      // color = 0x0000FF;
    }
    if (rayDirY < 0)
    {
      stepY = -1;
      sideDistY = (data->p_y - mapY) * deltaDistY;
    }
    else
    {
      stepY = 1;
      sideDistY = (mapY + 1.0 - data->p_y) * deltaDistY;
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
      perpWallDist = (sideDistX - deltaDistX);
    else
      perpWallDist = (sideDistY - deltaDistY);

    //Calculate height of line to draw on screen
    int lineHeight = (int)(h / perpWallDist);

    //calculate lowest and highest pixel to fill in current stripe
    int drawStart = -lineHeight / 2 + h / 2;
    if (drawStart < 0)
      drawStart = 0;
    int drawEnd = lineHeight / 2 + h / 2;
    if (drawEnd >= h)
      drawEnd = h - 1;

    //choose wall color
    int color;
    switch (worldMap[mapX][mapY])
    {
    case 1:
      color = 0x00FF00;
      break; //red
    case 2:
      color = 0x0000FF;
      break; //green
    case 3:
      color = 0xFFFFFF;
      break; //blue
    case 4:
      color = 0xFF0000;
      break; //white
    default:
      color = 0x00FF00;
      break; //yellow
    }

    // give x and y sides different brightness

    //draw the pixels of the stripe as a vertical line
    // for(int k = 0; k < drawStart; k++)
    // {
    //   int tmp =  0xFF00FF;
    //   my_mlx_pixel_put(&data->img, x, k, tmp);
    // }
    // fprintf(stderr, "%d - %d", drawStart, drawEnd);
    // exit(1);
    for (int k = drawStart; k < drawEnd + 10; k++)
    {
      my_mlx_pixel_put(&data->img, x, k, color);
    }
    for (int k = drawEnd + 10; k < 512; k++)
    {
      int tmp = 0xFF00FF;
      my_mlx_pixel_put(&data->img, x, k, tmp);
    }
  }
  mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.img_ptr, 0, 0);
  mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
  return 0;
}

int main(void)
{
  t_data data;
  
  init_data(&data);
  init_map("maps/test.cub", &data);
  is_map_valid(&data);
  mlx_loop_hook(data.mlx_ptr, draw_game, &data);
  mlx_hook(data.mlx_win, 2, 1L << 0, update_game, &data);
  mlx_loop(data.mlx_ptr);
  // screen(screenWidth, screenHeight, 0, "Raycaster");
}
