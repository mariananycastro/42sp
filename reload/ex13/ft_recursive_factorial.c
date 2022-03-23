int ft_recursive_factorial(int nb)
{
  int new_number;
  new_number = nb;

  if (nb < 0)
    return 0;
  else if (nb == 0 || nb == 1)
    return 1;
  else
    return new_number = new_number + ft_iterative_factorial(nb - 1);
}
