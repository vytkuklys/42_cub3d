/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_str_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 17:57:35 by tblaase           #+#    #+#             */
/*   Updated: 2022/01/27 19:00:09 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
 * Frees allocated null-terminated string array
*/
void	ft_free_str_array(char ***arr)
{
	int	i;

	i = 0;
	while (*arr && (*arr)[i] != NULL)
	{
		ft_free_str(&(*arr)[i]);
		(*arr)[i] = NULL;
		i++;
	}
	free(*arr);
	*arr = NULL;
}
