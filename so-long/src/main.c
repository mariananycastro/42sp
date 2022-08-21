/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 10:13:34 by mariana           #+#    #+#             */
/*   Updated: 2022/08/21 13:03:09 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <unistd.h> // close and open
#include <fcntl.h> // close and open

#include <stdio.h> // printf

#define MLX_ERROR 1
#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 300

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; // bits per pixel
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_sprites
{
	t_img	player;
	t_img	wall;
	t_img	empty_space;
	t_img	collectible;
	t_img	exit;
}	t_sprites;

typedef struct s_map
{
	int		width;
	int		height;
}	t_map;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_sprites	sprites;
	t_map		map;
}	t_data;

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

int	render(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->sprites.player.mlx_img, 32, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->sprites.wall.mlx_img, 0, 0);

	return (0);
}

void ft_create_imgs(t_data *data)
{
	char	*blueDino = "./sprites/player/BlueDino.xpm";
	char	*title1 = "./sprites/background/titleBack1.xpm";
	t_img blueDinoImg;
	t_img title1Img;

	blueDinoImg.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, blueDino, &blueDinoImg.width, &blueDinoImg.height);
	blueDinoImg.addr = mlx_get_data_addr(blueDinoImg.mlx_img, &blueDinoImg.bpp, &blueDinoImg.line_len, &blueDinoImg.endian);

	title1Img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, title1, &title1Img.width, &title1Img.height);
	title1Img.addr = mlx_get_data_addr(title1Img.mlx_img, &title1Img.bpp, &title1Img.line_len, &title1Img.endian);
	data->sprites.player = blueDinoImg;
	data->sprites.wall = title1Img;
}

void ft_get_map_size(t_data *data)
{
	char	*map_file = "./maps/map1.ber";
	char	buffer;
	int		fd;
	int		lines;
	int		columns;

	lines = 1;
	columns = 0;
	fd = open(map_file, O_RDONLY);
	if (fd != -1)
	{
		while (read(fd, &buffer, 1) != 0)
		{
			if (buffer != '\n' && lines == 1)
				columns++;
			if (buffer == '\n')
				lines++;
		}
	}
	close(fd);
	data->map.width = columns;
	data->map.height = lines;
}

void ft_set_map_matrix(t_data *data)
{
	char	*map_file = "./maps/map1.ber";
	int		map_matrix[data->map.height][data->map.width];
	char	buffer;
	int		fd;
	int		line;
	int		column;

	line = 0;
	column = 0;
	fd = open(map_file, O_RDONLY);
	if (fd != -1)
	{
		while (read(fd, &buffer, 1) != 0)
		{
			if(buffer != '\n')
			{
				map_matrix[line][column] = buffer;
				column++;
			}
			else
			{
				line++;
				column = 0;
			}
		}
	}
	close(fd);
}

void ft_create_map(t_data *data)
{
	ft_get_map_size(data);
	ft_set_map_matrix(data);
}

int	main(void)
{
	t_data		data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window!");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	ft_create_imgs(&data);
	ft_create_map(&data);

	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data);
	mlx_hook(data.win_ptr, DestroyNotify, NoEventMask, &handle_destroy_window, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
