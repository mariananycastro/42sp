/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 22:13:53 by mariana           #+#    #+#             */
/*   Updated: 2022/09/04 19:21:26 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_validate_map_bonus(t_data *data)
{
	int		width;
	int		height;
	char	*matrix;

	width = data->map.width;
	height = data->map.height;
	matrix = data->map.matrix;
	if (ft_check_map_tiles_bonus(width, height, matrix, data) != 0)
	{
		ft_error_message_bonus(2);
		ft_destroy_matrix_bonus(data);
	}
}
