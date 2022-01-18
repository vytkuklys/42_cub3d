/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jludt <jludt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 18:05:33 by julian            #+#    #+#             */
/*   Updated: 2021/07/01 11:38:37 by jludt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The memset() function writes len bytes of value 
** c (converted to an unsigned char) to the string b.
** of the memory area pointed to by b with the constant byte c. 
** The memset() function returns its first argument.
*/

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*new;

	new = b;
	while (len--)
		*new++ = c;
	return (b);
}
