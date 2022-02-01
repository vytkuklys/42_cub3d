/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:13:38 by tblaase           #+#    #+#             */
/*   Updated: 2022/02/01 13:51:32 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* will append s2 to s1
** will do nothing if s1 or s2 is NULL
** this is a modified ft_strjoin, it will ad the divider between the strings */
char	*ft_strcjoin(const char *s1, const char *s2, char divider)
{
	char	*c;
	int		i;
	int		i2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	i2 = 0;
	c = malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (c == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		c[i] = s1[i];
		i++;
	}
	c[i++] = divider;
	while (s2[i2] != '\0')
	{
		c[i] = s2[i2];
		i++;
		i2++;
	}
	c[i] = '\0';
	return (c);
}
