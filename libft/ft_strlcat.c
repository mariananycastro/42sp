/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 22:18:04 by mariana           #+#    #+#             */
/*   Updated: 2022/03/31 22:18:32 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int				size_src;
	int				size_dest;
	unsigned int	i;
	unsigned int	current_size;

	if (size == 0)
		return (0);
	size_dest = 0;
	while (dest[size_dest])
		size_dest++;
	size_src = 0;
	while (src[size_src])
		size_src++;
	i = 0;
	current_size = size_dest;
	while (current_size <= size - 2 && src[i])
	{
		dest[current_size] = src[i];
		current_size++;
		i++;
	}
	dest[size - 1] = '\0';
	return (size_dest + size_src);
}
