/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_window.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 22:10:42 by mariana           #+#    #+#             */
/*   Updated: 2022/08/28 15:59:39 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_destroy_window(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	ft_destroy_display(data);
	exit(0);
}
