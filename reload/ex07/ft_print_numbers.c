#include <unistd.h>

void ft_putchar(int number)
{
  write(1, &number, 1);
}

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
