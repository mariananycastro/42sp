/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_size_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 22:11:46 by mariana           #+#    #+#             */
/*   Updated: 2022/09/04 19:23:18 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_not_rec_error(void)
{
	ft_error_message_bonus(1);
	exit(0);
}

void	ft_invalid_tile_error(void)
{
	ft_error_message_bonus(2);
	exit(0);
}

void	ft_read_file(int fd, t_data *data)
{
	char	buffer;
	int		columns;

	columns = 0;
	while (read(fd, &buffer, 1) != 0)
	{
		if (ft_valid_tiles_bonus(buffer) == 1)
			columns++;
		else if (buffer == '\n')
		{
			if (data->map.height == 1)
				data->map.width = columns;
			else if (columns != data->map.width)
				ft_not_rec_error();
			data->map.height++;
			columns = 0;
		}
		else
			ft_invalid_tile_error();
	}
}

void	ft_get_map_size_bonus(t_data *data, const char	*map_file)
{
	int		fd;

	data->map.height = 1;
	data->map.width = 0;
	fd = open(map_file, O_RDONLY);
	if (fd != -1)
	{
		ft_read_file(fd, data);
	}
	close(fd);
}
