/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 10:13:34 by mariana           #+#    #+#             */
/*   Updated: 2022/08/25 10:09:02 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_set_map_matrix(t_data *data, char *map_file)
{
	char	*map_matrix;
	size_t	matrix_size;
	char	buffer;
	int		fd;
	int		index;

	matrix_size = data->map.height * data->map.width;
	map_matrix = ft_calloc(matrix_size, sizeof(char));

	index = 0;
	fd = open(map_file, O_RDONLY);
	if (fd != -1)
	{
		while (read(fd, &buffer, 1) != 0)
		{
			if(buffer != '\n')
			{
				map_matrix[index] = buffer;
				if (buffer == 'P')
					data->map.player_position = index;
				index++;
			}
		}
	}
	close(fd);
	data->map.matrix = map_matrix;
}

int ft_validate_extension(char *map_file)
{
	int	extention_size;
	size_t path_size;

	extention_size = 4;
	path_size = ft_strlen(map_file);
	return (ft_memcmp(&map_file[path_size - extention_size], ".ber", extention_size));
}

int	ft_create_window(t_data	*data)
{
	int		width;
	int		height;

	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (MLX_ERROR);
	width = data->map.width * IMG_SIZE;
	height = data->map.height * IMG_SIZE;
	data->win_ptr = mlx_new_window(data->mlx_ptr, width, height, "So long!");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return (MLX_ERROR);
	}
	return (0);
}

int	main(void)
{
	t_data	data;
	char	*map_file = "./maps/map1.ber";

	ft_create_map(&data, map_file);
	ft_create_window(&data);
	ft_create_imgs(&data);
	data.score = 0;
	ft_printf("Score: %d\n", data.score);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(
		data.win_ptr,
		KeyRelease, KeyReleaseMask,
		&handle_keyrelease,
		&data
		);
	mlx_hook(
		data.win_ptr,
		DestroyNotify,
		NoEventMask,
		&handle_destroy_window,
		&data
		);
	mlx_loop(data.mlx_ptr);
	ft_destroy(&data);
}
