https://www.linuxtopia.org/online_books/an_introduction_to_gcc/gccintro_9.html

#include "hello.h"

int
main (void)
{
  hello ("world");
  return 0;
}
--
#include <stdio.h>
#include "hello.h"

void 
hello (const char * name)
{
  printf ("Hello, %s!\n", name);
}

compilar e gerar um arquivo hello -> flag -o
if it is omitted, the output is written to a default file called 'a.out'. 

$ gcc -Wall main.c hello_fn.c -o hello

to run 
$ ./hello

---

Compiling files independently
- a file is compiled without creating an executable -> cria um arquivo objeto (files.o)
  An object file contains machine code where any references to the memory addresses of
  functions (or variables) in other files are left undefined.
- the object files are merged together by a separate program called the linker
  The linker combines all the object files to create a single executable. 
  The linker fills in these missing addresses when it produces the executable

command-line option -c is used to compile a source file to an object file. 
  the following command will compile the source file 'main.c' to an object file:
$ gcc -Wall -c main.c
This produces an object file 'main.o' containing the machine code for the main
  function. It contains a reference to the external function hello, but the 
  corresponding memory address is left undefined in the object file at this
  stage (it will be filled in later by linking). 

There is no need to put the header file 'hello.h' on the command line, since 
it is automatically included by the #include statements in 'main.c' and 'hello_fn.c'. 

use gcc to link the object files together and fill in the missing addresses of
external functions. To link object files together, they are simply listed on the command line:
$ gcc main.o hello_fn.o -o hello

This is one of the few occasions where there is no need to use the -Wall 
warning option, since the individual source files have already been successfully 
compiled to object code. Once the source files have been compiled, linking is 
an unambiguous process which either succeeds or fails (it fails only if there 
are references which cannot be resolved). 

To perform the linking step gcc uses the linker ld, which is a separate program. 

-o:
  gera um arquivo executavel newhello
  $ gcc -Wall main.c hello_fn.c -o newhello
  $ ./newhello

-c:
  gera arquivos objetos
  $ gcc -Wall -c main.c
  depois atraves dos arquivos objetos, consigo criar um executavel
  $ gcc main.o hello_fn.o -o hello
  caso eu realize alguma alteração em algum arquivo .c, só gera um novo arquivo objeto
  deste unico arquivo e gera um novo executavel

-------

https://www.linuxtopia.org/online_books/an_introduction_to_gcc/gccintro_16.html

Makefile
inplicitamente (usando as chaves abaixo), ja sabe q o compilador CC vai usar as flags CFLAGS com os arquivos objetos *.o
q são baseados nos arquivo *.c

CC=gcc 
CFLAGS=-Wall
main: main.o hello_fn.o

clean:
	rm -f main main.o hello_fn.o
  * -f: força deletar, se arquivo não existe não dá erro

resultado:
$ make
gcc -Wall   -c -o main.o main.c
gcc -Wall   -c -o hello_fn.o hello_fn.c
gcc   main.o hello_fn.o   -o main
$ ./main

To rebuild the executable after modifying a source file, simply type make again. By checking the timestamps of the target and dependency files, make identifies the files which have changed and regenerates the corresponding intermediate files needed to update the targets: 
----------------------------
External libraries
Libraries are typically stored in special archive files with the extension '.a', referred to as static libraries.
hey are created from object files with a separate tool, the GNU archiver ar, and used by the linker to resolve references to functions at compile-time
$$
The standard system libraries are usually found in the directories '/usr/lib' and '/lib'
ex:  the C math library is typically stored in the file '/usr/lib/libm.a' 
  prototype declarations for the functions in this library are given in the header file '/usr/include/math.h'
  #include <math.h>

  se souber o caminho pra lib
  $ gcc -Wall calc.c /usr/lib/libm.a -o calc
  To avoid the need to specify long paths on the command line, the compiler provides a short-cut option '-l' for linking against libraries. 
  $ gcc -Wall calc.c -lm -o calc

  the compiler option -lNAME will attempt to link object files with a library file 'libNAME.a'  in the standard library directories
  The traditional behavior of linkers is to search for external functions from left to right in the libraries specified on the command line. This means that a library containing the definition of a function should appear after any source files or object files which use it
  $ gcc -Wall calc.c -lm -o calc

  A library which calls an external function defined in another library should appear before the library containing the function. 
 For example, a program 'data.c' using the GNU Linear Programming library 'libglpk.a', which in turn uses the math library 'libm.a', should be compiled as,
  $ gcc -Wall data.c -lglpk -lm

Erros qdo nao acha lib
/usr/bin/ld: cannot find library

geralmente os header deveriam estar salvo em 
/usr/local/include/
/usr/include/

e as libs
/usr/local/lib/
/usr/lib/
The directories on these paths are searched in order, from first to last in the two lists above.(7) For example, a header file found in '/usr/local/include' takes precedence over a file with the same name in '/usr/include'. Similarly, a library found in '/usr/local/lib' takes precedence over a library with the same name in '/usr/lib'. 

The compiler options -I and -L add new directories to the beginning of the include path and library search path respectively

 The program uses the header file 'gdbm.h' and the library 'libgdbm.a'. If the library has been installed in the default location of '/usr/local/lib', with the header file in '/usr/local/include', then the program can be compiled with the following simple command:

$ gcc -Wall dbmain.c -lgdbm

se tiver em outra pasta, pq foi incluido o header, mas não linkado
$ gcc -Wall -I/opt/gdbm-1.8.3/include dbmain.c -lgdbm 
/usr/bin/ld: cannot find -lgdbm
collect2: ld returned 1 exit status

$ gcc -Wall -I/opt/gdbm-1.8.3/include -L/opt/gdbm-1.8.3/lib dbmain.c -lgdbm

