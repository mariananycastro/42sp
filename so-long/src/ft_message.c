/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_message.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 14:35:54 by mariana           #+#    #+#             */
/*   Updated: 2022/08/28 16:04:22 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdio.h>

void	ft_message(int n, t_data *data)
{
	if (n == 1)
		printf("End Game: %d\n", data->score);
	if (n == 2)
		printf("Score: %d\n", data->score);
}
