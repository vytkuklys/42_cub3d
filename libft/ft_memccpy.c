/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jludt <jludt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 15:07:14 by julian            #+#    #+#             */
/*   Updated: 2021/07/01 11:38:12 by jludt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The memccpy() function copies no more than n bytes from memory 
** area src to memory area dest,
** stopping when the character c is found.
** If the memory areas overlap, the results are undefined.
** return value:
** a pointer to the next character in dest after c,
** or NULL if c was not found in the first n characters of src.
*/

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*cache_dest;
	unsigned char	*cache_src;

	cache_dest = (unsigned char *)dest;
	cache_src = (unsigned char *)src;
	while (n--)
	{
		*cache_dest = *cache_src;
		if (*cache_src == (unsigned char)c)
			return (++cache_dest);
		cache_src++;
		cache_dest++;
	}
	return (NULL);
}
