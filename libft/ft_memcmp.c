/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jludt <jludt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 14:03:02 by julian            #+#    #+#             */
/*   Updated: 2021/07/01 11:38:23 by jludt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The memcmp() function compares the first n bytes (each interpreted 
** as unsigned char) of the memory areas s1 and s2.
**return value:
** an integer less than, equal to, or greater than zero if the first n bytes 
** of s1 is found,respectively, to be less than, to match, or be greater than
** the first n bytes of s2.
** For a nonzero return value, the sign is determined by the sign of the 
** difference between the first pair of bytes (interpreted as unsigned char) 
** that differ in s1 and s2. If n is zero, the return value is zero.
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*cache_s1;
	const unsigned char	*cache_s2;
	size_t				i;

	cache_s1 = (const unsigned char *)s1;
	cache_s2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (cache_s1[i] != cache_s2[i])
			return (cache_s1[i] - cache_s2[i]);
		i++;
	}
	return (0);
}
