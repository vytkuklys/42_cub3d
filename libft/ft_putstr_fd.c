/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jludt <jludt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 17:54:20 by jludt             #+#    #+#             */
/*   Updated: 2021/07/01 11:39:13 by jludt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Outputs the string ’s’ to the given file descriptor.
** parameters:
** s - The string to output.
** fd - The file descriptor on which to write.
** return value: none
*/

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		while (*s != '\0')
			write(fd, s++, 1);
}
