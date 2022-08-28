/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 22:13:53 by mariana           #+#    #+#             */
/*   Updated: 2022/08/28 15:28:28 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_validate_map(t_data *data, const char *map_file)
{
	int		width;
	int		height;
	char	*matrix;

	width = data->map.width;
	height = data->map.height;
	matrix = data->map.matrix;
	if (ft_validate_extension(map_file) != 0)
	{
		ft_error_message(3);
		ft_destroy_matrix(data);
	}
	if (ft_check_map_tiles(width, height, matrix) != 0)
	{
		ft_error_message(2);
		ft_destroy_matrix(data);
	}
}
