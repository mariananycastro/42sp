/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:09:10 by mariana           #+#    #+#             */
/*   Updated: 2022/08/21 09:36:16 by mariana          ###   ########.fr       */
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

#define GREEN_PIXEL 0xFF00
#define RED_PIXEL 0xFF0000
#define WHITE_PIXEL 0xFFFFFF

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
	t_img	img;
}	t_data;

typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
	int color;
}	t_rect;


// int	handle_no_event(void *data)
int	handle_no_event()
{
	/* This function needs to exist, but it is useless for the moment */
	return (0);
}

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

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;

    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

int render_rect(t_img *img, t_rect rect)
{
	int	i;
	int j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}

int	render(t_data *data)
{
	char	*redDino = "./sprites/RedDino.xpm";
	t_img redDinoImg;
	if (data->win_ptr == NULL)
		return (1);
	// render_background(&data->img, WHITE_PIXEL);
	// render_rect(&data->img, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100,
	// 	100, 100, GREEN_PIXEL});
	// render_rect(&data->img, (t_rect){0, 0, 500, 300, RED_PIXEL});

	redDinoImg.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, redDino, &redDinoImg.width, &redDinoImg.height);
	redDinoImg.addr = mlx_get_data_addr(redDinoImg.mlx_img, &redDinoImg.bpp,
			&redDinoImg.line_len, &redDinoImg.endian);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, redDinoImg.mlx_img, 15, 0);

	return (0);
}

int	main(void)
{
	t_data	data;
	char	*blueDino = "./sprites/BlueDino.xpm";

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window!");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	data.img.mlx_img = mlx_xpm_file_to_image(data.mlx_ptr, blueDino, &data.img.width, &data.img.height);
	
	// data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);

	/* Setup hooks */ 
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data); /* CHANGED */
	mlx_hook(data.win_ptr, DestroyNotify, NoEventMask, &handle_destroy_window, &data); /* CHANGED */

	mlx_loop(data.mlx_ptr);

	/* we will exit the loop if there's no window left, and execute this code */
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}

// "mandelbrot" "julia"

// should delete a.out, fractal.a?
// realmente tá so gerando arquivos com mudanças?
// estudar makefile

// mlx_init connection
// mlx_new_window: manage windows
// mlx_pixel_put: draw inside window
// mlx_new_image: manipulate images
// mlx_loop: handle keyboard or mouse events

// int	mlx_mouse_hook (void *win_ptr, int (*funct_ptr)(), void *param);
// int	mlx_key_hook (void *win_ptr, int (*funct_ptr)(), void *param);
// int	mlx_expose_hook (void *win_ptr, int (*funct_ptr)(), void *param);
// int	mlx_loop_hook (void *mlx_ptr, int (*funct_ptr)(), void *param);
// int	mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param);


// antes  bpp 4203296, 0, 	  -1125931344
// depois bpp 32,	    2400, 0 