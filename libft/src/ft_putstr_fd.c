/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 11:00:28 by tblaase           #+#    #+#             */
/*   Updated: 2022/02/01 14:20:56 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* writes s to fd
*  can't write to fd=0 */
void	ft_putstr_fd(char *s, int fd)
{
	int		i;
	char	c;

	if (s == NULL)
		s = "\0";
	if (fd == 0)
		fd = 1;
	i = 0;
	while (s[i] != '\0')
	{
		c = s[i];
		write(fd, &c, 1);
		i++;
	}
}
