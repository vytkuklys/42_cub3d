/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:04:41 by tblaase           #+#    #+#             */
/*   Updated: 2022/01/27 18:46:52 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* will return a pointer to the position of first appearance of c in s
** will return a pointer to NULL if not found */
char	*ft_strchr(const char *s, int c)
{
	char	a;
	int		i;

	if (!s)
		return (NULL);
	a = c;
	i = 0;
	while (s && s[i] != '\0' && s[i] != a)
		i++;
	if (s[i] == a)
		return ((char *)(s + i));
	else
		return (NULL);
}
