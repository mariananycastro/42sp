/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 22:14:14 by mariana           #+#    #+#             */
/*   Updated: 2022/08/28 15:56:16 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_create_map(t_data *data, const char *map_file)
{
	if (ft_validate_extension(map_file) != 0)
	{
		ft_error_message(3);
		exit(0);
	}
	ft_get_map_size(data, map_file);
	ft_set_map_matrix(data, map_file);
	ft_validate_map(data);
}
