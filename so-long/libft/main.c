/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 19:04:46 by mariana           #+#    #+#             */
/*   Updated: 2022/09/03 16:17:35 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

int	main(void)
{
	int	x;
	int	y;

	x = 'c';
	y = 'b';
	x = ft_printf(" NULL %d NULL ", 'a');
	y = printf(" NULL %d NULL ", 'a');
	ft_printf("x = %d \n", x);
	ft_printf("y = %d\n", y);
	ft_printf("%d", ft_isalpha(48));
	return (0);
}
