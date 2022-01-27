/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 13:26:30 by tblaase           #+#    #+#             */
/*   Updated: 2022/01/27 18:44:50 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* counts the digits of an int */
int	ft_intlen(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (10);
	if (n >= 0 && n <= 9)
		return (1);
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
