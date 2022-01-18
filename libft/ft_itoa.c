/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jludt <jludt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:40:52 by jludt             #+#    #+#             */
/*   Updated: 2021/07/01 11:37:51 by jludt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates (with malloc(3)) and returns a string
** representing the integer received as an argument.
** Negative numbers must be handled.
** parameters:
** n - the integer to convert.
** return value:
** The string representing the integer. NULL if the
** allocation fails.
*/

static char	*positiv(int n, int len, char *dest)
{
	dest[len] = '\0';
	len--;
	while (len)
	{
		dest[len--] = '0' + n % 10;
		n = n / 10;
	}
	dest[len] = '0' + n % 10;
	return (dest);
}

static char	*min_int(char *dest)
{
	dest[0] = '-';
	dest[1] = '2';
	dest[2] = '1';
	dest[3] = '4';
	dest[4] = '7';
	dest[5] = '4';
	dest[6] = '8';
	dest[7] = '3';
	dest[8] = '6';
	dest[9] = '4';
	dest[10] = '8';
	dest[11] = '\0';
	return (dest);
}

static char	*get_number(int n, int len, char *dest)
{
	if (n >= 0)
		dest = positiv(n, len, dest);
	else
	{
		if (n == -2147483648)
		{
			dest = min_int(dest);
			return (dest);
		}
		else
			dest[++len] = '\0';
		n = n * (-1);
		len--;
		while (len)
		{
			dest[len--] = '0' + n % 10;
			n = n / 10;
		}
		dest[len] = '-';
	}
	return (dest);
}

char	*ft_itoa(int n)
{
	int		number;
	int		len_n;
	char	*s_int;
	int		sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	number = n;
	len_n = 0;
	if (n == 0)
		len_n = 1;
	while (number != 0)
	{
		number = number / 10;
		len_n++;
	}
	if (n >= 0)
		s_int = malloc(sizeof(char) * len_n + 1);
	else
		s_int = malloc(sizeof(char) * len_n + 2);
	if (s_int == NULL)
		return (NULL);
	s_int = get_number(n, len_n, s_int);
	return (s_int);
}
