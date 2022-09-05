/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_imgs_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 22:11:27 by mariana           #+#    #+#             */
/*   Updated: 2022/09/04 19:19:29 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_create_imgs_bonus(t_data *data)
{
	data->sprites.player = ft_create_img_bonus(data, DINO_RIGHT_PATH);
	data->sprites.wall = ft_create_img_bonus(data, WALL_PATH);
	data->sprites.empty_space = ft_create_img_bonus(data, EMPTY_SPACE_PATH);
	data->sprites.exit = ft_create_img_bonus(data, CLOSED_DOOR_PATH);
	data->sprites.collectible = ft_create_img_bonus(data, COLLECTIBLE_PATH);
	data->sprites.monster = ft_create_img_bonus(data, MONSTER_PATH);
}
