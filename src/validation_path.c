/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 22:35:40 by vkuklys           #+#    #+#             */
/*   Updated: 2022/02/03 19:04:41 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	is_xpm_valid(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == '"')
		{
			if (ft_strncmp(&line[1], "64 64", 5))
			{
				free(line);
				line = NULL;
				return (EXIT_FAILURE);
			}
			else
			{
				close(fd);
				free(line);
				line = NULL;
				return (EXIT_SUCCESS);
			}
		}
		free(line);
		line = get_next_line(fd);
	}
	return (EXIT_FAILURE);
}

int	set_path(t_img *img, char *path, char flag)
{
	if (flag == 'W' && img->tex_paths[west] == NULL)
	{
		img->tex_paths[west] = ft_strdup(path);
		return (is_null(img->tex_paths[west]));
	}
	else if (flag == 'E' && img->tex_paths[east] == NULL)
	{
		img->tex_paths[east] = ft_strdup(path);
		return (is_null(img->tex_paths[east]));
	}
	else if (flag == 'S' && img->tex_paths[south] == NULL)
	{
		img->tex_paths[south] = ft_strdup(path);
		return (is_null(img->tex_paths[south]));
	}
	else if (flag == 'N' && img->tex_paths[north] == NULL)
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
	if (fd == -1 || ft_strncmp(&path[strlen(path) - 4], ".xpm", 4)
		|| is_xpm_valid(fd))
	{
		write(2, "Invalid path\n", 14);
		free(path);
		path = NULL;
		close(fd);
		return (EXIT_FAILURE);
	}
	if (set_path(img, path, flag) == EXIT_FAILURE)
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
	if (el == NULL || *el == '\0' || ft_strlen(el) < 2)
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
	if ((fd == -1 || ft_strlen(filename) < 4
			|| ft_strncmp(&filename[strlen(filename) - 4], ".cub", 4)))
		return (-1);
	line = NULL;
	count = 0;
	while (count < TOTAL_ELEMENTS)
	{
		line = get_next_line(fd);
		if (line && *line != '\n' && !is_element_valid(img, line))
			count++;
		else if ((!line || *line != '\n') && write(2, "Invalid elements\n", 18))
		{
			free(line);
			close(fd);
			return (-1);
		}
		free(line);
		line = NULL;
	}
	return (fd);
}
