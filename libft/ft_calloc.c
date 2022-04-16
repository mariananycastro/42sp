/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 10:42:49 by mariana           #+#    #+#             */
/*   Updated: 2022/04/15 16:00:46 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_calloc(size_t nmemb, size_t size)
{
    void *alloc_nmemb;

    alloc_nmemb = (void *) malloc (nmemb * size);
    if (alloc_nmemb == NULL)
	    return (NULL);
    ft_bzero(alloc_nmemb, nmemb * size);
    return (alloc_nmemb);
}
