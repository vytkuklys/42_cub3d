/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jludt <jludt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 17:49:37 by jludt             #+#    #+#             */
/*   Updated: 2021/07/01 11:38:56 by jludt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Outputs the character ’c’ to the given file descriptor.
** parameters:
** c - The character to output.
** fd - The file descriptor on which to write.
return value: none
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
