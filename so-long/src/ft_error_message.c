/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_message.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 14:35:54 by mariana           #+#    #+#             */
/*   Updated: 2022/08/28 15:22:56 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

# include <stdio.h>

void    ft_error_message(int n)
{
    if (n == 1)
        printf("Error1\n Not Rec Map\n");
    if (n == 2)
        printf("Error\nInvalid map titles\n");
    if (n == 3)
        printf("Error\n Invalid extension\n");
    if (n == 4)
        printf("Error\nWrong params were given");
    if (n == 5)
        printf("Error\nOps something went wrong");
}
