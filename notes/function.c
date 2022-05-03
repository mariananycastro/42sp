void fun(int a)
{
    printf("Value of a is %d\n", a);
}

int main()
{
// fun_ptr is a pointer to function fun() 
// function pointer points to code, not data
// do not allocate de-allocate memory using function pointers
    void (*fun_ptr)(int) = &fun;
    (*fun_ptr)(10);

    // ||

    void (*fun_ptr)(int) = fun;
    fun_ptr(10);

    return 0;
}

void add(int a, int b)
{
    printf("Addition is %d\n", a+b);
}
void subtract(int a, int b)
{
    printf("Subtraction is %d\n", a-b);
}
void multiply(int a, int b)
{
    printf("Multiplication is %d\n", a*b);
}


int main()
{
    // fun_ptr_arr is an array of function pointers
    void (*fun_ptr_arr[])(int, int) = {add, subtract, multiply};
    unsigned int ch, a = 15, b = 10;
  
    printf("Enter Choice: 0 for add, 1 for subtract and 2 "
            "for multiply\n");
    scanf("%d", &ch);
  
    if (ch > 2) return 0;
  
    (*fun_ptr_arr[ch])(a, b);
  
    return 0;
}


-------------
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
//   duvida
}
  
int main ()
{
  int arr[] = {10, 5, 15, 12, 90, 80};
//   descobrir tamanho de um item do array
  int n = sizeof(arr)/sizeof(arr[0]), i;
  
  qsort (arr, n, sizeof(int), compare);
  
  for (i=0; i<n; i++)
     printf ("%d ", arr[i]);
  return 0;
}