/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keyrelease_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 21:55:25 by mariana           #+#    #+#             */
/*   Updated: 2022/09/04 19:22:32 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	handle_keyrelease_bonus(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		ft_message_bonus(1, data);
		ft_destroy_imgs_bonus(data);
		exit(0);
	}
	else if (keysym == UP)
		ft_move_bonus(data, data->map.width * -1);
	else if (keysym == LEFT)
	{
		mlx_destroy_image(data->mlx_ptr, data->sprites.player.mlx_img);
		data->sprites.player = ft_create_img_bonus(data, DINO_LEFT_PATH);
		ft_move_bonus(data, -1);
	}
	else if (keysym == DOWN)
		ft_move_bonus(data, data->map.width);
	else if (keysym == RIGHT)
	{
		mlx_destroy_image(data->mlx_ptr, data->sprites.player.mlx_img);
		data->sprites.player = ft_create_img_bonus(data, DINO_RIGHT_PATH);
		ft_move_bonus(data, 1);
	}
	return (0);
}
