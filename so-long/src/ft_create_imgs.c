/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_imgs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 22:11:27 by mariana           #+#    #+#             */
/*   Updated: 2022/08/22 22:11:29 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_create_imgs(t_data *data)
{
	char	*blueDinoPath = "./sprites/player/RedDino.xpm";
	char	*wallPath = "./sprites/background/wall.xpm";
	char	*emptySpacePath = "./sprites/background/background.xpm";
	char	*exitPath = "./sprites/background/window.xpm";
	char	*diamondPath = "./sprites/coins/diamond.xpm";
	t_img blueDinoImg;
	t_img wallImg;
	t_img emptySpaceImg;
	t_img exitImg;
	t_img collectibleImg;

	blueDinoImg.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, blueDinoPath, &blueDinoImg.width, &blueDinoImg.height);
	blueDinoImg.addr = mlx_get_data_addr(blueDinoImg.mlx_img, &blueDinoImg.bpp, &blueDinoImg.line_len, &blueDinoImg.endian);

	wallImg.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, wallPath, &wallImg.width, &wallImg.height);
	wallImg.addr = mlx_get_data_addr(wallImg.mlx_img, &wallImg.bpp, &wallImg.line_len, &wallImg.endian);

	emptySpaceImg.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, emptySpacePath, &emptySpaceImg.width, &emptySpaceImg.height);
	emptySpaceImg.addr = mlx_get_data_addr(emptySpaceImg.mlx_img, &emptySpaceImg.bpp, &emptySpaceImg.line_len, &emptySpaceImg.endian);

	exitImg.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, exitPath, &exitImg.width, &exitImg.height);
	exitImg.addr = mlx_get_data_addr(exitImg.mlx_img, &exitImg.bpp, &exitImg.line_len, &exitImg.endian);

	collectibleImg.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, diamondPath, &collectibleImg.width, &collectibleImg.height);
	collectibleImg.addr = mlx_get_data_addr(collectibleImg.mlx_img, &collectibleImg.bpp, &collectibleImg.line_len, &collectibleImg.endian);

	data->sprites.player = blueDinoImg;
	data->sprites.wall = wallImg;
	data->sprites.empty_space = emptySpaceImg;
	data->sprites.exit = exitImg;
	data->sprites.collectible = collectibleImg;
}
