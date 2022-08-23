/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 22:13:53 by mariana           #+#    #+#             */
/*   Updated: 2022/08/22 22:23:45 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_validate_map(t_data *data, char *map_file)
{
	if (ft_validate_extension(map_file) != 0)
	{
		ft_printf("Error\n Invalid extension\n");
		ft_exit(data);
	}
	if (ft_check_map_titles(data->map.width, data->map.height, data->map.matrix) != 0)
	{
		ft_printf("Error\nInvalid map titles\n");
		ft_exit(data);
	}
}
