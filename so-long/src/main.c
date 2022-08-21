/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 10:13:34 by mariana           #+#    #+#             */
/*   Updated: 2022/08/21 16:12:58 by mariana          ###   ########.fr       */
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
#define IMG_SIZE 32

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
	char	*matrix;
}	t_map;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_sprites	sprites;
	t_map		map;
}	t_data;

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (i < n)
	{
		*(char *)(s + i) = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	max_test;

	max_test = nmemb * size;
	if (nmemb != 0 && (max_test / nmemb != size))
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

// ===============

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

// 65362	up		XK_Up
// 65364	down	XK_Down
// 65363	right	XK_Right
// 65361	left	XK_Left

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
	char	*blueDinoPath = "./sprites/player/BlueDino.xpm";
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
	char	*map_matrix;
	size_t	matrix_size;
	char	buffer;
	int		fd;
	int		index;

	matrix_size = data->map.height * data->map.width;
	map_matrix = calloc(matrix_size, sizeof(char));

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

	// size_t x = 0;
	// while (x < matrix_size)
	// {
		// 	printf("%d ", data->map.matrix[x]);
		// 	x++;
	// }
}

void ft_create_map(t_data *data)
{
	ft_get_map_size(data);
	ft_set_map_matrix(data);
}

int	main(void)
{
	t_data	data;
	int		window_width;
	int		window_height;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	ft_create_map(&data);
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
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
