/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 10:46:45 by jludt             #+#    #+#             */
/*   Updated: 2022/01/20 14:55:27 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** Deletes and frees the given element and every successor of that element,
** using the function ’del’ and free(3).
** Finally, the pointer to the list must be set to NULL.
** parameters:
** lst - The adress of a pointer to an element.
** del - The adress of the function used to delete the content of the element.
** return value: none
*/

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}
