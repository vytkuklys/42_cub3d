/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:03:24 by tblaase           #+#    #+#             */
/*   Updated: 2022/01/27 18:45:28 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void	ft_standard(char *str, int i, int n)
{
	if (n < 0)
	{
		str[0] = 45;
		n = n * -1;
	}
	str[i] = '\0';
	i--;
	ft_putnbr(n, str, i);
}

/* turns an int into a string */
char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = ft_intlen(n);
	if (n == -2147483648)
		str = ft_strdup("-2147483648");
	else
	{
		if (n < 0)
			i++;
		str = malloc(i + 1);
		if (!str)
			return (NULL);
		ft_standard(str, i, n);
	}
	return (str);
}
