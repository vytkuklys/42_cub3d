/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jludt <jludt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 16:09:43 by jludt             #+#    #+#             */
/*   Updated: 2021/07/01 11:39:42 by jludt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates (with malloc(3)) and returns a new string, 
** which is the result of the concatenation of ’s1’ and ’s2’.
** parameters:
** s1 - The prefix string.
** s2 - The suffix string.
** return value:
** The new string. NULL if the allocation fails.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s_join;
	int		len_s1;
	int		len_s2;
	int		i;
	int		j;

	if (s1 == 0 || s2 == 0)
		return (0);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	s_join = (char *)malloc(sizeof(*s1) * (len_s1 + len_s2) + 1);
	if (s_join == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		s_join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		s_join[i++] = s2[j++];
	s_join[i] = '\0';
	return (s_join);
}
