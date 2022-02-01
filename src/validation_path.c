/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 22:35:40 by vkuklys           #+#    #+#             */
/*   Updated: 2022/02/01 03:40:33 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	set_path(t_img *img, char *path, char flag)
{
	if (flag == 'W' && !img->tex_paths[west])
	{
		img->tex_paths[west] = ft_strdup(path);
		return (is_null(img->tex_paths[west]));
	}
	else if (flag == 'E' && !img->tex_paths[east])
	{
		img->tex_paths[east] = ft_strdup(path);
		return (is_null(img->tex_paths[east]));
	}
	else if (flag == 'S' && !img->tex_paths[south])
	{
		img->tex_paths[south] = ft_strdup(path);
		return (is_null(img->tex_paths[south]));
	}
	else if (flag == 'N' && !img->tex_paths[north])
	{
		img->tex_paths[north] = ft_strdup(path);
		return (is_null(img->tex_paths[north]));
	}
	return (EXIT_FAILURE);
}

int	is_path_valid(t_img *img, char *el, char flag)
{
	char	*path;
	int		fd;

	while (el && *el && ft_strchr(" \t\r", *el))
		el++;
	path = ft_substr(el, 0, ft_strlen(el) - 1);
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		free(path);
		path = NULL;
		return (EXIT_FAILURE);
	}
	close(fd);
	if (set_path(img, path, flag))
	{
		free(path);
		path = NULL;
		return (EXIT_FAILURE);
	}
	free(path);
	path = NULL;
	return (EXIT_SUCCESS);
}

int	is_element_valid(t_img *img, char *el)
{
	char	tmp[3];

	while (el && *el && ft_strchr(" \t\r", *el))
		el++;
	if (!el || *el == '\0' || ft_strlen(el) < 2)
		return (1);
	tmp[0] = *el++;
	tmp[1] = *el++;
	tmp[2] = '\0';
	if ((*el == ' ') && ft_strnstr("NOSOWEEA", tmp, 9)
		&& !is_path_valid(img, el, tmp[0]))
		return (EXIT_SUCCESS);
	if (ft_strnstr("F C ", tmp, 5) && !is_color_valid(img, el, tmp[0]))
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	are_elements_valid(t_img *img, char *filename)
{
	int		fd;
	char	*line;
	int		count;

	fd = open(filename, O_RDONLY);
	if (fd == -1 && write(2, "Invalid file\n", 13))
		return (-1);
	line = NULL;
	count = 0;
	while (count < TOTAL_ELEMENTS)
	{
		line = get_next_line(fd);
		if (line && *line != '\n' && !is_element_valid(img, line))
			count++;
		else if ((!line || *line != '\n') && write(2, "Invalid map\n", 13))
		{
			free(line);
			line = NULL;
			close(fd);
			return (-1);
		}
		free(line);
		line = NULL;
	}
	return (fd);
}
