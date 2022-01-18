/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jludt <jludt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 09:38:58 by julian            #+#    #+#             */
/*   Updated: 2021/07/01 11:38:17 by jludt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The  memchr()  function  scans the initial n bytes of the memory area 
** pointed to by s. 
** for the first instance of c.  Both c and the bytes of the memory area 
** pointed to by s.
** are interpreted as unsigned char.
** return value:
** a pointer to the matching byte 
** or NULL if the character does not occur in the given memory area
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*match;
	int				null;

	match = (unsigned char *)s;
	null = 0;
	while ((unsigned char)n-- && null == 0)
	{
		if (*match != (unsigned char)c)
			match++;
		else
			null = 1;
	}
	if (null == 0)
		return (NULL);
	return (match);
}
