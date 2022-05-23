/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:36:42 by mariana           #+#    #+#             */
/*   Updated: 2022/05/22 22:10:17 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

void	*ft_memcpy(void *dest, const void *src, size_t n);
// localiza c na string e retorna primeira ocorrencia;
int		ft_strchr(char *s, int c);
// return copia de src
char	*ft_strdup(char *src);
int		ft_strlen(char *str);
char	*ft_strappend(char *s1, char *s2);
char	*get_next_line(int fd);
#endif
