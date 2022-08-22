/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:23:39 by mariana           #+#    #+#             */
/*   Updated: 2022/08/22 09:18:05 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <unistd.h> // close and open
#include <fcntl.h> // close and open
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
