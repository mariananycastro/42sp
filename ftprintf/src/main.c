/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 19:04:46 by mariana           #+#    #+#             */
/*   Updated: 2022/06/12 19:05:35 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "../include/ft_printf.h"

int	main(void)
{
	int	x;
	int	y;

	x = ft_printf(" NULL %s NULL ", NULL);
	y = printf(" NULL %s NULL ", NULL);
	printf("x = %d \n", x);
	printf("y = %d\n", y);
	return (0);
}
