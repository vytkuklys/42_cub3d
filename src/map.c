/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 02:57:12 by vkuklys           #+#    #+#             */
/*   Updated: 2022/02/01 03:17:06 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	get_perimeter(int fd, t_data *data)
{
	char	*line;

	line = get_next_line(fd);
	data->map.columns = 0;
	data->map.rows = 0;
	while (line)
	{
		if (*line == '\n' && data->map.rows)
		{
			free(line);
			return (1);
		}
		else if (*line != '\n' && (int)ft_strlen(line) > data->map.rows)
		{
			data->map.rows = ft_strlen(line);
			if (line[data->map.rows - 1] != '\n')
				data->map.rows++;
		}
		if (*line != '\n')
			data->map.columns++;
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

void	fill_row(char **map, char *line, int rows)
{
	char	*tmp;
	int		j;

	tmp = *map;
	j = 0;
	while (line != NULL && line[j] != '\0' && line[j] != '\n')
	{
		tmp[j] = line[j];
		j++;
	}
	while (j < rows - 1)
	{
		tmp[j] = ' ';
		j++;
	}
	tmp[j] = '\0';
}

int	fill_perimeter(int fd, t_data *data)
{
	int	i;

	data->map.map = (char **)ft_calloc((data->map.columns + 1), sizeof(char *));
	if (!data->map.map)
	{
		free(data->tmp_str);
		return (EXIT_FAILURE);
	}
	i = -1;
	while (++i < data->map.columns)
	{
		if (i > 0)
			data->tmp_str = get_next_line(fd);
		data->map.map[i] = (char *)ft_calloc(data->map.rows, sizeof(char));
		if (data->map.map[i] == NULL)
		{
			free(data->tmp_str);
			return (EXIT_FAILURE);
		}
		fill_row(&data->map.map[i], data->tmp_str, data->map.rows);
		free(data->tmp_str);
		data->tmp_str = NULL;
	}
	data->map.map[i] = NULL;
	return (EXIT_SUCCESS);
}

int	skip_to_map(t_data *data, char *filename)
{
	int	fd;
	int	count;

	fd = open(filename, O_RDONLY);
	count = 0;
	if (fd == -1)
		return (-1);
	while (count < TOTAL_ELEMENTS + 1)
	{
		free(data->tmp_str);
		data->tmp_str = get_next_line(fd);
		if (!data->tmp_str)
		{
			close(fd);
			return (-1);
		}
		if (data->tmp_str[0] != '\n')
			count++;
	}
	return (fd);
}

int	init_map(char *filename, t_data *data)
{
	int	fd;

	fd = are_elements_valid(&data->img, filename);
	if (fd == -1)
	{
		return (EXIT_FAILURE);
	}
	if (init_textures(data) || get_perimeter(fd, data))
	{
		close(fd);
		return (EXIT_FAILURE);
	}
	close(fd);
	fd = skip_to_map(data, filename);
	if (fd == -1 && write(2, "Invalid file\n", 14))
		return (EXIT_FAILURE);
	if (fill_perimeter(fd, data) && write(2, "Memory allocation\n", 19))
	{
		close(fd);
		return (EXIT_FAILURE);
	}
	close(fd);
	return (EXIT_SUCCESS);
}
