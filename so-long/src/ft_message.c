/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_message.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 14:35:54 by mariana           #+#    #+#             */
/*   Updated: 2022/09/03 16:15:43 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_message(int n, t_data *data)
{
	int	missing_coins;

	missing_coins = data->collectibles - data->score;
	if (n == 1)
		ft_printf("End Game: %d\n", data->score);
	if (n == 2)
		ft_printf("Score: %d\n", data->score);
	if (n == 3)
		ft_printf("Missing %d coins, can't exit game\n", missing_coins);
	if (n == 4)
		ft_printf("Got all coins, go to exit\n");
	if (n == 5)
		ft_printf("You died! Touched a monster\n");
}
