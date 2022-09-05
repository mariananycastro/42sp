/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_window_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:10:34 by mariana           #+#    #+#             */
/*   Updated: 2022/09/04 19:21:17 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_create_window_bonus(t_data	*data)
{
	int		width;
	int		height;

	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
	{
		ft_error_message_bonus(5);
		ft_destroy_matrix_bonus(data);
	}
	width = data->map.width * IMG_SIZE;
	height = data->map.height * IMG_SIZE;
	data->win_ptr = mlx_new_window(data->mlx_ptr, width, height, "So long!");
	if (data->win_ptr == NULL)
	{
		ft_error_message_bonus(5);
		ft_destroy_display_bonus(data);
	}
	return (0);
}
