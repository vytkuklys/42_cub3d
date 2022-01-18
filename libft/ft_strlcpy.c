/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jludt <jludt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 11:37:02 by jludt             #+#    #+#             */
/*   Updated: 2021/07/01 11:39:53 by jludt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** strlcpy() and strlcat() take the full size of the destination buffer and 
** guarantee NUL-termination if there is room.  Note that room for the NUL 
** should be included in dstsize.
** strlcpy() copies up to dstsize - 1 characters from the string src to dst, 
** NUL-terminating the result if dstsize is not 0.
** return value:
** The strlcpy() function returns the total length of the string it tried 
** to create. For strlcpy() that means the length of src.
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	length;
	size_t	i;

	if (dst == 0 || src == 0)
		return (0);
	length = ft_strlen(src);
	if (dstsize == 0)
		return (length);
	i = 0;
	while (src[i] != '\0' && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (length);
}
