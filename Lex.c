//-----------------------------------------------------------------------------
// Based on FileIO.c
// Illustrates file input-output commands and text processing using the
// string functions strtok and strcat.
//-----------------------------------------------------------------------------
#include<stdio.h>
#include<stdlib.h>
#include "List.h"
#include <string.h>

#define MAX_LEN 300

int main(int argc, char * argv[]){

   int count=0;
   FILE *in, *out;
   char line[MAX_LEN];
   //char tokenlist[MAX_LEN];
   //char* token;

   // check command line for correct number of arguments
   if( argc != 3 ){
      printf("Usage: %s <input file> <output file>\n", argv[0]);
      exit(1);
   }

   // open files for reading and writing 
   in = fopen(argv[1], "r");
   out = fopen(argv[2], "w");
   if( in==NULL ){
      printf("Unable to open file %s for reading\n", argv[1]);
      exit(1);
   }
   if( out==NULL ){
      printf("Unable to open file %s for writing\n", argv[2]);
      exit(1);
   }
  
  List list = newList();

  //replace with insertion sort
   /* read each line of input file, then count and print tokens */
   while( fgets(line, MAX_LEN, in) != NULL)  {  
      count++;
   }
   rewind(in);

   char cArray[count][MAX_LEN];
   int i = 0;
   while( fgets(line, MAX_LEN, in) != NULL)  {
       strcpy(cArray[i], line);
       i++;
   }
   append(list, 0); //put a string first? 

    for(int i = 1; i < count; i++){ //int i =1;
      moveFront(list);
      int inserted = 0;
      while (inserted != 1 && index(list) != -1) { //checks for location
        if (strcmp(cArray[i],cArray[get(list)]) < 0){ //what to compare to? //before
          insertBefore(list,i);
          inserted = 1;
        }
        else{
        	moveNext(list);
        }
      }
      if (inserted == 0){
        append(list,i);//must be at the back
      }
    }
   
   //putting array in the file
   moveFront(list);
   while(index(list) != -1){
        fprintf(out, "%s",cArray[get(list)]);
        moveNext(list);
   }

   /* close files */
   fclose(in);
   fclose(out);

   freeList(&list);

   return(0);
}
