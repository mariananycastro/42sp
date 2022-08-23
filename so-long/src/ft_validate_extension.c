/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_extension.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 22:12:39 by mariana           #+#    #+#             */
/*   Updated: 2022/08/22 22:12:41 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_validate_extension(char *map_file)
{
	int	extention_size;
	size_t path_size;

	extention_size = 4;
	path_size = ft_strlen(map_file);
	return (ft_memcmp(&map_file[path_size - extention_size], ".ber", extention_size));
}
