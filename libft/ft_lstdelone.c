/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jludt <jludt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 10:37:10 by jludt             #+#    #+#             */
/*   Updated: 2021/06/30 10:54:09 by jludt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Takes as a parameter an element and frees the memory of the element’s 
** content using the function ’del’ given as a parameter and free the element.
** The memory of ’next’ must not be freed.
** parameters:
** lst - The element to free.
** del - The address of the function used to delete the content.
** return value: none
*/

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst)
	{
		if (del)
			del(lst->content);
		free (lst);
	}
}
