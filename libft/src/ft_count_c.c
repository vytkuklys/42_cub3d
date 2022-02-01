/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:01:45 by tblaase           #+#    #+#             */
/*   Updated: 2022/02/01 13:44:07 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* will count appearances of c inside str and return them as integer */
int	ft_count_c(char *str, char c)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	if (str == NULL)
		return (-1);
	while (str && str[i])
	{
		if (str[i++] == c)
			x++;
	}
	return (x);
}
