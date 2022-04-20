/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 22:18:04 by mariana           #+#    #+#             */
/*   Updated: 2022/04/20 08:36:42 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	size_src;
	unsigned int	size_dest;
	unsigned int	i;
	unsigned int	current_size;

	size_src = ft_strlen(src);
	size_dest = 0;
	while (dest[size_dest] && size_dest < size)
		size_dest++;
	i = 0;
	current_size = size_dest;
	if (size_dest < size)
	{
		while (current_size < size - 1 && src[i])
		{
			dest[current_size] = src[i];
			current_size++;
			i++;
		}
		dest[current_size] = '\0';
	}
	return (size_dest + size_src);
}
