/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_imgs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 22:11:27 by mariana           #+#    #+#             */
/*   Updated: 2022/09/04 16:38:35 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_create_imgs(t_data *data)
{
	data->sprites.player = ft_create_img(data, DINO_RIGHT_PATH);
	data->sprites.wall = ft_create_img(data, WALL_PATH);
	data->sprites.empty_space = ft_create_img(data, EMPTY_SPACE_PATH);
	data->sprites.exit = ft_create_img(data, CLOSED_DOOR_PATH);
	data->sprites.collectible = ft_create_img(data, COLLECTIBLE_PATH);
}
