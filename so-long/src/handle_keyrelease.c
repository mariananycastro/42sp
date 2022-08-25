/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keyrelease.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 21:55:25 by mariana           #+#    #+#             */
/*   Updated: 2022/08/24 18:43:26 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdio.h> // deletar

void	ft_move(t_data *data, int new_position)
{
	char	*matrix_position;
	int		index;

	index = data->map.player_position + new_position;
	matrix_position = &data->map.matrix[index];
	if (*matrix_position != WALL)
	{
		if (*matrix_position == COLLECTIBLE)
		{
			data->score++;
			printf("Score: %d\n", data->score);
		}
		if (*matrix_position == EXIT)
		{
			printf("End Game: %d\n", data->score);
			ft_exit(data);
		}
		data->map.matrix[data->map.player_position] = EMPTY_SPACE;
		data->map.player_position = index;
		data->map.matrix[data->map.player_position] = PLAYER;
	}
}

int	handle_keyrelease(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		exit(0);
	else if (keysym == UP)
		ft_move(data, data->map.width * -1);
	else if (keysym == LEFT)
		ft_move(data, -1);
	else if (keysym == DOWN)
		ft_move(data, data->map.width);
	else if (keysym == RIGHT)
		ft_move(data, 1);
	return (0);
}
