/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 21:19:26 by tblaase           #+#    #+#             */
/*   Updated: 2022/01/27 18:44:28 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* finds the first long long of a string and returns it as long long */
long long	ft_atol(char *str)
{
	int			c;
	int			i;
	long long	x;

	i = 0;
	c = 1;
	x = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			c = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		x = x * 10 + (str[i] - 48);
		i++;
	}
	return (x * c);
}
