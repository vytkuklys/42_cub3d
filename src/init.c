/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:41:42 by vkuklys           #+#    #+#             */
/*   Updated: 2022/01/22 00:04:15 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int get_perimeter(char *filename, t_data *data)
{
    char *line;
    int fd;
    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (1);
    line = get_next_line(fd);
    data->map.columns = 0;
    data->map.rows = 0;
    while (line)
    {
        if (line && (int)ft_strlen(line) > data->map.rows)
        {
            data->map.rows = ft_strlen(line);
            if (line[data->map.rows - 1] != '\n')
                data->map.rows++;
        }
        free(line);
        line = get_next_line(fd);
        data->map.columns++;
    }
    close(fd);
    return (0);
}

int	fill_row(char **map, char *line, int rows)
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
    while(j < rows - 2)
    {
        tmp[j] = ' ';
        j++;
    }
	tmp[j] = '\0';
    return (0);
}

int fill_perimeter(char *filename, t_data *data)
{
    char *line;
    int fd;
    int i;
    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (1);
    data->map.map = (char **)malloc((data->map.columns + 1) * sizeof(char *));
    line = NULL;
    i = 0;
    while (i < data->map.columns)
    {
        line = get_next_line(fd);
        data->map.map[i] = (char *)malloc(data->map.rows);
        if (data->map.map[i] == NULL)
            exit(1);
        fill_row(&data->map.map[i], line, data->map.rows);
        free(line);
        i++;
    }
    data->map.map[i] = NULL;

    return (0);
}

int init_map(char *filename, t_data *data)
{
    get_perimeter(filename, data);
    fill_perimeter(filename, data);
    return (0);
}
