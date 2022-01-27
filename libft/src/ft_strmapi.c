/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 10:15:38 by tblaase           #+#    #+#             */
/*   Updated: 2022/01/27 18:47:16 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strmapi(const char *s, char (*f) (unsigned int, char))
{
	unsigned int	i;
	char			*res;

	if (!s)
		return (0);
	i = 0;
	res = malloc(ft_strlen(s) + 1);
	if (res == '\0' || s == '\0' || f == '\0')
		return (0);
	while (s[i] != '\0')
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
