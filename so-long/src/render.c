/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 22:11:04 by mariana           #+#    #+#             */
/*   Updated: 2022/08/22 22:11:11 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render(t_data *data)
{
	size_t	index;
	size_t	x;
	size_t	y;
	size_t	max_x;
	size_t	max_y;

	index = 0;
	x = 0;
	y = 0;
	max_x = data->map.width * IMG_SIZE;
	max_y = data->map.height * IMG_SIZE;

	while(y < max_y)
	{
		while(x < max_x)
		{
			if (data->map.matrix[index] == '1') // wall
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->sprites.wall.mlx_img, x, y);
			if (data->map.matrix[index] == 'P') // player
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->sprites.player.mlx_img, x, y);
			if (data->map.matrix[index] == '0') // empty_space
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->sprites.empty_space.mlx_img, x, y);
			if (data->map.matrix[index] == 'C') // collectible
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->sprites.collectible.mlx_img, x, y);
			if (data->map.matrix[index] == 'E') // exit
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->sprites.exit.mlx_img, x, y);
			x = x + IMG_SIZE;
			index++;
		}
		y = y + IMG_SIZE;
		x = 0;
	}
	return (0);
}
