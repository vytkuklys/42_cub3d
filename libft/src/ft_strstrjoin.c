/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:18:29 by tblaase           #+#    #+#             */
/*   Updated: 2022/02/01 13:53:23 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* will append s2 to s1
** will do nothing if s1, s2 or divider is NULL
** it will ad the divider string between the strings
** will free s1 */
char	*ft_strstrjoin(char *s1, const char *s2, char *divider)
{
	char	*c;
	int		i;
	int		i2;

	if (s1 == NULL || s2 == NULL || divider == NULL)
		return (NULL);
	i = 0;
	i2 = 0;
	s1 = ft_strjoin(s1, divider);
	c = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (c == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		c[i] = s1[i];
		i++;
	}
	while (s2[i2] != '\0')
		c[i++] = s2[i2++];
	c[i] = '\0';
	ft_free_str(&s1);
	return (c);
}
