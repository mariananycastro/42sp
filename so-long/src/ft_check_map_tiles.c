/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_tiles.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 22:13:34 by mariana           #+#    #+#             */
/*   Updated: 2022/08/28 16:47:00 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_map_tiles(int width, int height, char *matrix, t_data *data)
{
	int	i;
	int	has_e;
	int	has_p;

	i = 0;
	data->collectibles = 0;
	has_e = 0;
	has_p = 0;
	while (matrix[i])
	{
		if ((i < width || i % width == 0 || i % width == (width - 1)
				|| i >= ((width * height) - width)) && matrix[i] != WALL)
			return (1);
		if (matrix[i] == COLLECTIBLE)
			data->collectibles++;
		if (matrix[i] == EXIT)
			has_e++;
		if (matrix[i] == PLAYER)
			has_p++;
		i++;
	}
	if (data->collectibles == 0 || has_e == 0 || has_p == 0)
		return (1);
	return (0);
}
