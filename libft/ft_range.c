/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 00:37:13 by mcastro           #+#    #+#             */
/*   Updated: 2022/03/31 22:07:49 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_range(int min, int max)
{
	int	*answer;
	int	i;

	if (min >= max)
		return ((void *) 0);
	answer = (int *) malloc((max - min) * sizeof(int));
	i = 0;
	while (min < max)
	{
		answer[i] = min;
		i++;
		min++;
	}
	return (answer);
}
