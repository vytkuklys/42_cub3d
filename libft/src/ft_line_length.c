/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:42:17 by tblaase           #+#    #+#             */
/*   Updated: 2022/01/27 19:03:22 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* this function will find the length of the first line in a file */
int	ft_line_length(int fd)
{
	char	buffer[1];
	int		length;
	int		bytes;

	buffer[0] = '\0';
	bytes = 1;
	length = 0;
	while (bytes == 1)
	{
		bytes = read(fd, buffer, 1);
		if (buffer[0] != '\n' && buffer[0] != '\0')
			length++;
		else
			break ;
	}
	return (length);
}
