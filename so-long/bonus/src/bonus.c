/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 10:13:34 by mariana           #+#    #+#             */
/*   Updated: 2022/09/04 19:28:15 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_create_game(const char *file_name)
{
	t_data	data;

	ft_create_map_bonus(&data, file_name);
	ft_create_window_bonus(&data);
	ft_create_imgs_bonus(&data);
	data.score = 0;
	data.movements = 0;
	ft_message_bonus(2, &data);
	ft_message_bonus(5, &data);
	mlx_loop_hook(data.mlx_ptr, &render_bonus, &data);
	mlx_hook(
		data.win_ptr,
		KeyRelease, KeyReleaseMask,
		&handle_keyrelease_bonus,
		&data
		);
	mlx_hook(
		data.win_ptr,
		DestroyNotify,
		NoEventMask,
		&handle_destroy_window_bonus,
		&data
		);
	mlx_loop(data.mlx_ptr);
	ft_exit_bonus(&data);
}

int	main(int argc, const char *argv[])
{
	ft_thanks_msg_bonus();
	if (argc == 2)
		ft_create_game(argv[1]);
	else
		ft_error_message_bonus(4);
	return (0);
}
