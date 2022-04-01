/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 21:13:41 by mariana           #+#    #+#             */
/*   Updated: 2022/03/31 22:27:09 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int							ft_atoi(char *str);
int							ft_count_if(char **tab, int (*f)(char*));
void						ft_foreach(int *tab, int length, void (*f)(int));
void						ft_ft(int *nbr);
int							ft_is_prime(int nb);
void						ft_print(int argc, char *argv[ ]);
void						ft_putchar(char c);
void						ft_putnbr_base(int nbr, char *base);
void						ft_putstr(char *str);
int							*ft_range(int min, int max);
int							ft_recursive_factorial(int nb);
int							ft_recursive_power(int nb, int power);
void						ft_rev_int_tab(int *tab, int size);
void						ft_sort_int_tab(int *tab, int size);
int							ft_sqrt(int nb);
int							ft_strcmp(char *s1, char *s2);
char						*ft_strcpy(char *dest, char *src);
char						*ft_strdup(char *src);
unsigned	int		ft_strlcat(char *dest, char *src, unsigned int size);
unsigned	int		ft_strlcpy(char *dest, char *src, unsigned int size);
int							ft_strlen(char *str);
char						*ft_strstr(char *str, char *to_find);
void						ft_swap(int *a, int *b);
#endif