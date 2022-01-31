/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:41:42 by vkuklys           #+#    #+#             */
/*   Updated: 2022/01/31 13:57:15 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	get_perimeter(int fd, t_data *data)//think about void
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
	close(fd);
	return (0);
}

int	fill_row(char **map, char *line, int rows)//think about void
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
	return (0);
}

int	fill_perimeter(int fd, t_data *data)
{
	int	i;

	data->map.map = (char **)malloc((data->map.columns + 1) * sizeof(char *));
	if (!data->map.map)
	{
		free(data->tmp_str);
		return (1);
	}
	i = 0;
	while (i < data->map.columns)
	{
		if (i > 0)
			data->tmp_str = get_next_line(fd);
		data->map.map[i] = (char *)malloc(data->map.rows);
		if (data->map.map[i] == NULL)
		{
			free(data->tmp_str);
			return (1);
		}
		fill_row(&data->map.map[i], data->tmp_str, data->map.rows);
		free(data->tmp_str);
		i++;
	}
	data->map.map[i] = NULL;
	return (0);
}

int	skip_to_map(t_data *data, char *filename)//think about unsigned int
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
			return (-1);
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
		fprintf(stderr, "Invalid elements");
		return (EXIT_FAILURE);
	}
	if (get_perimeter(fd, data))
	{
		fprintf(stderr, "Map problems");
		close(fd);
		return (EXIT_FAILURE);
	}
	close(fd);
	fd = skip_to_map(data, filename);
	if (fd == -1)
		return (EXIT_FAILURE);
	if (fill_perimeter(fd, data))
	{
		close(fd);
		return (EXIT_FAILURE);
	}
	close(fd);
	return (EXIT_SUCCESS);
}
