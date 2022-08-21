/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 10:13:34 by mariana           #+#    #+#             */
/*   Updated: 2022/08/21 10:20:15 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <X11/keysym.h>
#include <X11/X.h>

# define MLX_ERROR 1
# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

int handle_destroy_window()
{
	exit(0);
}

int	handle_keyrelease(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}


int	render()
{
	// char	*redDino = "./sprites/player/RedDino.xpm";
	// t_img redDinoImg;
	// if (data->win_ptr == NULL)
	// 	return (1);
	// // render_background(&data->img, WHITE_PIXEL);
	// // render_rect(&data->img, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100,
	// // 	100, 100, GREEN_PIXEL});
	// // render_rect(&data->img, (t_rect){0, 0, 500, 300, RED_PIXEL});

	// redDinoImg.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, redDino, &redDinoImg.width, &redDinoImg.height);
	// redDinoImg.addr = mlx_get_data_addr(redDinoImg.mlx_img, &redDinoImg.bpp,
	// 		&redDinoImg.line_len, &redDinoImg.endian);
	// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, redDinoImg.mlx_img, 15, 0);

	return (0);
}

int	main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window!");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data); /* CHANGED */
	mlx_hook(data.win_ptr, DestroyNotify, NoEventMask, &handle_destroy_window, &data); /* CHANGED */

	mlx_loop(data.mlx_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}