/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_titles.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 22:13:34 by mariana           #+#    #+#             */
/*   Updated: 2022/08/22 22:13:37 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

int ft_check_map_titles(int width, int height, char *matrix)
{
	int index;
	int has_c;
	int has_e;
	int has_p;

	index = 0;
	has_c = 0;
	has_e = 0;
	has_p = 0;

	while(matrix[index])
	{
		if (index < width || index >= ((width * height) - width) || index%width == 0 || index%width == width - 1)
		{
			if (ft_is_wall(matrix[index]) != 1)
				return (1);
		}
		else
		{
			if (matrix[index] == 'C')
				has_c++;
			if (matrix[index] == 'E')
				has_e++;
			if (matrix[index] == 'P')
				has_p++;
		}
		index++;
	}
	if (has_c == 0 || has_e == 0 || has_p == 0)
		return (1);
	return(0);
}
