I made this file only to take notes, so it may not always makes sense :D

1. Put all relevant files into one directory including the header (.h )
 file containing prototypes for the relevant entities.
  
2. Make sure that the header (.h) file contains the macros 
	#ifndef <HEADERFILE>_H and #define <HEADERFILE>_H 
	at the top and #endif at the bottom so that the header 
	file is only defined once instead of each time it is called.

3. Batch compile all source (.c) files. 
	Use the -c option so that compiler doesn’t link the object files yet
	but instead creates counterpart object (.o) file for each source (.c) file

	gcc -Wall -Werror -Wextra -c *.c

4. Archive all of the object (.o) files into one static library (.a) file. 
	Use the command option -r to ensure that if the library (.a) file already exists,
	it will be replaced. The command option -c should be used so that if the file 
	doesn’t exist, it will be created.

	ar -rc file_name.a *.o

	ar : An archive is a single file holding a collection of other files in 
	a structure that makes it possible to retrieve the original individual files 
	(called members of the archive). 


5. Now, instead of having to include all relevant file names in the compilation
	command, only the library (.a) file need be referenced

	gcc main.c file_name.a