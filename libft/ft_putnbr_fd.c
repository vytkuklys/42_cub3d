/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jludt <jludt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:22:24 by jludt             #+#    #+#             */
/*   Updated: 2021/07/01 11:39:08 by jludt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Outputs the integer ’n’ to the given file descriptor.
** parameters:
** n - The integer to output.
** fd - The file descriptor on which to write.
** return value: none
*/

int	positiv(int p, int fd)
{
	int	i;

	if (p == 0)
		return (0);
	i = p % 10;
	positiv(p / 10, fd);
	ft_putchar_fd('0' + i, fd);
	return (0);
}

int	negativ(int n, int fd)
{
	int	i;

	if (n == 0)
	{
		ft_putchar_fd('-', fd);
		return (0);
	}
	i = (n % 10) * (-1);
	negativ(n / 10, fd);
	ft_putchar_fd('0' + i, fd);
	return (0);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
	{
		write(fd, "0", 1);
	}
	else if (n > 0)
	{
		positiv(n, fd);
	}
	else
	{
		negativ(n, fd);
	}
}
