/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jludt <jludt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:29:00 by jludt             #+#    #+#             */
/*   Updated: 2021/07/01 11:41:56 by jludt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates (with malloc(3)) and returns a substring from the string ’s’.
** The substring begins at index ’start’ and is of maximum size ’len’.
** parameters:
** s		- The string from which to create the substring.
** start	- The start index of the substring in the string ’s’.
** len		- The maximum length of the substring.
** return value: 
** The substring. NULL if the allocation fails.
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*s_sub;
	unsigned int	j;

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
