/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_imgs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 22:11:27 by mariana           #+#    #+#             */
/*   Updated: 2022/08/28 17:49:28 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	ft_create_img(t_data *data, char *imgPath)
{
	t_img	new_img;

	new_img.mlx_img = mlx_xpm_file_to_image(
			data->mlx_ptr, imgPath, &new_img.width, &new_img.height
			);
	if (new_img.mlx_img == NULL)
		ft_destroy_window(data);
	new_img.addr = mlx_get_data_addr(
			new_img.mlx_img, &new_img.bpp, &new_img.line_len, &new_img.endian
			);
	return (new_img);
}

void	ft_create_imgs(t_data *data)
{
	data->sprites.player = ft_create_img(data, DINO_PATH);
	data->sprites.wall = ft_create_img(data, WALL_PATH);
	data->sprites.empty_space = ft_create_img(data, EMPTY_SPACE_PATH);
	data->sprites.exit = ft_create_img(data, EXIT_PATH);
	data->sprites.collectible = ft_create_img(data, COLLECTIBLE_PATH);
	data->sprites.monster = ft_create_img(data, MONSTER_PATH);
}
