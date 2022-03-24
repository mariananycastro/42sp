int ft_sqrt(int nb)
{
  int sqrt = 2;
  
  if (nb <= 0)
    return 0;
  else
  {
    while (sqrt <= nb/2)
    {
      if (sqrt * sqrt == nb)
        return sqrt;
      else
       sqrt++;
    }
    return 0;
  }
}