/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 22:13:53 by mariana           #+#    #+#             */
/*   Updated: 2022/08/28 16:23:56 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_validate_map(t_data *data)
{
	int		width;
	int		height;
	char	*matrix;

	width = data->map.width;
	height = data->map.height;
	matrix = data->map.matrix;
	if (ft_check_map_tiles(width, height, matrix, data) != 0)
	{
		ft_error_message(2);
		ft_destroy_matrix(data);
	}
}
