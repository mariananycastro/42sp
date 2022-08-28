/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keyrelease.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 21:55:25 by mariana           #+#    #+#             */
/*   Updated: 2022/08/28 18:07:29 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_change_tile(t_data *data, int index)
{
	data->map.matrix[data->map.player_position] = EMPTY_SPACE;
	data->map.player_position = index;
	data->map.matrix[data->map.player_position] = PLAYER;
}

void	ft_collectible_movement(t_data *data, int index)
{
	data->score++;
	ft_message(2, data);
	ft_change_tile(data, index);
	if (data->collectibles == data->score)
		ft_message(4, data);
}

void	ft_exit_movement(t_data *data)
{
	if (data->collectibles == data->score)
	{
		ft_message(1, data);
		ft_exit(data);
	}
	else
		ft_message(3, data);
}

void	ft_move(t_data *data, int new_position)
{
	char	*matrix_position;
	int		index;

	index = data->map.player_position + new_position;
	matrix_position = &data->map.matrix[index];
	if (*matrix_position != WALL)
	{
		if (*matrix_position == COLLECTIBLE)
			ft_collectible_movement(data, index);
		else if (*matrix_position == MONSTER)
		{
			ft_message(5, data);
			ft_exit(data);
		}
		else if (*matrix_position == EXIT)
			ft_exit_movement(data);
		else
			ft_change_tile(data, index);
	}
}

int	handle_keyrelease(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		ft_message(1, data);
		ft_destroy_imgs(data);
		exit(0);
	}
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
