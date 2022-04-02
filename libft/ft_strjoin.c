/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:15:37 by mariana           #+#    #+#             */
/*   Updated: 2022/04/02 13:41:06 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    char *new_string;
    size_t len;
    size_t i;
    size_t z;

    len = ft_strlen(s1) + ft_strlen(s2) + 1;
    new_string = (char*) malloc((len * sizeof(char)));
    if (new_string == NULL)
        return (NULL);
    i = 0;
    while (s1[i])
    {
        new_string[i] = s1[i];
        i++;
    }
    z = 0;
    while (s2[z])
    {
        new_string[i] = s2[z];
        i++;
        z++;
    }
    new_string[i] = '\0';
    return (new_string);
}
