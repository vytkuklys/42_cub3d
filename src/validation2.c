
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 22:35:40 by vkuklys           #+#    #+#             */
/*   Updated: 2022/01/23 22:51:25 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int get_number(char *el)
{
	int num;
	int minus;

	minus = 1;
	while (*el && ft_strchr(" \t\r", *el))
		el++;
	if (*el == '-')
	{
		el++;
		minus = -1;
	}
	num = 0;
	while (ft_isdigit(*el))
	{
		num = num * 10;
		num += *el - '0';
		el++;
	}
	while (*el && ft_strchr(" \t\r\n", *el))
		el++;
	if (*el != '\0')
		return (-1);
	return (num * minus);
}

int set_floor_color(t_img *img, int tmp[3])
{
	int i;

	i = -1;
	while (++i < 3)
		img->floor_rgb[i] = tmp[i];
	return (0);
}

int set_ceiling_color(t_img *img, int tmp[3])
{
	int i;

	i = -1;
	while (++i < 3)
		img->ceiling_rgb[i] = tmp[i];
	return (0);
}

int is_rgb_valid(char **split, int tmp[3])
{
	int i;

	i = -1;
	while (++i < 3)
	{
		tmp[i] = get_number(split[i]);
		if (tmp[i] < 0 || tmp[i] > 255)
			return (1);
	}
	return (0);
}

int is_color_valid(t_img *img, char *el, char flag)
{
	char **split;
	int tmp[3];

	split = ft_split(el, ',');
	if (split == NULL || ft_strlen_2d(split) != 3 || el[ft_strlen(el) - 1] == ',')
	{
		ft_free_2d_array(&split, ft_strlen_2d(split));
		return (1);
	}
	if ((flag != 'F' && flag != 'C') || (flag == 'C' && img->ceiling_rgb[0] != -1)
		|| (flag == 'F' && img->floor_rgb[0] != -1) || is_rgb_valid(split, tmp))
		{
		ft_free_2d_array(&split, ft_strlen_2d(split));
		return (1);
		}
	if (flag == 'F')
		set_floor_color(img, tmp);
	else
		set_ceiling_color(img, tmp);
	ft_free_2d_array(&split, ft_strlen_2d(split));
	return (0);
}

int set_path(t_img *img, char *path, char flag)
{
	if (flag == 'W' && !img->west_path)
	{
		img->west_path = ft_strdup(path);
		return (0);
	}
	else if (flag == 'E' && !img->east_path)
	{
		img->east_path = ft_strdup(path);
		return (0);
	}
	else if (flag == 'S' && !img->south_path)
	{
		img->south_path = ft_strdup(path);
		return (0);
	}
	else if (flag == 'N' && !img->north_path)
	{
		img->north_path = ft_strdup(path);
		return (0);
	}
	return (1);
}

int is_path_valid(t_img *img, char *el, char flag)
{
	char *path;
	int fd;

	while (el && *el && ft_strchr(" \t\r", *el))
		el++;
	path = ft_substr(el, 0, ft_strlen(el) - 1);
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		free(path);
		return (1);
	}
	close(fd);
	if (set_path(img, path, flag))
		return (1);
	free(path);
	path = NULL;
	return (0);
}

int is_element_valid(t_img *img, char *el)
{
	char tmp[3];

	while (el && *el && ft_strchr(" \t\r", *el))
		el++;
	if (!el || *el == '\0' || ft_strlen(el) < 2)
		return (1);
	tmp[0] = *el++;
	tmp[1] = *el++;
	tmp[2] = '\0';

	if ((*el == ' ') && ft_strnstr("NOSOWEEA", tmp, 9) && !is_path_valid(img, el, tmp[0]))
	    return (0);
	if (ft_strnstr("F C ", tmp, 5) && !is_color_valid(img, el, tmp[0]))
		return (0);
	return (1);
}

int are_elements_valid(t_img *img, char *filename)
{
	int fd;
	char *line;
	int count;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = NULL;
	count = 0;
	while (count < TOTAL_ELEMENTS)
	{
		line = get_next_line(fd);
		if (line && *line != '\n' && !is_element_valid(img, line))
			count++;
		else if (!line || *line != '\n')
		{
			free(line);
			close(fd);
			return (-1);
		}
		free(line);
	}
	return (fd);
}
