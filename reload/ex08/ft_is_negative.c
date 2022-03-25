#include <unistd.h>

void ft_putchar(char c);

void ft_is_negative(int n)
{
  int letter = 80;

  if (n < 0)
  {
    letter = 78; 
  }

  ft_putchar(letter);
}
