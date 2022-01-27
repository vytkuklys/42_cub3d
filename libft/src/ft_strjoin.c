/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 10:35:44 by tblaase           #+#    #+#             */
/*   Updated: 2022/01/27 19:38:53 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* will append s2 to s1
** will do nothing if s2 is NULL
** will free s1 */
char	*ft_strjoin(char *s1, const char *s2)
{
	char	*c;
	int		i;
	int		i2;

	if (!s2)
		return (0);
	i = 0;
	i2 = 0;
	c = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (c == '\0')
		return (0);
	while (s1[i] != '\0')
	{
		c[i] = s1[i];
		i++;
	}
	while (s2[i2] != '\0')
	{
		c[i] = s2[i2];
		i++;
		i2++;
	}
	c[i] = '\0';
	ft_free_str(&s1);
	return (c);
}
