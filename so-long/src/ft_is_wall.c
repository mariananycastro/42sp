/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 22:12:59 by mariana           #+#    #+#             */
/*   Updated: 2022/08/24 14:07:54 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_is_wall(char map_title)
{
	char wall;

	wall = '1';
	return (map_title == wall);
}

int ft_is_coin(char map_title)
{
	char coin;

	coin = 'C';
	return (map_title == coin);
}

int ft_is_exit(char map_title)
{
	char exit;

	exit = 'E';
	return (map_title == exit);
}
