/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:29:25 by mariana           #+#    #+#             */
/*   Updated: 2022/05/12 15:29:45 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
