// I made this file only to take notes, so it may not always makes sense :D

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

    me = (struct name *)malloc(1 * sizeof(struct name));
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

    me = (struct name *)malloc( sizeof(struct name) * 1);
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