#include <stdio.h>
#include <string.h>

#include "./ex06/ft_print_alphabet.c"
// #include "./ex07/ft_print_numbers.c"
// #include "./ex08/ft_is_negative.c"
#include "./ex09/ft_ft.c"
#include "./ex10/ft_swap.c"
#include "./ex11/ft_div_mod.c"
#include "./ex12/ft_iterative_factorial.c"
#include "./ex13/ft_recursive_factorial.c"
#include "./ex14/ft_sqrt.c"
// #include "./ex15/ft_putstr.c"
#include "./ex16/ft_strlen.c"
#include "./ex17/ft_strcmp.c"
#include "./ex20/ft_strdup.c"
#include "./ex21/ft_range.c"
#include "./ex22/ft_abs.h"

// ex18
// gcc -Wall -Werror -Wextra ft_print_params.c && ./a.out test1 test2 test3

// ex19
// gcc -Wall -Werror -Wextra ft_sort_params.c && ./a.out teste1 abc teste0 

void ft_putchar(char letter)
{
  write(1, &letter, 1);
}

int main()
{
  printf("\n--------------------------------------------\n");
  printf("ex22=%d\n", ABS(-2));

  printf("\n--------------------------------------------\n");
  int *range;
  int min = 1;
  int max = 5;
  range = ft_range(min, max);
  int i = 0;
  printf("[min.. max-1] ex21\n");
  printf("[min=%d, max=%d]\n", min, max);
  while(range[i])
  {
    printf("%d", range[i]);
    i++;
  }

  printf("\n--------------------------------------------\n");
  printf("new var(copy) ex20\n");

  char str20[] = "0125";
  char *new_char = ft_strdup(str20);
  printf("ex20=%s\n", new_char);


  printf("\n--------------------------------------------\n");
  printf("copy ex17\n");

  char str1[] = "0125";
  char str2[] = "01234";

  printf("ex17=%d\n", ft_strcmp(str1, str2));
  printf("ex17=%d\n", strcmp(str1, str2));

  printf("\n--------------------------------------------\n");
  printf("leng str ex16\n");

  // int ex16 = ft_strlen(string);
  // printf("ex16=%d=9\n", ex16);

  printf("\n--------------------------------------------\n");
  printf("print string ex15\n");

  // char string[10] = "123456789"; 
  // printf("ex15\n");
  // ft_putstr(string);

  printf("\n--------------------------------------------\n");
  printf("ex14\n");

  int sqr = 2147395600; //46340
  int ex14 = ft_sqrt(sqr);
  printf("sqrt ex14=%d\n", ex14);

  printf("\n--------------------------------------------\n");
  printf("ex13\n");

  int nb13 = 5;
  int ex13 = ft_recursive_factorial(nb13);
  printf("fatorial ex13=%d\n", ex13);

  printf("\n--------------------------------------------\n");
  printf("ex12\n");

  int nb = 5;
  int ex12 = ft_iterative_factorial(nb);
  printf("fatorial ex12=%d\n", ex12);

  printf("\n--------------------------------------------\n");
  printf("ex11\n");

  int divisor = 10;
  int dividendo = 2;
  int division;
  int remainder;
  int *div = &division;
  int *mod = &remainder;

  ft_div_mod(divisor, dividendo, div, mod);
  printf("dividendo/remainder after %d=5 e %d=0\n", *div, *mod);

  printf("\n--------------------------------------------\n");
  printf("ex10\n");

  int x = 1;
  int y = 2;
  int *a = &x;
  int *b = &y;
  printf("number before %d e %d\n", x, y);
  ft_swap(a, b);
  printf("number after %d e %d\n", x, y);

  printf("\n--------------------------------------------\n");
  printf("ex09\n");

	int number = 2;
	int *nbr = &number;
  printf("number before %d\n", number);
  ft_ft(nbr);
  printf("number after %d\n", number);

  printf("\n--------------------------------------------\n");

  ft_print_alphabet();
  // ft_print_numbers();
  // ft_is_negative(2);
}
