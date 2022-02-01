/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 03:03:15 by vkuklys           #+#    #+#             */
/*   Updated: 2022/02/01 03:13:38 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	is_movement(t_data *data)
{
	if (data->controls.down != -1 || data->controls.left != -1
		|| data->controls.right != -1 || data->controls.up != -1)
		return (true);
	return (false);
}

void	animate_hands(t_data *data)
{
	static int	left;
	static bool	up;

	if (left == -30)
		up = true;
	else if (left == 30)
		up = false;
	if (up == true && is_movement(data) == true)
		left += 2;
	else if (is_movement(data) == true)
		left -= 2;
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
		data->img.textures.left_hand, 0, left + 30);
	mlx_put_image_to_window(data->mlx_ptr,
		data->mlx_win, data->img.textures.right_hand, 0, left * -1 + 30);
}
