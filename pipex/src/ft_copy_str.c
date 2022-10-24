/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:44:33 by mariana           #+#    #+#             */
/*   Updated: 2022/10/24 16:24:47 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_copy_str(char *src)
{
	int		size;
	int		i;
	char	*answer;

	size = 0;
	size = ft_strlen(src);
	if (size == 0)
		return (NULL);
	i = 0;
	answer = (char *) malloc(sizeof(char) * size + 1);
	while (src[i])
	{
		answer[i] = src[i];
		i++;
	}
	answer[i] = '\0';
	return (answer);
}
