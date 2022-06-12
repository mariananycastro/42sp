/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:12:06 by mariana           #+#    #+#             */
/*   Updated: 2022/06/12 12:39:22 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] && s2[i] && (i + 1) < n)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
