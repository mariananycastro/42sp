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
#include <stdio.h> // printf("string %s", var) %d, %s, %lu, %f, %zu (sizeof)
#include <unistd.h> // write(1, &var, n_caracteres)
#include "arquvivo.c" // prototipar void function(charx);

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

void 
  (void *) -> ponteiro p void

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

// numbers
int = 2147483648
      -2147483647
short = +-32768
null = '\0'

// variavel / var
  typedef int bolinha; 
  bolinha number = 1;

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

  ----
  typedef	struct s_point
  {
    int x;
    int y;
  } t_point;

  t_point point; // sem o struct