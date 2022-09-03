/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_tiles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:49:30 by mariana           #+#    #+#             */
/*   Updated: 2022/09/03 16:56:38 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_valid_tiles(char buffer)
{
	if (buffer == COLLECTIBLE || buffer == EXIT || buffer == PLAYER
		|| buffer == WALL || buffer == EMPTY_SPACE || buffer == MONSTER)
		return (1);
	return (0);
}
