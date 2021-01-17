#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <libgen.h>
#include <pthread.h>


long ct = 0;
void recursive(char *directories);
pthread_mutex_t mtx;
char directories[50]; //Getting the directory
char path[50];
struct Params{pthread_t id;};
struct Params parameter[3];


int main(){
    
    printf("Enter a path: "); //Prompts user string input
    scanf("%s", directories);

    strcpy(path, "gcc -c");//Finds the compiler to get C files
    strcat(path, directories);

    system(directories);

    recursive(directories);
    pthread_mutex_init(&mtx, NULL);

    
    return 0;
}

//Declaring the directory to descend to
void recursive(char *base){
    char directories[500];
    struct dirent *dt;
    
    DIR *d = opendir(base);

//Returns error if not not found
    if(!d)
    printf("Not found");
        return;

//Finds subdirectories and directories recursively
    while ((dt = readdir(d)) != NULL){
        if(strcmp(dt->d_name, ".") != 0 && strcmp(dt->d_name, "..") != 0){

            pthread_mutex_lock(&mtx);
            pthread_create(&parameter[ct].id, NULL, *base, dt->d_name);
            pthread_mutex_unlock(&mtx);
            

            strcpy(directories, base);
            strcat(directories, "/");
            strcat(directories, dt->d_name);

            recursive(directories);
        }
    }

    closedir(d);

    
    char x;
    char *file;
    char i = file[x-1]; //Calling last character in file name;
    char j = file[x-1]; 
    if(i == '.' && j == 'c'){ //Gets the C files

    }else if(j == '.' && i == 'o'){ //Gets the Object files

    }else if(i == '.' && j == 'a'){ //Gets static library

    }
    strcpy(directories, dt->d_name);
    strcpy(path, "-ar rcs directory.a");
    strcat(directories,path);
    system(path);
    printf("%s\n", dt->d_name);

}








//TO USE IF NEEDED

/*//Finds the extend of all the files
int extendFile(char *file){
    int x = strlen(file);
    char i = file[x-1]; //Calling last character in file name;
    char j = file[x-1]; //Calling second character

    if(i=='.' && j == 'c'){ //If file is .c
        return 0; //returns C files
    }else if(j == '.' && i == 'o'){ //If file is .o
        return 1; //returns object files
    }else if(i == '.' && j == 'a'){
        return 2; //returns static library
    }
}


//Creates the Object files
int ObjectFile(char *ofile){

	int checkCompile;

	//Make complete compile ccompiler. Ex. "gcc -c file1.c"
	char cd [50*sizeof(char) ] = "gcc -c \""; 
	strcat(cd, ofile);
	checkCompile = system(cd); //Create .o file from .c

	return 0;
}

//Create .a files 
int AFile(DIR *dir){
    char aString[120*sizeof(char)];
    char cd[1000*sizeof(char)] = "ar -rc \"";
    char AFile[30*sizeof(char)] = "\"";

    //Make ccompiler
    strcat(AFile, cd);
    strcat(AFile, ".a\"");
    strcat(cd, ".a\"");

    //Move ccompiler
    char move[1000 *sizeof(char)] = "m ";
    strcat(move, AFile);

    rewinddir(dir);
}


int Linker(){
    DIR *topdirectory = opendir(".");
    struct dirent *topcwd;

    char linkdir[1000*sizeof(char)] = "gcc";
    char list[20*sizeof(char)] = "-o buildtools";
    char tempsFiles[20*sizeof(char)];

    //Finding all the C files
    while((topcwd = readdir(topdirectory)) != NULL){
        if(extension(topcwd->d_name) == 0 && strcmp(topcwd->d_name, "buildtools.c") != 0){
            ObjectFile(topcwd->d_name);
        }
    }
    readdir(topcwd);
    while ((topdirectory = readdir(topcwd)) != NULL){
        if(extendFile(topcwd->d_name) == 1 || extendFile(topcwd->d_name) == 2){

            strcpy(topcwd, "\"");
            strcat(topcwd, "/");
            strcat(topcwd, topcwd->d_name);
            strcat(linkdir, tempsFiles);
        }
    }
    //Links all the buildtools
    strcat(linkdir, list);

    system(linkdir);
    return 0;
}*/