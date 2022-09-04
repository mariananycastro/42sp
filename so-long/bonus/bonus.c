/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 10:13:34 by mariana           #+#    #+#             */
/*   Updated: 2022/09/04 16:37:22 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_create_game(const char *file_name)
{
	t_data	data;

	ft_create_map(&data, file_name);
	ft_create_window(&data);
	ft_create_imgs(&data);
	data.score = 0;
	data.movements = 0;
	ft_message(2, &data);
	ft_message(5, &data);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(
		data.win_ptr,
		KeyRelease, KeyReleaseMask,
		&handle_keyrelease,
		&data
		);
	mlx_hook(
		data.win_ptr,
		DestroyNotify,
		NoEventMask,
		&handle_destroy_window,
		&data
		);
	mlx_loop(data.mlx_ptr);
	ft_exit(&data);
}

int	main(int argc, const char *argv[])
{
	ft_thanks_msg();
	if (argc == 2)
		ft_create_game(argv[1]);
	else
		ft_error_message(4);
	return (0);
}
