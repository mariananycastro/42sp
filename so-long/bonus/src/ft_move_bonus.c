/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:57:13 by mariana           #+#    #+#             */
/*   Updated: 2022/09/04 19:20:21 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_change_tile(t_data *data, int index)
{
	data->map.matrix[data->map.player_position] = EMPTY_SPACE;
	data->map.player_position = index;
	data->map.matrix[data->map.player_position] = PLAYER;
}

void	ft_collectible_movement(t_data *data, int index)
{
	data->score++;
	ft_message_bonus(2, data);
	ft_change_tile(data, index);
	if (data->collectibles == data->score)
	{
		mlx_destroy_image(data->mlx_ptr, data->sprites.exit.mlx_img);
		data->sprites.exit = ft_create_img_bonus(data, OPENED_DOOR_PATH);
		ft_message_bonus(4, data);
	}
}

void	ft_exit_movement(t_data *data)
{
	if (data->collectibles == data->score)
	{
		ft_message_bonus(1, data);
		ft_exit_bonus(data);
	}
	else
		ft_message_bonus(3, data);
}

void	ft_count_moves(t_data *data)
{
	data->movements++;
	ft_message_bonus(5, data);
}

void	ft_move_bonus(t_data *data, int new_position)
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
			ft_message_bonus(6, data);
			ft_exit_bonus(data);
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
