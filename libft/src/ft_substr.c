/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 18:37:26 by tblaase           #+#    #+#             */
/*   Updated: 2022/02/01 13:54:55 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* will create a string with length len from position start of s */
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char				*c;
	unsigned int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	c = malloc(len + 1);
	if (c == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		c[i] = '\0';
		return (c);
	}
	while (i < len)
	{
		c[i] = s[start];
		i++;
		start ++;
	}
	c[i] = '\0';
	return (c);
}
