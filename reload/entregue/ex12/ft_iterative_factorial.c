/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastro <mariananycastro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 00:23:02 by mcastro           #+#    #+#             */
/*   Updated: 2022/03/28 00:23:03 by mcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	answer;
	int	i;

	if (nb < 0)
		return (0);
	i = 1;
	answer = 1;
	while (nb >= i)
	{
		answer = answer * nb;
		nb--;
	}
	return (answer);
}
