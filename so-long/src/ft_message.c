/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_message.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 14:35:54 by mariana           #+#    #+#             */
/*   Updated: 2022/08/28 17:02:12 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdio.h>

void	ft_message(int n, t_data *data)
{
	int	missing_coins;

	missing_coins = data->collectibles - data->score;
	if (n == 1)
		printf("End Game: %d\n", data->score);
	if (n == 2)
		printf("Score: %d\n", data->score);
	if (n == 3)
		printf("Missing %d coins, can't exit game\n", missing_coins);
	if (n == 4)
		printf("Got all coins, go to exit\n");
	if (n == 5)
		printf("You died! Touched a monster\n");
}
