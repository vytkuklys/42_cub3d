
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

// #include "../includes/cub3d.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

// Single line validation of ceiling/floor and directions

// To do: Still need to use this in a loop where new lines would be considered


typedef struct s_img
{
	char *west_path;
	char *east_path;
	char *north_path;
	char *south_path;
	int floor_rgb[3];
	int ceiling_rgb[3];
} t_img;

size_t ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
char *ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t i;
	char *s_sub;
	unsigned int j;

	if (s == 0)
		return (0);
	j = ft_strlen(s);
	s_sub = (char *)malloc((sizeof(*s) * len) + 1);
	if (s_sub == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[i] != '\0' && start < j)
	{
		s_sub[i] = s[start + i];
		i++;
	}
	s_sub[i] = '\0';
	return (s_sub);
}

int ft_isalpha(int c)
{
	if ((c > 64 && c < 91) || (c > 96 && c < 123))
		return (1);
	else
		return (0);
}

int ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	else
		return (0);
}

int ft_isalnum(int c)
{
	if (ft_isalpha(c) == 1 || ft_isdigit(c) == 1)
		return (1);
	else
		return (0);
}

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (i < len && haystack[i] != '\0')
	{
		if (needle[0] == haystack[i])
		{
			j = 0;
			while (needle[j] != '\0' && haystack[i + j] == needle[j] && i + j < len)
			{
				j++;
			}
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (0);
}

static int num_split(char const *s, char c, int i)
{
	int split;

	split = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			split++;
		i++;
	}
	return (split);
}

static char **do_split(char **s_array, char const *s, char c, int i)
{
	int j;
	int k;
	int s_num;

	s_num = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (s[i + j] != c && s[i + j] != '\0')
			j++;
		s_array[s_num] = malloc(sizeof(char) * j + 1);
		if (s_array[s_num] == NULL)
			return (NULL);
		j = i + j;
		k = 0;
		while (i < j)
			s_array[s_num][k++] = s[i++];
		s_array[s_num][k] = '\0';
		s_num++;
		while (s[i] != '\0' && s[i] == c)
			i++;
	}
	s_array[s_num] = NULL;
	return (s_array);
}

char **ft_split(char const *s, char c)
{
	char **s_array;
	int i;

	if (s == 0)
		return (0);
	i = 0;
	while (s[i] != '\0' && s[i] == c)
		i++;
	s_array = malloc(sizeof(char *) * (num_split(s, c, i) + 2));
	if (s_array == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] == c)
		i++;
	s_array = do_split(s_array, s, c, i);
	return (s_array);
}

int ft_strlen_2d(char **s)
{
	int len;

	len = 0;
	while (s && s[len] != NULL)
		len++;
	return (len);
}

char *ft_free_2d_array(char ***arr, unsigned int allocated)
{
	unsigned int i;
	unsigned int current;

	current = 1;
	if (*arr == NULL)
		return (NULL);
	i = 0;
	while (i < allocated + current)
	{
		free((*arr)[i]);
		i++;
	}
	free(*arr);
	*arr = NULL;
	return (NULL);
}

char *ft_strdup(const char *s1)
{
	char *duplicate;
	char *cache;
	int s_len;

	s_len = ft_strlen(s1);
	duplicate = (char *)malloc((sizeof(*s1) * s_len) + 1);
	if (duplicate == NULL)
		return (NULL);
	cache = duplicate;
	while (*s1 != '\0')
		*cache++ = *s1++;
	*cache = '\0';
	return (duplicate);
}

int get_number(char *el)
{
	int i;
	int num;

	while (*el && ft_strchr(" \t\r", *el))
		el++;
	num = 0;
	while (ft_isdigit(*el))
	{
		num = num * 10;
		num += *el - '0';
		el++;
	}
	while (*el && ft_strchr(" \t\r", *el))
		el++;
	if (*el != '\0')
		return (-1);
	return (num);
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

int is_rgb_valid(t_img *img, char **split, int tmp[3])
{
	int i;

	i = 0;
	while (i < 3)
	{
		tmp[i] = get_number(split[i]);
		if (tmp[i] < 0 || tmp[i] > 255)
			return (1);
		i++;
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
		|| (flag == 'F' && img->floor_rgb[0] != -1) || is_rgb_valid(img, split, tmp))
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
	path = ft_substr(el, 0, ft_strlen(el));
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

	if (ft_strnstr("NOSOWEEA", tmp, 9) && !is_path_valid(img, el, tmp[0]))
	    return (0);
	if (ft_strnstr("F C ", tmp, 5) && !is_color_valid(img, el, tmp[0]))
		return (0);
	return (1);
}

int main(void)
{
	t_img img;
	img.floor_rgb[0] = -1;
	img.ceiling_rgb[0] = -1;
	img.north_path = NULL;
	img.south_path = NULL;
	img.east_path = NULL;
	img.west_path = NULL;
	char *test = "NO../maps/test.cub";
	char *test2 = "   WE     ../maps/test.cub";
	char *test3 = "SO     ../maps/test.cub";
	char *test4 = "EA        ../maps/test.cub";

	char *test5 = "NO     ../maps/test.cub";
	char *test6 = "NR ../maps/test.cub";
	char *test7 = "NR ./maps/test.cub";
	char *test8 = "EA        ../maps/test.cub";

	printf("\n   **Cardinal directions tests ** \ntest (to be fixed): %d\n", is_element_valid(&img, test));
	printf("test2: %d\n", is_element_valid(&img, test2));
	printf("test3: %d\n", is_element_valid(&img, test3));
	printf("test4: %d\n", is_element_valid(&img, test4));
	printf("\n   --Invalid below-- \ntest5: %d\n", is_element_valid(&img, test5));
	printf("test6: %d\n", is_element_valid(&img, test6));
	printf("test7: %d\n", is_element_valid(&img, test7));
	printf("test8: %d\n", is_element_valid(&img, test7));

	// char *test10 = "F 1   ,123, 21";
	// char *test11 = "C         1     ,          2a          ,               3";
	// char *test12 = "C 10, 255,255";
	// char *test13 = "F 1   ,123, 21";
	// char *test14 = "C 10, 255,255";

	// printf("test10: %d\n", is_element_valid(&img, test10));
	// printf("test11: %d\n", is_element_valid(&img, test11));
	// printf("test12: %d\n", is_element_valid(&img, test12));
	// printf("test13: %d\n", is_element_valid(&img, test13));
	// printf("test14: %d\n", is_element_valid(&img, test13));
	return (0);
}