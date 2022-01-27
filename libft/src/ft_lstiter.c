/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:09:13 by tblaase           #+#    #+#             */
/*   Updated: 2022/01/27 18:45:49 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* will iterate through lst and use function f on every element */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst != NULL && f != NULL)
	{
		while (lst != NULL)
		{
			f(lst->content);
			lst = lst->next;
		}
	}
}
