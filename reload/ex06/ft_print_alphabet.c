#include <unistd.h>

void ft_putchar(char c);

void ft_print_alphabet(void)
{
  int a = 97;
  int z = 122;
  int letter = a;

  while(letter <= z)
  {
    ft_putchar(letter);
    letter++;
  }
}
