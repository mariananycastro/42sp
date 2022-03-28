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
	ar creates an index, this index is updated in the archive whenever ar makes
	a change to its contents
	-r : replace existing or insert new file(s) into the archive
		(ar t file_name.a - list of files in the index)
		(ar p file_name.a - show content)
		(ar d file_name.a file_to_delete.txt)

5. Now, instead of having to include all relevant file names in the compilation
	command, only the library (.a) file need be referenced

	gcc main.c file_name.a

	-----
	1. Compile the ``.c'' file containing the source code
		gcc -Wall -g -c hello.c

		-c : produce an object file called (in this case) ``hello.o''.
		-g : tells the compiler to include information needed by the debugger

	2. Link the ``.o'' file to produce an executable 
		gcc -o hello hello.o -lm

		-o : tells C what to name the executable
		-lm : tells C to link in the math libraries.

	3. Run the executable in the usual way
		gcc -Wall -g -o hello hello.c -lm

		if your entire program is contained within a single file, you can do
		the compilation and linking in one step by entering the command

	---
	multiple files
	putting the various functions that make up the program into more than one file. 
--> compiling, linking, and running 

1. Compile each of the ``.c'' files separately.
	gcc -Wall -g -c main.c
	gcc -Wall -g -c help.c

2. Link the two resulting ``.o'' files into a single executable program.
	gcc -o demo main.o help.o -lm

	This results in an executable called ``demo''.

3. Run the resulting executable.
	demo

---
gcc -E : preprocessor 
		-S : translate to assembly 
		-c : assembly to executable, generate .o files
		-o : to object file -> gcc file.c -o tip -> ./tip
					create a link between files .o, just need to prototype the functions



