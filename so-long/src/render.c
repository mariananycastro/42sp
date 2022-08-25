/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 22:11:04 by mariana           #+#    #+#             */
/*   Updated: 2022/08/24 22:13:22 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_img_to_window(t_data *data, void *sprite, size_t x, size_t y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, sprite, x, y);
}

void	ft_put_img(t_data *data, char position, int x, int y)
{
	void	*wall_img;
	void	*player_img;
	void	*empty_space_img;
	void	*collectible_img;
	void	*exit_img;

	wall_img = data->sprites.wall.mlx_img;
	player_img = data->sprites.player.mlx_img;
	empty_space_img = data->sprites.empty_space.mlx_img;
	collectible_img = data->sprites.collectible.mlx_img;
	exit_img = data->sprites.exit.mlx_img;
	if (position == WALL)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, wall_img, x, y);
	if (position == PLAYER)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, player_img, x, y);
	if (position == EMPTY_SPACE)
		mlx_put_image_to_window(
			data->mlx_ptr, data->win_ptr, empty_space_img, x, y);
	if (position == COLLECTIBLE)
		mlx_put_image_to_window(
			data->mlx_ptr, data->win_ptr, collectible_img, x, y);
	if (position == EXIT)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, exit_img, x, y);
}

int	render(t_data *data)
{
	int	index;
	int	x;
	int	y;

	index = 0;
	x = 0;
	y = 0;
	while (y < (data->map.height * IMG_SIZE))
	{
		while (x < (data->map.width * IMG_SIZE))
		{
			ft_put_img(data, data->map.matrix[index], x, y);
			x = x + IMG_SIZE;
			index++;
		}
		y = y + IMG_SIZE;
		x = 0;
	}
	return (0);
}
