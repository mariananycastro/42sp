/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_message.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 14:35:54 by mariana           #+#    #+#             */
/*   Updated: 2022/09/04 20:01:42 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_message(int n)
{
	if (n == 1)
		ft_printf("Error1\n Not Rec Map\n");
	if (n == 2)
		ft_printf("Error\nInvalid map tiles\n");
	if (n == 3)
		ft_printf("Error\n Invalid extension\n");
	if (n == 4)
		ft_printf("Error\nWrong params were given");
	if (n == 5)
		ft_printf("Error\nOps something went wrong");
}
