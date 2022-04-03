/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 21:13:41 by mariana           #+#    #+#             */
/*   Updated: 2022/04/03 16:33:59 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

int							ft_atoi(char *str); // retorn int de acordo com string recebida
void						ft_bzero(void *s, size_t n); // desaloca n espaços da string s
int							ft_isalnum(int c); // return se é num ou letra
int							ft_isalpha(int c); // return se é letra
int							ft_isascii(int c); // return se faz parte tabela ascii
int							ft_isdigit(int c); // return se é num
int							ft_islower(int c); // return se é letra minus
int							ft_isprint(int c); // return se é printable
int							ft_isspace(int c); // return se é space
int							ft_isupper(int c); // return se é letra maius

// talvez refazer??
void						*ft_memcpy(void *dest, const void *src, size_t n); // copia n data de *src p *dest
char						*ft_strdup(char *src); // return copia de src
unsigned	int		ft_strlcat(char *dest, char *src, unsigned int size);
unsigned	int		ft_strlcpy(char *dest, char *src, unsigned int size);

int							ft_strlen(char const *str);
char						*ft_substr(char const *s, unsigned int start, size_t len); // returno copia a partir do start a string s, até a len max da copia 
char						*ft_strjoin(char const *s1, char const *s2); // return nova string concatenando s1 e s2
char						*ft_strtrim(char const *s1, char const *set); // retorna s1 removendo set no inicio e final de s1 
char						**ft_split(char const *s, char c); // divide s a cada c, e return array de string