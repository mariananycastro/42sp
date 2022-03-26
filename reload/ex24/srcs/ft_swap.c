#include "../includes/header.h"

void ft_swap(char **a, char **b)
{
  int temp;

  temp = **a;
  **a = **b;
  **b = temp; 
}