/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:05:12 by mariana           #+#    #+#             */
/*   Updated: 2022/06/12 18:55:58 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

int	ft_printf(const char *phrase, ...);
int	ft_decimal(int number);
int	ft_to_base(unsigned long nbr, unsigned int base_number, char *char_base);
int	ft_string(char *str);
int	ft_pointer(unsigned long position);
#endif