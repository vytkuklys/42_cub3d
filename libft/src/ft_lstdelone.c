/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:03:11 by tblaase           #+#    #+#             */
/*   Updated: 2022/01/27 18:45:46 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* free's the memory of the content using the function 'del' */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst != NULL && del != NULL)
	{
		del(lst->content);
		free(lst);
	}
}
