/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 10:13:34 by mariana           #+#    #+#             */
/*   Updated: 2022/08/28 14:32:16 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_set_map_matrix(t_data *data, const char *map_file)
{
	size_t	matrix_size;
	char	buffer;
	int		fd;
	int		index;

	matrix_size = (data->map.height * data->map.width) + 1;
	data->map.matrix = ft_calloc(matrix_size, sizeof(char));
	index = 0;
	fd = open(map_file, O_RDONLY);
	if (fd != -1)
	{
		while (read(fd, &buffer, 1) != 0)
		{
			if (buffer != '\n')
			{
				data->map.matrix[index] = buffer;
				if (buffer == PLAYER)
					data->map.player_position = index;
				index++;
			}
		}
	}
	data->map.matrix[index] = '\0';
	close(fd);
}

int ft_validate_extension(const char *map_file)
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
	{
		free(data->map.matrix);
		return (MLX_ERROR);
	}
	width = data->map.width * IMG_SIZE;
	height = data->map.height * IMG_SIZE;
	data->win_ptr = mlx_new_window(data->mlx_ptr, width, height, "So long!");
	if (data->win_ptr == NULL)
	{
		ft_destroy(data);
		return (MLX_ERROR);
	}
	return (0);
}

void	ft_create_game(const char *file_name)
{
	t_data	data;

	ft_create_map(&data, file_name);
	ft_create_window(&data);
	// ft_create_imgs(&data);
	// data.score = 0;
	// ft_printf("Score: %d\n", data.score);
	// ft_message(2, &data);
	// mlx_loop_hook(data.mlx_ptr, &render, &data);
	// mlx_hook(
	// 	data.win_ptr,
	// 	KeyRelease, KeyReleaseMask,
	// 	&handle_keyrelease,
	// 	&data
	// 	);
	// mlx_hook(
	// 	data.win_ptr,
	// 	DestroyNotify,
	// 	NoEventMask,
	// 	&handle_destroy_window,
	// 	&data
	// 	);
	// mlx_loop(data.mlx_ptr);
	ft_destroy_window(&data);
}

int	main(int argc, const char *argv[])
{
	if (argc == 2)
		ft_create_game(argv[1]);
	else
		ft_printf("Wrong params were given");
	// ft_error_message(4);
	return (0);
}
