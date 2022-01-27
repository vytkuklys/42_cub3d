/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 16:22:00 by jludt             #+#    #+#             */
/*   Updated: 2022/01/20 14:55:36 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** Returns the last element of the list.
** parameters:
** lst - The beginning of the list.
** return value: Last element of the list.
*/

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp != NULL)
	{
		if (tmp->next == NULL)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}
