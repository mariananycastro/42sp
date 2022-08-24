/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keyrelease.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 21:55:25 by mariana           #+#    #+#             */
/*   Updated: 2022/08/24 14:07:19 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdio.h> // deletar

void ft_move(t_data *data, int new_position)
{
	char *matrix_position;

	matrix_position = &data->map.matrix[data->map.player_position + new_position];

	if (ft_is_wall(*matrix_position) == 0)
	{
		if (ft_is_coin(*matrix_position) == 1)
		{
			data->score++;
			printf("Score: %d\n", data->score);
		}
		if (ft_is_exit(*matrix_position) == 1)
		{
			printf("End Game: %d\n", data->score);
			ft_exit(data);
		}
		data->map.matrix[data->map.player_position] = '0';
		data->map.player_position = data->map.player_position + new_position;
		data->map.matrix[data->map.player_position] = 'P';
	}
}

int	handle_keyrelease(int keysym, t_data *data)
{
	int w_up;
	int a_left;
	int s_down;
	int d_right;
	int new_position;

	w_up = 119;
	a_left = 97;
	s_down = 115;
	d_right = 100;

	if (keysym == XK_Escape)
		exit(0);
	else if (keysym == w_up)
	{
		new_position = data->map.width * -1;
		ft_move(data, new_position);
	}
	else if (keysym == a_left)
	{
		new_position =  -1;
		ft_move(data, new_position);
	}
	else if (keysym == s_down)
	{
		new_position = data->map.width;
		ft_move(data, new_position);
	}
	else if (keysym == d_right)
	{
		new_position = 1;
		ft_move(data, new_position);
	}
	return (0);
}
