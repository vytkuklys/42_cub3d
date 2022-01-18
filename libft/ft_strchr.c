/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jludt <jludt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 18:32:55 by julian            #+#    #+#             */
/*   Updated: 2021/10/27 19:37:26 by jludt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strchr() function returns a pointer to the first occurrence 
** of the character c in the string s.
** return value:
** a pointer to the matched character or NULL if the character is not found.
** the terminating null byte is considered part of the string, so that if c is
** specified as '\0', these functions return a pointer to the terminator.
*/

char	*ft_strchr(const char *s, int c)
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
