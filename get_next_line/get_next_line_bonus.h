/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 09:15:20 by mariana           #+#    #+#             */
/*   Updated: 2022/05/25 11:38:35 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_strchr(char *s, int c);
char	*ft_strdup(char *src);
int		ft_strlen(char *str);
char	*ft_strappend(char *s1, char *s2);
char	*get_next_line_bonus(int fd);
#endif
