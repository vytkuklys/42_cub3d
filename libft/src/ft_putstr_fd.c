/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 11:00:28 by tblaase           #+#    #+#             */
/*   Updated: 2022/01/27 18:46:43 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* writes s to fd */
void	ft_putstr_fd(char *s, int fd)
{
	int		i;
	char	c;

	if (!s)
		s = "\0";
	if (!fd)
		fd = 1;
	i = 0;
	while (s[i] != '\0')
	{
		c = s[i];
		write(fd, &c, 1);
		i++;
	}
}
