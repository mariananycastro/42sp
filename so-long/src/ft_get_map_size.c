/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 22:11:46 by mariana           #+#    #+#             */
/*   Updated: 2022/08/22 22:11:59 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_get_map_size(t_data *data, char	*map_file)
{
	char	buffer;
	int		fd;
	int		lines;
	int 	std_column;
	int		columns;

	lines = 1;
	columns = 0;
	std_column = 0;
	fd = open(map_file, O_RDONLY);

	if (fd != -1)
	{
		while (read(fd, &buffer, 1) != 0)
		{
			if (buffer == 'C' || buffer == 'E' || buffer == 'P' || buffer == '1' || buffer == '0')
				columns++;
			else if (buffer == '\n')
			{
				if (lines == 1)
					std_column = columns;
				else if (columns != std_column)
				{
					ft_printf("Error1\n Not Rec Map\n");
					exit(0);
				}
				lines++;
				columns = 0;
			}
			else
			{
				ft_printf("Error\nInvalid map titles\n");
				exit(0);
			}
		}
	}
	close(fd);
	data->map.width = columns;
	data->map.height = lines;
}
