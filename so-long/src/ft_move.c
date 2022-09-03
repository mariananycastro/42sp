/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:57:13 by mariana           #+#    #+#             */
/*   Updated: 2022/09/03 16:57:59 by mariana          ###   ########.fr       */
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
	{
		mlx_destroy_image(data->mlx_ptr, data->sprites.exit.mlx_img);
		data->sprites.exit = ft_create_img(data, OPENED_DOOR_PATH);
		ft_message(4, data);
	}
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

void	ft_count_moves(t_data *data)
{
	data->movements++;
	ft_message(6, data);
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
		{
			ft_collectible_movement(data, index);
			ft_count_moves(data);
		}
		else if (*matrix_position == MONSTER)
		{
			ft_message(5, data);
			ft_exit(data);
		}
		else if (*matrix_position == EXIT)
			ft_exit_movement(data);
		else
		{
			ft_change_tile(data, index);
			ft_count_moves(data);
		}
	}
}
