/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastro <mariananycastro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 00:32:11 by mcastro           #+#    #+#             */
/*   Updated: 2022/03/28 00:34:24 by mcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_length(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*copy;
	int		i;
	int		size;

	size = ft_length(src);
	copy = (char *) malloc((size) * sizeof(char));
	if (copy == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	return (copy);
}
