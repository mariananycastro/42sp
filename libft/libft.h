/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 21:13:41 by mariana           #+#    #+#             */
/*   Updated: 2022/04/15 21:48:58 by mariana          ###   ########.fr       */
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
void						ft_bzero(void *s, size_t n);
/* desaloca n espaços de s, ou seja, zera todas as posições. Em C se alocar
memória e acessar imediatamente pegará lixo, ou seja, valores que estavam lá 
na memória anteriormente */
void 						*ft_calloc(size_t nmemb, size_t size); // aloca memoria e limpa a memoria alocada
int							ft_isalnum(int c); // return se é num ou letra
int							ft_isalpha(int c); // return se é letra
int							ft_isascii(int c); // return se faz parte tabela ascii
int							ft_isdigit(int c); // return se é num
int							ft_islower(int c); // return se é letra minus
int							ft_isprint(int c); // return se é printable
int							ft_isspace(int c); // return se é space
int							ft_isupper(int c); // return se é letra maius
char						*ft_itoa(int n); // return uma string de um numero;
void						*ft_memchr(const void *s, int c, size_t n); // procura em n bytes de s pela primeira ocorrencia de c
void						*ft_memcpy(void *dest, const void *src, size_t n); // copia n data de *src p *dest
void						*ft_memset(void *s, int c, size_t n); // preenche memoria com determinado caracter;
void						ft_putchar_fd(char c, int fd); // print char c
void						ft_putendl_fd(char *s, int fd); // print string s + new line
void						ft_putnbr_fd(int n, int fd); // print number
void						ft_putstr_fd(char *s, int fd); // print string s
char						**ft_split(char const *s, char c); // divide s a cada c, e return array de string
char						*ft_strchr(const char *s, int c); // localiza c na string e retorna primeira ocorrencia;
char						*ft_strdup(char *src); // return copia de src
unsigned	int		ft_strlcat(char *dest, char *src, unsigned int size);
unsigned	int		ft_strlcpy(char *dest, char *src, unsigned int size);
int							ft_strlen(char const *str);
char						*ft_strrchr(const char *s, int c); // localiza c na string e retorna ultuma occurrencia
char						*ft_strjoin(char const *s1, char const *s2); // return nova string concatenando s1 e s2
char						*ft_strtrim(char const *s1, char const *set); // retorna s1 removendo set no inicio e final de s1 
char						*ft_substr(char const *s, unsigned int start, size_t len); // returno copia a partir do start a string s, até a len max da copia 
char						**ft_split(char const *s, char c); // divide s a cada c, e return array de string
char						*ft_itoa(int n); // return uma string de um numero;
void						ft_putchar_fd(char c, int fd); // print char c
void						ft_putendl_fd(char *s, int fd); // print string s + new line
void						ft_putstr_fd(char *s, int fd); // print string s
void						ft_putnbr_fd(int n, int fd); // print number
#endif
