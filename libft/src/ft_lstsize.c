/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 13:51:49 by tblaase           #+#    #+#             */
/*   Updated: 2022/01/27 18:46:01 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* returns the size of a list as int */
int	ft_lstsize(t_list *lst)
{
	t_list	*current;
	int		i;

	i = 0;
	current = lst;
	while (current != NULL)
	{
		current = current->next;
		i++;
	}
	return (i);
}
