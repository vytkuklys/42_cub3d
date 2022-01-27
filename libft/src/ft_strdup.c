/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 17:55:54 by tblaase           #+#    #+#             */
/*   Updated: 2022/01/27 18:46:58 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* will malloc for the given string and return adress to that string */
char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s;

	if (!s1)
		return (NULL);
	i = 0;
	s = malloc(ft_strlen(s1) + 1);
	if (!s)
		return (NULL);
	while (s1[i] != '\0')
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
