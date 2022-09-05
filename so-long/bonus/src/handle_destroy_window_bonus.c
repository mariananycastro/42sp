/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_destroy_window_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 21:43:37 by mariana           #+#    #+#             */
/*   Updated: 2022/09/04 19:22:07 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	handle_destroy_window_bonus(t_data *data)
{
	ft_message_bonus(1, data);
	ft_destroy_imgs_bonus(data);
	return (0);
}
