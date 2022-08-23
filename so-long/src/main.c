/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 10:13:34 by mariana           #+#    #+#             */
/*   Updated: 2022/08/22 21:19:09 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h> // printf substituir pela minha func

int handle_destroy_window(void)
{
	exit(0);
}

int	handle_keyrelease(int keysym)
{
	if (keysym == XK_Escape)
		exit(0);
	return (0);
}

void ft_destroy(t_data *data)
{
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data->map.matrix);
}

void ft_exit(t_data *data)
{
	free(data->map.matrix);
	exit(0);
}

int	render(t_data *data)
{
	size_t	index;
	size_t	x;
	size_t	y;
	size_t	max_x;
	size_t	max_y;

	index = 0;
	x = 0;
	y = 0;
	max_x = data->map.width * IMG_SIZE;
	max_y = data->map.height * IMG_SIZE;

	while(y < max_y)
	{
		while(x < max_x)
		{
			if (data->map.matrix[index] == '1') // wall
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->sprites.wall.mlx_img, x, y);
			if (data->map.matrix[index] == 'P') // player
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->sprites.player.mlx_img, x, y);
			}
			if (data->map.matrix[index] == '0') // empty_space
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->sprites.empty_space.mlx_img, x, y);
			if (data->map.matrix[index] == 'C') // collectible
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->sprites.collectible.mlx_img, x, y);
			if (data->map.matrix[index] == 'E') // exit
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->sprites.exit.mlx_img, x, y);
			x = x + IMG_SIZE;
			index++;
		}
		y = y + IMG_SIZE;
		x = 0;
	}
	return (0);
}

void ft_create_imgs(t_data *data)
{
	char	*blueDinoPath = "./sprites/player/RedDino.xpm";
	char	*wallPath = "./sprites/background/wall.xpm";
	char	*emptySpacePath = "./sprites/background/background.xpm";
	char	*exitPath = "./sprites/background/window.xpm";
	char	*diamondPath = "./sprites/coins/diamond.xpm";
	t_img blueDinoImg;
	t_img wallImg;
	t_img emptySpaceImg;
	t_img exitImg;
	t_img collectibleImg;

	blueDinoImg.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, blueDinoPath, &blueDinoImg.width, &blueDinoImg.height);
	blueDinoImg.addr = mlx_get_data_addr(blueDinoImg.mlx_img, &blueDinoImg.bpp, &blueDinoImg.line_len, &blueDinoImg.endian);

	wallImg.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, wallPath, &wallImg.width, &wallImg.height);
	wallImg.addr = mlx_get_data_addr(wallImg.mlx_img, &wallImg.bpp, &wallImg.line_len, &wallImg.endian);

	emptySpaceImg.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, emptySpacePath, &emptySpaceImg.width, &emptySpaceImg.height);
	emptySpaceImg.addr = mlx_get_data_addr(emptySpaceImg.mlx_img, &emptySpaceImg.bpp, &emptySpaceImg.line_len, &emptySpaceImg.endian);

	exitImg.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, exitPath, &exitImg.width, &exitImg.height);
	exitImg.addr = mlx_get_data_addr(exitImg.mlx_img, &exitImg.bpp, &exitImg.line_len, &exitImg.endian);

	collectibleImg.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, diamondPath, &collectibleImg.width, &collectibleImg.height);
	collectibleImg.addr = mlx_get_data_addr(collectibleImg.mlx_img, &collectibleImg.bpp, &collectibleImg.line_len, &collectibleImg.endian);

	data->sprites.player = blueDinoImg;
	data->sprites.wall = wallImg;
	data->sprites.empty_space = emptySpaceImg;
	data->sprites.exit = exitImg;
	data->sprites.collectible = collectibleImg;
}

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
					printf("Not Rec Map Error1\n");
					exit(0);
				}
				lines++;
				columns = 0;
			}
			else
			{
				printf("Invalid title Error\n");
				exit(0);
			}
		}
	}
	close(fd);
	data->map.width = columns;
	data->map.height = lines;
}

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

int ft_is_wall(char map_title)
{
	char wall;

	wall = '1';
	return (map_title == wall);
}

int ft_check_map(int width, int height, char *matrix)
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


void ft_validate_map(t_data *data, char *map_file)
{
	if (ft_validate_extension(map_file) != 0)
	{
		printf("Invalid extension Error\n");
		ft_exit(data);
	}
	if (ft_check_map(data->map.width, data->map.height, data->map.matrix) != 0)
	{
		printf("Invalid map Error\n");
		ft_exit(data);
	}
}

void ft_create_map(t_data *data, char *map_file)
{
	ft_get_map_size(data, map_file);
	ft_set_map_matrix(data, map_file);
	ft_validate_map(data, map_file);
}

int	main(void)
{
	t_data	data;
	int		window_width;
	int		window_height;
	char	*map_file = "./maps/map1.ber";

	ft_create_map(&data, map_file);
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	window_width = data.map.width * IMG_SIZE;
	window_height = data.map.height * IMG_SIZE;
	data.win_ptr = mlx_new_window(data.mlx_ptr, window_width, window_height, "So long!");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	ft_create_imgs(&data);

	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data);
	mlx_hook(data.win_ptr, DestroyNotify, NoEventMask, &handle_destroy_window, &data);
	mlx_loop(data.mlx_ptr);
	ft_destroy(&data);
}
