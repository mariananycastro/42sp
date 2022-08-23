/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:23:39 by mariana           #+#    #+#             */
/*   Updated: 2022/08/22 22:27:12 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
#include <stdlib.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <unistd.h>
#include <fcntl.h>
#include <mlx.h>

// remove list import
#include "../../ftprintf/include/ft_printf.h"

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

int	handle_keyrelease(int keysym);
int handle_destroy_window(void);
void ft_create_map(t_data *data, char *map_file);
void ft_validate_map(t_data *data, char *map_file);
int ft_check_map_titles(int width, int height, char *matrix);
int ft_is_wall(char map_title);
int ft_validate_extension(char *map_file);
void ft_set_map_matrix(t_data *data, char *map_file);
void ft_get_map_size(t_data *data, char	*map_file);
int	render(t_data *data);
void ft_create_imgs(t_data *data);
void ft_destroy(t_data *data);
void ft_exit(t_data *data);
#endif
