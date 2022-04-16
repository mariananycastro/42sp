/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:35:17 by mariana           #+#    #+#             */
/*   Updated: 2022/04/11 17:06:21 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(int n)
{
	int	size;
	int	copy_n;

	copy_n = n;
	size = 1;
	if (n < 0)
	{
		copy_n = copy_n * -1;
		size++;
	}
	while (copy_n / 10 >= 1)
	{
		copy_n = (copy_n / 10);
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*string;
	int		i;
	int		copy_n;

	copy_n = n;
	size = ft_size(n);
	string = (char *) malloc((size + 1) * sizeof(char));
	if (!string)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		copy_n = copy_n * -1;
		string[0] = 45;
		i++;
	}
	string[size] = '\0';
	while (size > i)
	{
		string[size - 1] = (copy_n % 10) + 48;
		copy_n = copy_n / 10;
		size--;
	}
	return (string);
}
