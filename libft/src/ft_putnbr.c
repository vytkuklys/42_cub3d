/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:52:22 by tblaase           #+#    #+#             */
/*   Updated: 2022/01/27 18:46:40 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* write an integer into a string */
void	ft_putnbr(unsigned int n, char *str, unsigned int i)
{
	if (n >= 10)
	{
		ft_putnbr(n / 10, str, i - 1);
		ft_putnbr(n % 10, str, i);
	}
	else
		str[i] = n + '0';
	i++;
}
