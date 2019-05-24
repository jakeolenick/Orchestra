#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
#include <math.h> 
#include <unistd.h>
#include "convert.c"
#define BUF_SIZE 4096



/**
   HOW TO COMPILE
   gcc mute_sounds.c
   
*/

 int main(int argc, char **argv)  
 {  
     
     int f = fork();
     if (!f){
       execlp("cat","cat","chart",NULL);
       exit(0);
     }

     while(1){
       printf("loop\n");
       char chr[4];
       fgets(chr,3,stdin);
       char note = chr[0];
       printf("note: %f\n",convert3(note));
     }
     
     
     return 0;
 }  
