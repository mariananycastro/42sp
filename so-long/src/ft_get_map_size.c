/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 22:11:46 by mariana           #+#    #+#             */
/*   Updated: 2022/08/28 17:01:42 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_not_rec_error(void)
{
	ft_error_message(1);
	exit(0);
}

void	ft_invalid_title_error(void)
{
	ft_error_message(2);
	exit(0);
}

void	ft_read_file(int fd, t_data *data)
{
	char	buffer;
	int		columns;

	columns = 0;
	while (read(fd, &buffer, 1) != 0)
	{
		if (buffer == COLLECTIBLE || buffer == EXIT || buffer == PLAYER
			|| buffer == WALL || buffer == EMPTY_SPACE || buffer == MONSTER)
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
			ft_invalid_title_error();
	}
}

void	ft_get_map_size(t_data *data, const char	*map_file)
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
