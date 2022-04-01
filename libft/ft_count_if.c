/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 01:32:52 by mcastro           #+#    #+#             */
/*   Updated: 2022/03/31 22:02:15 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_if(char **tab, int (*f)(char*))
{
	int	i;
	int	answer;

	i = 0;
	answer = 0;
	while (tab[i])
	{
		if (f(tab[i]) == 1)
			answer++;
		i++;
	}
	return (answer);
}
