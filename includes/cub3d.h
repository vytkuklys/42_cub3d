/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 16:55:52 by vkuklys           #+#    #+#             */
/*   Updated: 2022/01/23 19:46:19 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdbool.h>
#include "../mlx/mlx.h"
#include "../libft/libft.h"

#define WALL_DISTANCE 0.3
#define SCREENWIDTH 640
#define SCREENHEIGHT 480
#define MAPWIDTH 24
#define MAPHEIGHT 24
#define MOVE_LEFT 0
#define MOVE_RIGHT 2
#define MOVE_DOWN 1
#define MOVE_UP 13
#define ROTATE_LEFT 123
#define ROTATE_RIGHT 124
#define ESCAPE 53

#define FRAMES 0.012
#define SPEED FRAMES * 3.5
#define ROTATION FRAMES * 2.75

#define NORTH 0
#define EAST 1
#define WEST 2
#define SOUTH 3

#define WIDTH 1024
#define HEIGHT 512

typedef struct s_textures
{
	int east_wall[64][64];
	int west_wall[64][64];
	int north_wall[64][64];
	int south_wall[64][64];
	void *east_ptr;
	void *west_ptr;
	void *north_ptr;
	void *south_ptr;
	char *west_addr;
	char *east_addr;
	char *south_addr;
	char *north_addr;
} t_textures;

typedef struct s_img
{
	void *img_ptr;
	char *addr;
	int bpp;
	int sl;
	int endian;
	int width;
	int height;
	t_textures textures;
} t_img;

typedef struct s_map
{
	int columns;
	int rows;
	char **map;
} t_map;

typedef struct s_ray
{
	float camera;
	double dir_x;
	double dir_y;
	double delta_x;
	double delta_y;
	double side_dist_x;
	double side_dist_y;
	double length;
	int step_x;
	int step_y;
	int side;
} t_ray;

typedef struct s_wall
{
	int top;
	int bottom;
	int x;
	double step;
	double position;
	int vertical;
	int horizontal;
	int direction;
} t_wall;

typedef struct s_data
{
	int worldMap[64];
	float p_x;
	float p_y;
	double plane_x;
	double plane_y;
	double dir_x;
	double dir_y;
	float delta_x;
	float delta_y;
	void *mlx_ptr;
	void *mlx_win;
	int pressed_key;
	int pressed_key2;
	int width;
	int height;
	t_img img;
	t_map map;
	t_ray ray;
	t_wall wall;
} t_data;

int get_columns(char *filename, t_data *data);
int init_map(char *filename, t_data *data);
int is_map_valid(t_data *data);
int is_x_forwards_wall(t_data *data);
int is_y_forwards_wall(t_data *data);
int is_x_backwards_wall(t_data *data);
int is_y_backwards_wall(t_data *data);
int is_x_right_wall(t_data *data);
int is_y_right_wall(t_data *data);
int is_x_left_wall(t_data *data);
int is_y_left_wall(t_data *data);
void my_mlx_pixel_put(t_img *img, int x, int y, int color);
int draw_minimap(t_data *data);
int init_textures(t_data *data);
int draw_west_wall(t_img *img, int x, int start, int end);
int test2(int key, t_data *data);
int test(int key, t_data *data);
int update_game(int key, t_data *data);
int createRGB(int r, int g, int b);
int draw_ground(t_data *data, int x, int from);
int draw_sky(t_data *data, int x, int up_to);
int get_ray_data(t_data *data, int x);
void draw_walls(t_wall *wall, t_img *img, int x);
void get_wall_data(t_data *data);
void check_events(t_data *data);

#endif
