/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_imgs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 22:10:42 by mariana           #+#    #+#             */
/*   Updated: 2022/08/28 15:43:23 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_destroy_imgs(t_data *data)
{
    mlx_destroy_image(data->mlx_ptr, data->sprites.player.mlx_img);
	mlx_destroy_image(data->mlx_ptr, data->sprites.wall.mlx_img);
	mlx_destroy_image(data->mlx_ptr, data->sprites.empty_space.mlx_img);
	mlx_destroy_image(data->mlx_ptr, data->sprites.exit.mlx_img);
	mlx_destroy_image(data->mlx_ptr, data->sprites.collectible.mlx_img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	ft_destroy_display(data);
}
