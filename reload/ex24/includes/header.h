#include <stdio.h>
#include <unistd.h>

#ifndef HEADER_H
# define HEADER_H

typedef	struct s_point
{
	int x;
	int y;
} t_point;

#endif

void ft_putchar(char c);
void ft_putstr(char *str);
int ft_strcmp(char *s1, char *s2);
int ft_strlen(char *str);
void ft_swap(char **a, char **b);
void set_point(t_point *point);


