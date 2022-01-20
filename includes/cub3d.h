/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:39:39 by vkuklys           #+#    #+#             */
/*   Updated: 2022/01/19 19:34:16 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 16:55:52 by vkuklys           #+#    #+#             */
/*   Updated: 2021/09/20 19:00:23 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D
# define CUB3D
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "../mlx/mlx.h"
#include "../libft/libft.h"

#define screenWidth 640
#define screenHeight 480
#define mapWidth 24
#define mapHeight 24
#define MOVE_LEFT 0
#define MOVE_RIGHT 2
#define MOVE_DOWN 1
#define MOVE_UP 13
#define ROTATE_LEFT 123
#define ROTATE_RIGHT 124
#define ESCAPE 53
#define false 0
#define true 0

typedef struct s_img
{
  void *img_ptr;
  char *addr;
  int bpp;
  int sl;
  int endian;
  int width;
  int height;
} t_img;

typedef struct s_map
{
    char **map;
    int columns;
    int rows;    
}   t_map;

typedef struct s_data
{
  int worldMap[64];

  // // players position
  float p_x;
  float p_y;
  double plane_x;
  double plane_y;
  double dir_x;
  double dir_y;
  float delta_x;
  float delta_y;
  float angle;
  void *mlx_ptr;
  void *mlx_win;
  t_img img;
  t_map map;
} t_data;

int get_columns(char *filename, t_data *data);
int init_map(char *filename, t_data *data);
int	is_map_valid(t_data *data);

#endif
