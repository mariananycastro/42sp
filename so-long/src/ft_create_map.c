/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 22:14:14 by mariana           #+#    #+#             */
/*   Updated: 2022/08/25 10:27:27 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_create_map(t_data *data, const char *map_file)
{
	ft_get_map_size(data, map_file);
	ft_set_map_matrix(data, map_file);
	ft_validate_map(data, map_file);
}
