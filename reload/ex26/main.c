#include <stdio.h>
#include "ft_count_if.c"

int ft_eq(char *str)
{
  if (str == "222")
    return 1;
  else
    return 0;
}

int main()
{
  char *str_array[][3] = {"111", "222", "333", "444"};
  printf("%d\n", ft_count_if(&str_array[0][0], ft_eq));
}