#include <unistd.h>

void ft_putchar(char letter)
{
  write(1, &letter, 1);
}

void ft_putstr(char *str)
{
  while(*str)
  {
    ft_putchar(*str);
    str++;
  }
}