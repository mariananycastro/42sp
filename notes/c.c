// I made this file only to take notes, so it may not always makes sense :D 

// methods

if () {}
else if() {}
else {}

while(sth)
{
  sth_happens;
  i++;
}

for(i=1; condition; i++) { }

sth > 0 ? sth_happens : sth_els_happens;

//  macro preprocessor

// -> header file
#include <stdio.h> // printf("string %s", var) %d, %s, %lu, %f, %zu (sizeof) / puts("") ou puts(var)
#include <unistd.h> // write(1, &var, n_caracteres)
#include "arquvivo.c" // prototipar void function(charx);
#include  <bsd/string.h> //strlcpy gcc main.c -lbsd

int main() {}

// compilar
gcc -Wall -Werror -Wextra main.c && ./a.out

// ==>>>>>pointer - alterar variavel fora da função
pointer nulo nao aponta p lugar nenhum, não inicilizado
 
string
  char string[10] = "123456789"; 
  char *char_string = &string; // p atribuir um ponteiro sempre pego a posição de uma variavel

  ft_putstr(string); 
    ==> dentro chega como ft_putstr(char *str)
      valor = *str (conforme tabela ascii se string)
              str[n]
              *(str + i)
      address = &str[i] ou str[i++]
                str + 1; str++

void ft_test(){
	const char *a[2];
	a[0] = "blah";
	a[1] = "hmm";
	
	printf("%s", a[0]); // "blah"
}

void 
  (void *) -> ponteiro p void
  void(*f)(int) -> function retorna void e recebe um int
  int(*f)(char*) -> function retorna int e recbe um char*

array
  array[] = *array

  int array[10] = {1,2,3,4,5,6,7,8,9,0}
  int *number = &array => aponta para array[0]
  int a = array[10][5]; 

  number = 1 => altero valor pro array[0]

  char string[9] = "123456789";
  char *char_string = &string; 
  str++
  -----------------
  char str[4][2] = {"11", "22", "33", "44"}
  char str[4][5] = {"11", "22", "33", "44"} => gera espaços vazios não utilizados
  char *b = str[4][1];  

  ------

	char strs[NUMBER_OF_STRINGS][STRING_LENGTH+1];
	...
	strcpy(strs[0], aString); // where aString is either an array or pointer to char
	strcpy(strs[1], "foo");
	
	char strs[NUMBER_OF_STRINGS][STRING_LENGTH+1] = {"foo", "bar", "bletch", ...};

	Instead of using a 2-d array of char, you can store a 1-d array of pointers to char:
		// sem desperdiçar memoria
	char *strs[NUMBER_OF_STRINGS];	
	allocated memory to hold the pointers to the strings; the memory for the strings 
	themselves must be allocated 
	elsewhere (either as static arrays or by using malloc() or calloc())
	char *strs[NUMBER_OF_STRINGS] = {"foo", "bar", "bletch", ...};

	Instead of copying the contents of the string constants, youre simply 
	storing the pointers to them. 

	that string constants may not be writable; you can reassign the pointer, like so:
	strs[i] = "bar";
	strs[i] = "foo"; 
	But you may not be able to change the strings contents; i.e.,
	strs[i] = "bar";
	strcpy(strs[i], "foo"); may not be allowed

	You can use malloc() to dynamically allocate the buffer for each string and copy to that buffer:
	strs[i] = malloc(strlen("foo") + 1);
	strcpy(strs[i], "foo");

BTW,

char (*a[2])[14];




// numbers
int = 2147483648
      -2147483647
short = +-32768
null = '\0'

// variavel / var
  typedef int bolinha; 
  bolinha number = 1;

  int *p, *q; // cria 2 var ponteiro.

// casting
  (char*) - typecasting some data type to char-type pointer
  *(char*) - accessing the content of the location to which the pointer
    variable points to

// string 
  white_spaces = { 9 .. 13 } + 32
  non_printable = { 0 .. 31 } + 127

// main                    
  int main(int argc,              char *artgv[]) {}
              qtd argumentos      valor dos argumentos

  arg[0] = nome do programa
  arg[0][i]
  (void)argv; //quando nao utilizo


// Macro
  fragment of code that is given a name.

  #define c 2
    // c = 2

  // function-like macros
  // no mesmo arquivo vou importar
  #define circleArea(r) (3.1415*(r)*(r))

  int main ()
  {
    circleArea(argument) == (3.1415*(argument)*(argument))
  }

  #ifdef MACRO    
  #ifndef // if not defined

    #ifndef YEARS_OLD
    #define YEARS_OLD 10
    #endif // if YEARS_OLD not defined YEARS_OLD = 10

    // #ifdef, #if, #defined, #else and #elif  
    // conditional codes
  #endif

  #if expression
      // conditional codes if expression is non-zero
  #elif expression1
      // conditional codes if expression is non-zero
  #elif expression2
      // conditional codes if expression is non-zero
  #else
      // conditional if all expressions are 0
  #endif

  __DATE__ == A string containing the current date
		
  __FILE__ == A string containing the file name
      
  __LINE__ == An integer representing the current line number
      
  __STDC__ == If follows ANSI standard C, then the value is a nonzero integer
      
  __TIME__ == A string containing the current date

  #include <stdio.h>
  int main()
  {
    printf("Current time: %s",__TIME__);   
  }

// Struct
  /*   The Dot(.) operator is used to access members of a structure or union.
   The Arrow(->) operator exists to access the members of the structure or the unions using pointers
   define the structure */
  
  struct person {
      char name[32];
      int age;
  };

  /* declare a structure variable */
  struct person me;

  /* fill the structure variable */
  strcpy(me.name,"Maria");
  me.age = 22;
  // or
  struct person me = { "Maria", 22 };
  // -----------> p não ter q sempre chamar com struct coloca typedef

  // declarar varias variaveis
  struct person {
      char name[32];
      int age;
  } me, you, him, her;


  // declarar e atribuir
  struct person {
      char name[32];
      int age;
  } me = { "Maria", 22 };

  struct person you = {
      .name = "John",
      .age = 30
  };

  // ----
  typedef	struct s_point
  {
    int x;
    int y;
  } t_point;

  t_point point; // sem o struct
  // ----------------

  read:
    https://c-for-dummies.com/blog/?p=3708
    http://c-for-dummies.com/blog/?p=2708

// File
   /* Posix Open function
    The first parameter : Path, 
      location of the file that you wish to open.
      when the file is in the same directory in which the file
      to be opened resides,you can omit its path or write twice.
    The second parameter : Flag,
      options with which you can open a file.
      O_RDONLY, O_WRONLY, O_RDWR, O_CREAT, and O_EXCL (prevent file creation)
      You can combine more than one flag at once, separated by "|"
    */

    #include <stdio.h>
    #include <fcntl.h>
    #include <errno.h>

    extern int errno;
    int file_descriptor = open("nome.txt", O_RDONLY);
    printf("%d", file_descriptor);
    if (file_descriptor < 0)
    {
      printf("Erro %d", errno);
    }

    file_descriptor == 3, if success
                        -1, fail
--------------
// malloc
	qual o tipo de variavel eu quero utilizar
    (char *) malloc (i * sizeof(char));
					tamanho da string


//
write(#, "string", n_space)
#
// 0 entrada padrao - stdin
// 1 saida padrao - stdout
// 2 erro padrao - stderr