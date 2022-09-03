/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keyrelease.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 21:55:25 by mariana           #+#    #+#             */
/*   Updated: 2022/09/03 16:57:55 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keyrelease(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		ft_message(1, data);
		ft_destroy_imgs(data);
		exit(0);
	}
	else if (keysym == UP)
		ft_move(data, data->map.width * -1);
	else if (keysym == LEFT)
	{
		mlx_destroy_image(data->mlx_ptr, data->sprites.player.mlx_img);
		data->sprites.player = ft_create_img(data, DINO_LEFT_PATH);
		ft_move(data, -1);
	}
	else if (keysym == DOWN)
		ft_move(data, data->map.width);
	else if (keysym == RIGHT)
	{
		mlx_destroy_image(data->mlx_ptr, data->sprites.player.mlx_img);
		data->sprites.player = ft_create_img(data, DINO_RIGHT_PATH);
		ft_move(data, 1);
	}
	return (0);
}
