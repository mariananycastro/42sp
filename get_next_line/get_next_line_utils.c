/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:29:55 by mariana           #+#    #+#             */
/*   Updated: 2022/05/12 20:02:25 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (i < n)
	{
		*(char *)(s + i) = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*alloc_nmemb;
	long int	copy_size;
	long int	copy_nmemb;

	copy_size = size;
	copy_nmemb = nmemb;
	if (copy_nmemb <= 0 || copy_size <= 0)
		return (NULL);
	alloc_nmemb = malloc (nmemb * size);
	if (!alloc_nmemb)
		return (NULL);
	ft_bzero(alloc_nmemb, nmemb * size);
	return (alloc_nmemb);
}

unsigned	int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	int				answer;

    answer = 0;
	answer = ft_strlen(src);
	if (size == 0)
		return (answer);
	i = 0;
	while (src[i] && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (answer);
}

int	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
