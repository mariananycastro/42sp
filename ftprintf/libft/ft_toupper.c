/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:23:29 by mariana           #+#    #+#             */
/*   Updated: 2022/06/12 12:39:22 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/libft.h"

int	ft_toupper(int c)
{
	if (ft_islower(c))
		return (c - 32);
	return (c);
}