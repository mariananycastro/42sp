/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_tiles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 20:15:30 by mariana           #+#    #+#             */
/*   Updated: 2022/09/03 20:16:42 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_valid_tiles(char buffer)
{
	if (buffer == COLLECTIBLE || buffer == EXIT || buffer == PLAYER
		|| buffer == WALL || buffer == EMPTY_SPACE)
		return (1);
	return (0);
}
