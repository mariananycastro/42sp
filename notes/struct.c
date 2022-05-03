// I made this file only to take notes, so it may not always makes sense :D

/ Struct
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


//   ------

  typedef struct	s_list
	{
		void *content;
		struct s_list *next;
	} t_list;

	content: The data contained in the node.
	void * allows to store any kind of data.

	next: The address of the next node, or NULL if the next node is the last one


// ------------------

#include <stdio.h>
#include <string.h>

int main()
{
    struct name {
        char first[24];
        char last[24];
    };
    struct name me;

    strcpy(me.first,"Dan");
    strcpy(me.last,"Gookin");

    printf("Hello, %s %s!\n",
            me.first,
            me.last);

    return(0);
}

// ------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    struct name {
        char first[24];
        char last[24];
    };
    struct name *me; //pointer

    me = (struct name *)malloc(sizeof(struct name));
    if( me==NULL )
    {
        puts("Unable to allocate memory");
        return(1);
    }

    strcpy(me->first,"Dan");
    strcpy(me->last,"Gookin");

    printf("Hello, %s %s!\n",
            me->first,
            me->last);

    return(0);
}

// -------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    struct name {
        char *first;
        char *last;
    };
    struct name me;

    me.first = (char *)malloc( sizeof(char) * 24 );
    me.last = (char *)malloc( sizeof(char) * 24 );
    if( me.first==NULL || me.last==NULL)
    {
        puts("Unable to allocate memory");
        return(1);
    }

    strcpy(me.first,"Dan");
    strcpy(me.last,"Gookin");

    printf("Hello, %s %s!\n",
            me.first,
            me.last);

    return(0);
}

// -------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    struct name {
        char *first;
        char *last;
    };
    struct name *me;

    me = (struct name *)malloc( sizeof(struct name));
    if( me==NULL )
    {
        puts("Unable to allocate memory");
        return(1);
    }
    me->first = (char *)malloc( sizeof(char) * 24 );
    me->last = (char *)malloc( sizeof(char) * 24 );
    if( me->first==NULL || me->last==NULL)
    {
        puts("Unable to allocate memory");
        return(1);
    }

    strcpy(me->first,"Dan");
    strcpy(me->last,"Gookin");

    printf("Hello, %s %s!\n",
            me->first,
            me->last);

    return(0);
}

