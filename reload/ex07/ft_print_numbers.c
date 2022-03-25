#include <unistd.h>

void ft_putchar(char c);

void ft_print_numbers(void)
{
  int zero = 48;
  int nine = 57;
  int number = zero;

  while(number <= nine)
  {
    ft_putchar(number);
    number++;
  }
}
