/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jludt <jludt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 12:41:06 by julian            #+#    #+#             */
/*   Updated: 2021/07/01 11:37:19 by jludt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The bzero() function writes n zeroed bytes to the string s.  
** If n is zero, bzero() does nothing. 
** to that area.
** return value: none
*/

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*null;

	null = s;
	while (n--)
		*null++ = '\0';
}
