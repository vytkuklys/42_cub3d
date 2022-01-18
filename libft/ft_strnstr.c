/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jludt <jludt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 08:50:15 by julian            #+#    #+#             */
/*   Updated: 2021/07/01 11:35:27 by jludt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** strnstr — locate a substring in a string
** The strnstr() function locates the first occurrence of the null-terminated
** string needle in the string haystack, where not more than len characters are 
** searched. Characters that appear after a ‘\0’character are not searched.  
** Since the strnstr() function is a FreeBSD specific API, it should only be 
** used when portability is not a concern.
** return value:
** If needle is an empty string, haystack is returned; if needle occurs nowhere 
** in haystack, NULL is returned; otherwise a pointer to the first character of 
** the first occurrence of needle is returned.
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (i < len && haystack[i] != '\0')
	{
		if (needle[0] == haystack[i])
		{
			j = 0;
			while (needle[j] != '\0' && haystack[i + j] == needle[j]
				&& i + j < len)
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
