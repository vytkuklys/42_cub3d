/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 18:05:33 by julian            #+#    #+#             */
/*   Updated: 2022/01/20 14:56:05 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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
