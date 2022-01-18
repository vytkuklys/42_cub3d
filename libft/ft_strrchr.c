/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jludt <jludt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 21:35:13 by julian            #+#    #+#             */
/*   Updated: 2021/07/01 11:41:20 by jludt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strrchr() function returns a pointer to the last occurrence of the 
** character c in the string s.
** return value:
** a pointer to the matched character or NULL if the character is not found.
** the terminating null byte is considered part of the string, so that if c is
** specified as '\0', these functions return a pointer to the terminator.
*/

char	*ft_strrchr(const char *s, int c)
{
	int	number_of_c;
	int	i;

	number_of_c = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			number_of_c++;
		i++;
	}
	while (*s != '\0')
	{
		if (*s == c)
			number_of_c--;
		if (*s == c && number_of_c == 0)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (NULL);
}
