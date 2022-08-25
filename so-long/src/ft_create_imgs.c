/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_imgs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 22:11:27 by mariana           #+#    #+#             */
/*   Updated: 2022/08/24 18:43:07 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	ft_create_img(t_data *data, char *imgPath)
{
	t_img	new_img;

	new_img.mlx_img = mlx_xpm_file_to_image(
			data->mlx_ptr, imgPath, &new_img.width, &new_img.height
			);
	new_img.addr = mlx_get_data_addr(
			new_img.mlx_img, &new_img.bpp, &new_img.line_len, &new_img.endian
			);
	return (new_img);
}

void	ft_create_imgs(t_data *data)
{
	t_img	dino_img;
	t_img	wall_img;
	t_img	empty_space_img;
	t_img	exit_img;
	t_img	collectible_img;

	dino_img = ft_create_img(data, DINO_PATH);
	data->sprites.player = dino_img;
	wall_img = ft_create_img(data, WALL_PATH);
	data->sprites.wall = wall_img;
	empty_space_img = ft_create_img(data, EMPTY_SPACE_PATH);
	data->sprites.empty_space = empty_space_img;
	exit_img = ft_create_img(data, EXIT_PATH);
	data->sprites.exit = exit_img;
	collectible_img = ft_create_img(data, COLLECTIBLE_PATH);
	data->sprites.collectible = collectible_img;
}
