#include <unistd.h>

void ft_putchar(int letter)
{
  write(1, &letter, 1);
}

void ft_is_negative(int n)
{
  int letter = 80;

  if (n < 0)
  {
    letter = 78; 
  }

  ft_putchar(letter);
}
