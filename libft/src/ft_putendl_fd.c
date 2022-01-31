/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 11:07:51 by tblaase           #+#    #+#             */
/*   Updated: 2022/01/31 18:47:50 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* writes s to fd followed by a \n */
void	ft_putendl_fd(char *s, int fd)
{
	char	c;

	ft_putstr_fd(s, fd);
	c = '\n';
	write (fd, &c, 1);
}