Note that you should never place the absolute paths of header files in #include statements in your source code, as this will prevent the program from compiling on other systems. The -I option or the INCLUDE_PATH variable described below should always be used to set the include path for header files.

directories can be added to the include path using the environment variable
 C_INCLUDE_PATH (for C header files)
 CPLUS_INCLUDE_PATH (for C++ header files)

$ C_INCLUDE_PATH=/opt/gdbm-1.8.3/include 
$ export C_INCLUDE_PATH

This directory will be searched after any directories specified on the command line with the option -I, and before the standard default directories (such as '/usr/local/include' and '/usr/include')

$ LIBRARY_PATH=/opt/gdbm-1.8.3/lib
$ export LIBRARY_PATH

This directory will be searched after any directories specified on the command line with the option -L, and before the standard default directories (such as '/usr/local/lib' and '/usr/lib').

DIR1:DIR2:DIR3:...
The directories are then searched in order from left to right. A single dot '.' can be used to specify the current directory

ou posso fazer arquivo por arquivo
$ gcc -I. -I/opt/gdbm-1.8.3/include -I/net/include
   -L. -L/opt/gdbm-1.8.3/lib -L/net/lib .....

Static libraries are the '.a' files
  machine code from the object files for any external functions used by the program is copied from the library into the final executable.

Shared libs
$ ./a.out
./a.out: error while loading shared libraries:
libgdbm.so.3: cannot open shared object file:
No such file or directory

This is because the GDBM package provides a shared library. This type of library requires special treatment--it must be loaded from disk before the executable will run
Shared libraries are handled with a more advanced form of linking, which makes the executable file smaller. They use the extension '.so', which stands for shared object. 
Whenever a static library 'libNAME.a' would be used for linking with the option -lNAME the compiler first checks for an alternative shared library with the same name and a '.so' extension. 

when the executable file is started its loader function must find the shared library in order to load it into memory. By default the loader searches for shared libraries only in a predefined set of system directories, such as '/usr/local/lib' and '/usr/lib'. If the library is not located in one of these directories it must be added to the load path

 The simplest way to set the load path is through the environment variable LD_LIBRARY_PATH. For example, the following commands set the load path to '/opt/gdbm-1.8.3/lib' so that 'libgdbm.so' can be found:

$ LD_LIBRARY_PATH=/opt/gdbm-1.8.3/lib
$ export LD_LIBRARY_PATH
$ ./a.out
Storing key-value pair... done.

 it is also possible to link directly with individual library files by specifying the full path to the library on the command line. For example, the following command will link directly with the static library 'libgdbm.a',

$ gcc -Wall -I/opt/gdbm-1.8.3/include 
    dbmain.c /opt/gdbm-1.8.3/lib/libgdbm.a

and the command below will link with the shared library file 'libgdbm.so':

$ gcc -Wall -I/opt/gdbm-1.8.3/include 
    dbmain.c /opt/gdbm-1.8.3/lib/libgdbm.so

static linking can be forced with the -static option to gcc to avoid the use of shared libraries:

$ gcc -Wall -static -I/opt/gdbm-1.8.3/include/ 
    -L/opt/gdbm-1.8.3/lib/ dbmain.c -lgdbm

Warning options in -Wall --> https://www.linuxtopia.org/online_books/an_introduction_to_gcc/gccintro_30.html

Macros
definir uma macro TEST
$ gcc -Wall -DTEST dtest.c
ou 
#define TEST "Hello, World!"
$ gcc -Wall -DNUM="2+2" dtestmul10.c
            -DMESSAGE='"Hello, World!"'

-g aponta p dump de memoria
$ gcc -Wall -g null.
$ ./a.out 
Segmentation fault (core dumped)
should produce a file called 'core' in the current directory.This core file contains a complete copy of the pages of memory used by the program at the time it was terminated. Incidentally, the term segmentation fault refers to the fact that the program tried to access a restricted memory "segment" outside the area of memory which had been allocated to it.

The current size limit can be shown by typing the following command: (pq eles geralmente sao muito grandes)
$ ulimit -c
$ ulimit -c unlimited (aumenta limite)

 Core files can be loaded into the GNU Debugger gdb with the following command:
$ gdb EXECUTABLE-FILE CORE-FILE

both the original executable file and the core file are required for debugging--it is not possible to debug a core file without the corresponding executable. In this example, we can load the executable and core file with the command:
$ gdb a.out core

debugger and breakpoints --> https://www.linuxtopia.org/online_books/an_introduction_to_gcc/gccintro_40.html

library
  ar combines a collection of object files into a single archive file, also known as a library

$ gcc -Wall -c hello_fn.c
$ gcc -Wall -c bye_fn.c
$ ar cr libhello.a hello_fn.o bye_fn.o
  cr stands for "create and replace". If the library does not exist, it is first created. If the library already exists, any original files in it with the same names are replaced by the new files specified on the command line.
  'libhello.a' is the name of the library
  The remaining arguments are the names of the object files to be copied into the library. 

The archiver ar also provides a "table of contents" option t to list the object files in an existing library:
  $ ar t libhello.a
  hello_fn.o
  bye_fn.o

main deve incluir o header da library, e o arquivo libhello.a deve estar no current directory
$ gcc -Wall main.c libhello.a -o hello
==
$ gcc -Wall -L. main.c -lhello -o hello

info sobre o executavel
$ file a.out
a.out: ELF 32-bit LSB executable, Intel 80386, 
  version 1 (SYSV), dynamically linked (uses shared
  libs), not stripped

dynamically linked
    The executable uses shared libraries (statically linked indicates programs linked statically, for example using the -static option) 
not stripped
    The executable contains a symbol table (this can be removed with the strip command
