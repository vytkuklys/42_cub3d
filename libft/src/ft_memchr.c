/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 13:35:08 by tblaase           #+#    #+#             */
/*   Updated: 2022/01/27 18:46:08 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*a;
	unsigned char	b;

	i = 0;
	b = c;
	a = (unsigned char *)s;
	while (i < n)
	{
		if (a[i] == b)
			return (a + i);
		i++;
	}
	return (0);
}
