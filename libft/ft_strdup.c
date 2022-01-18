/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jludt <jludt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 14:27:43 by julian            #+#    #+#             */
/*   Updated: 2021/07/01 11:39:30 by jludt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strdup() function allocates sufficient memory for a copy of the 
** string s1, does the copy, and returns a pointer to it.  
** The pointer may subsequently be used as an argument to the function free(3).
** return value:
** On success, the strdup() function returns a pointer to the duplicated 
** string. It returns NULL if insufficient memory was available, with errno 
** set to indicate the cause of the error.
*/

char	*ft_strdup(const char *s1)
{
	char	*duplicate;
	char	*cache;
	int		s_len;

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
