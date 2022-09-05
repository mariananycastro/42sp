/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 22:14:14 by mariana           #+#    #+#             */
/*   Updated: 2022/09/04 19:23:45 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_create_map_bonus(t_data *data, const char *map_file)
{
	if (ft_validate_extension_bonus(map_file) != 0)
	{
		ft_error_message_bonus(3);
		exit(0);
	}
	ft_get_map_size_bonus(data, map_file);
	ft_set_map_matrix_bonus(data, map_file);
	ft_validate_map_bonus(data);
}
