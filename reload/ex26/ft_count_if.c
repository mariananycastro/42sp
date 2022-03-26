#include <stdio.h>
// • Create a function ft_count_if which will return the number of elements of the
// array that return 1, passed to the function f.
// • The array will be delimited by 0.

int ft_count_if(char **tab, int(*f)(char*))
{
  int i = 0;
  int answer = 0;

  while (tab[i])
  {
    if (f(tab[i]) == 1)
      answer++;
    i++;
  }
  return (answer);
}
