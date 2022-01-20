/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 10:54:07 by jludt             #+#    #+#             */
/*   Updated: 2022/01/20 14:55:33 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** Iterates the list ’lst’ and applies the function’f’
** to the content of each element.
** parameters:
** lst - The adress of a pointer to an element.
** f - The adress of the function used to iterate on the list.
** return value: None
*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;

	tmp = lst;
	if (lst == NULL || f == NULL)
		return ;
	while (tmp != NULL)
	{
		f(tmp->content);
		tmp = tmp->next;
	}
}
