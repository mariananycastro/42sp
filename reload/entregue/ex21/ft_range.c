/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastro <mariananycastro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 00:37:13 by mcastro           #+#    #+#             */
/*   Updated: 2022/03/28 00:37:15 by mcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
