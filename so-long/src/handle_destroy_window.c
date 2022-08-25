/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_destroy_window.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 21:43:37 by mariana           #+#    #+#             */
/*   Updated: 2022/08/25 11:42:16 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h> // deletar

int	handle_destroy_window(t_data *data)
{
	printf("End Game: %d\n", data->score);
	exit(0);
}
