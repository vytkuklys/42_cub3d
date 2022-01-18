/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jludt <jludt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 17:19:46 by julian            #+#    #+#             */
/*   Updated: 2021/07/01 11:38:32 by jludt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The memmove() function copies len bytes from string src to string dst.  
** The two strings may overlap; 
** the copy is always done in a non-destructive manner.
** return value: the original value of dst
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*cache_dst;
	unsigned char	*cache_src;

	cache_dst = (unsigned char *)dst;
	cache_src = (unsigned char *)src;
	if (cache_src < cache_dst)
	{
		while (len--)
			cache_dst[len] = cache_src[len];
	}
	else
		ft_memcpy(cache_dst, cache_src, len);
	return (dst);
}
