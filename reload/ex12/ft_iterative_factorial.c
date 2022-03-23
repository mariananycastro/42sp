int ft_iterative_factorial(int nb)
{
  int new_number = 0;
  int i = 1;

  if (nb < 0)
    return 0;
  else if (nb == 0 || nb == 1)
    return 1;
  else
    while(i <= nb)
    {
      new_number = new_number + i;
      i++;
    }

  return new_number;
}
