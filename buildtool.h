#include <dirent.h> 


//Check whether a file name ends in .c
void recursive(char *directories);

//Compile a .c file to obtain .o file.
int ObjectFile(char *ofile);

//Put all cwd .o files into a .a static library.
int AFile(DIR *dir);

//Make sure the absolute path to top of file system is valid.
int extendFile(char *file);