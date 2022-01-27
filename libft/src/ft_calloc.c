/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:12:36 by tblaase           #+#    #+#             */
/*   Updated: 2022/01/27 19:09:36 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* mallocs for the size of nelem * elsize and sets everything to NULL*/
void	*ft_calloc(size_t nelem, size_t elsize)
{
	int		full_size;
	char	*buf;

	full_size = elsize * nelem;
	buf = malloc(full_size);
	if (buf == NULL)
		return (NULL);
	return (ft_memset((void *)buf, 0, full_size));
}
