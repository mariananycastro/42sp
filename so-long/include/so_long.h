/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:23:39 by mariana           #+#    #+#             */
/*   Updated: 2022/09/04 18:53:14 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include "libft.h"

# define IMG_SIZE 32
# define PLAYER 'P'
# define EXIT 'E'
# define EMPTY_SPACE '0'
# define WALL '1'
# define COLLECTIBLE 'C'

# define UP 119
# define LEFT 97
# define DOWN 115
# define RIGHT 100

# define DINO_RIGHT_PATH "./sprites/player/BlueDinoRight.xpm"
# define DINO_LEFT_PATH "./sprites/player/BlueDinoLeft.xpm"
# define WALL_PATH "./sprites/background/wall.xpm"
# define EMPTY_SPACE_PATH "./sprites/background/background.xpm"
# define CLOSED_DOOR_PATH "./sprites/background/door_closed.xpm"
# define OPENED_DOOR_PATH "./sprites/background/door_opened.xpm"
# define COLLECTIBLE_PATH "./sprites/coins/egg.xpm"

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
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
	int		player_position;
}	t_map;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_sprites	sprites;
	t_map		map;
	int			score;
	int			collectibles;
	int			movements;
}	t_data;

int		handle_keyrelease(int keysym, t_data *data);
int		handle_destroy_window(t_data *data);
void	ft_create_map(t_data *data, const char *map_file);
void	ft_validate_map(t_data *data);
int		ft_check_map_tiles(int width, int height, char *matrix, t_data *data);
int		ft_is_wall(char map_tile);
int		ft_validate_extension(const char *map_file);
void	ft_set_map_matrix(t_data *data, const char *map_file);
void	ft_get_map_size(t_data *data, const char	*map_file);
int		render(t_data *data);
void	ft_create_imgs(t_data *data);
void	ft_destroy_display(t_data *data);
void	ft_exit(t_data *data);
void	ft_error_message(int n);
void	ft_message(int n, t_data *data);
void	ft_destroy_imgs(t_data *data);
void	ft_destroy_matrix(t_data *data);
t_img	ft_create_img(t_data *data, char *imgPath);
void	ft_thanks_msg(void);
int		ft_create_window(t_data	*data);
int		ft_valid_tiles(char buffer);
void	ft_move(t_data *data, int new_position);
#endif
