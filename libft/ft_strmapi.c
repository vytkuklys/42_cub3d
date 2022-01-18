/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jludt <jludt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 12:58:55 by jludt             #+#    #+#             */
/*   Updated: 2021/07/01 11:40:07 by jludt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Applies the function ’f’ to each character of thestring ’s’ to create a 
** new string (with malloc(3)) resulting from successive applications of ’f’.
** parameters:
** s - The string on which to iterate.
** (*f) - The function to apply to each character.
** return value:
** The string created from the successive applications of ’f’'
** Returns NULL if the allocation fails.
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*s_new;
	int		i;

	if (s == 0 || f == 0)
		return (0);
	s_new = ft_strdup(s);
	if (s_new == NULL)
		return (NULL);
	i = 0;
	while (s_new[i] != '\0')
	{
		s_new[i] = f(i, s_new[i]);
		i++;
	}
	return (s_new);
}
