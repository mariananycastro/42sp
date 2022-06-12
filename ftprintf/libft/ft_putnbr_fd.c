/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 20:13:46 by mariana           #+#    #+#             */
/*   Updated: 2022/06/12 18:59:10 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	copy_n;

	copy_n = n;
	if (copy_n < 0)
	{
		ft_putchar_fd('-', fd);
		copy_n = copy_n * -1;
	}
	if (copy_n >= 10)
		ft_putnbr_fd((copy_n / 10), fd);
	ft_putchar_fd((copy_n % 10 + 48), fd);
}
