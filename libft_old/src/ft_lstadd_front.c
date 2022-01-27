/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:34:33 by jludt             #+#    #+#             */
/*   Updated: 2022/01/20 14:55:24 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** Adds the element ’new’ at the beginning of the list.
** parameters:
** lst - The address of a pointer to the first link of a list.
** new - The address of a pointer to the element to be
**       added to the list.
** return value: none
*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
