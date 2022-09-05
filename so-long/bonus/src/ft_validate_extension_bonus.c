/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_extension_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 22:12:39 by mariana           #+#    #+#             */
/*   Updated: 2022/09/04 19:18:00 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_validate_extension_bonus(const char *map_file)
{
	int		extention_size;
	size_t	path_size;
	size_t	index;

	extention_size = 4;
	path_size = ft_strlen(map_file);
	index = path_size - extention_size;
	return (ft_memcmp(&map_file[index], ".ber", extention_size));
}
