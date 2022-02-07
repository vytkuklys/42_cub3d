/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 16:55:52 by vkuklys           #+#    #+#             */
/*   Updated: 2022/02/07 14:59:39 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <math.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdbool.h>
# include "../mlx/mlx.h"
# include "../libft/include/libft.h"

// wall/corner min. distance controll
# define CORNER_DISTANCE 0.25
# define WALL_DISTANCE 0.3

// movespeed management
# define FRAMES 0.012
# define SPEED 0.039
# define ROTATION 0.033

// windowsize
// if this is changed, the hands need to be redone or removed by
// commenting out line 113 in draw.c
# define WIDTH 1024
# define HEIGHT 512

// minimap controlls
# define MINIMAP_MAX 1533
# define PARTIAL_MINIMAP 1

// texture elements
# define TOTAL_ELEMENTS 6
# define TOTAL_PATHS 8

// keycodes
# define MOVE_LEFT 0
# define MOVE_RIGHT 2
# define MOVE_DOWN 1
# define MOVE_UP 13
# define ROTATE_LEFT 123
# define ROTATE_RIGHT 124
# define ESCAPE 53

typedef struct s_textures
{
	int		east_wall[64][64];
	int		west_wall[64][64];
	int		north_wall[64][64];
	int		south_wall[64][64];
	int		gates[64][64];
	void	*tex_ptr[6];
	char	*tex_addr;
	void	*right_hand;
	void	*left_hand;
}				t_textures;

typedef enum e_tex
{
	north = 0,
	east = 1,
	west = 2,
	south = 3,
	door = 4,
	left_hand = 5,
	right_hand = 6,
}			t_tex;
typedef struct s_img
{
	void		*img_ptr;
	char		*addr;
	int			bpp;
	int			sl;
	int			endian;
	int			width;
	int			height;
	char		*tex_paths[TOTAL_PATHS];
	int			floor_rgb[3];
	int			ceiling_rgb[3];
	t_textures	textures;
}				t_img;

typedef struct s_map
{
	int		columns;
	int		rows;
	char	**map;
}				t_map;

typedef struct s_ray
{
	float	camera;
	double	dir_x;
	double	dir_y;
	double	delta_x;
	double	delta_y;
	double	side_dist_x;
	double	side_dist_y;
	double	length;
	int		step_x;
	int		step_y;
	int		side;
}				t_ray;

typedef struct s_wall
{
	int		top;
	int		bottom;
	int		x;
	double	step;
	double	position;
	int		vertical;
	int		horizontal;
	int		direction;
	int		door;
	char	type;
}				t_wall;

typedef struct s_controls
{
	int	up;
	int	down;
	int	left;
	int	right;
	int	rotate_left;
	int	rotate_right;
	int	escape;
}				t_controls;

typedef struct s_door
{
	bool			found;
	int				open_s_n[2];
	int				open_e_w[2];
	double			dir_x;
	double			dir_y;
	double			length;
	int				side;
	int				x;
	struct s_door	*next;
	struct s_door	*prev;
}				t_door;

// main struct that stores all data
typedef struct s_data
{
	float		p_x;
	float		p_y;
	double		plane_x;
	double		plane_y;
	double		dir_x;
	double		dir_y;
	float		delta_x;
	float		delta_y;
	void		*mlx_ptr;
	void		*mlx_win;
	char		*tmp_str;
	t_img		img;
	t_map		map;
	t_ray		ray;
	t_wall		wall;
	t_door		*door;
	t_controls	controls;
}				t_data;

// initialisation
int		init_map(char *filename, t_data *data);
int		init_textures(t_data *data);
int		init_data(t_data *data);
void	init_door(t_door *door);
void	init_mlx_img(t_data *data);

// validation
int		is_map_valid(t_data *data);
int		is_color_valid(t_img *img, char *el, char flag);
int		are_doors_valid(t_data *data, int y, int x);
int		are_elements_valid(t_img *img, char *filename);
int		is_null(char *str);

// getter, setter
int		get_ray_data(t_data *data, int x);
void	get_wall_data(t_data *data);
int		get_minimap_color(t_data *data, int x, int y);
int		get_color(char c);
void	get_door_data(t_data *data, t_door *door);
int		get_pixel(t_wall *wall, t_img *img, int y);
void	get_east_pixels(t_img *img);
void	get_west_pixels(t_img *img);
void	get_south_pixels(t_img *img);
void	get_north_pixels(t_img *img);
void	get_door_pixels(t_img *img);
void	set_door_data(t_data *data, int x);
void	set_coordinates(int *x, int *y, int x_val, int y_val);

// open and close doors
int		open_south_north_door(t_data *data);
int		close_south_north_door(t_data *data);
int		close_east_west_door(t_data *data);
int		open_east_west_door(t_data *data);

// draw the image
int		draw_game(t_data *data);
int		my_mlx_pixel_get(t_img *img, int x, int y);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		create_rgb(int r, int g, int b);
double	count_ray_length(t_data *data);
void	prepare_door_drawing(t_data *data, int x);
void	draw_doors(t_wall *wall, t_img *img, int x);
int		is_x_forwards_wall(t_data *data);
int		is_y_forwards_wall(t_data *data);
int		is_x_backwards_wall(t_data *data);
int		is_y_backwards_wall(t_data *data);
int		is_x_right_wall(t_data *data);
int		is_y_right_wall(t_data *data);
int		is_x_left_wall(t_data *data);
int		is_y_left_wall(t_data *data);
int		draw_minimap(t_data *data);
void	animate_hands(t_data *data);

// input
void	check_events(t_data *data);
int		key_press(int key, t_data *data);
int		key_release(int key, t_data *data);
void	update_game(int key, t_data *data);
int		mouse_hook(int x, int y, t_data *data);
int		set_player_direction(t_data *data, char direction);

// free stuff and clean exit
int		ft_strlen_2d(char **s);
t_door	*ft_door_lstlast(t_door *lst);
int		ft_door_lstsize(t_door *lst);
int		free_all(t_data *data, int flag);
char	*ft_free_2d_array(char ***arr, unsigned int allocated);
int		exit_maze(t_data *data, int exit_success);

#endif
