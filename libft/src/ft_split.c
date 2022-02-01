/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 13:46:19 by tblaase           #+#    #+#             */
/*   Updated: 2022/02/01 14:21:21 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* finds the next occurance of char c */
static int	ft_find_c(const char *s, char c, int i)
{
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

/* count the number of "words" within the given string */
static unsigned int	ft_count_words(const char *s, char c)
{
	int	str_nbr;
	int	i;

	if (s == NULL)
		return (0);
	str_nbr = 0;
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			str_nbr++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		str_nbr++;
	return (str_nbr);
}

/* will write the single "words" into the char **mainstr */
static void	ft_write_words(const char *s, char c, char **mainstr,
	unsigned int b)
{
	unsigned int	a;
	unsigned int	i;
	size_t			z;

	i = 0;
	a = 0;
	z = 0;
	while (a < b)
	{
		i = z + i;
		while (s[i] && s[i] == c)
			i++;
		z = ft_find_c(s, c, i) - i;
		mainstr[a] = (char *)ft_substr(s, i, z);
		a++;
	}
	mainstr[a] = NULL;
}

/* will split into single strings after every delimiter c */
char	**ft_split(const char *s, char c)
{
	char			**mainstr;
	unsigned int	b;

	if (s == NULL)
		return (NULL);
	b = ft_count_words(s, c);
	mainstr = (char **)malloc(b * sizeof(char *) + 1 * sizeof(char *));
	if (mainstr == NULL)
		return (NULL);
	ft_write_words(s, c, mainstr, b);
	return (mainstr);
}
