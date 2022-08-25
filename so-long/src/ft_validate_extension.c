/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_extension.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 22:12:39 by mariana           #+#    #+#             */
/*   Updated: 2022/08/24 19:03:12 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_validate_extension(char *map_file)
{
	int		extention_size;
	size_t	path_size;
	size_t	index;

	extention_size = 4;
	path_size = ft_strlen(map_file);
	index = path_size - extention_size;
	return (ft_memcmp(&map_file[index], ".ber", extention_size));
}
