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
