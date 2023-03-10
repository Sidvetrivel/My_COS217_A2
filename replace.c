/*--------------------------------------------------------------------*/
/* replace.c                                                          */
/* Author: Siddharth Vetrivel                                         */
/*--------------------------------------------------------------------*/

#include "str.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

/*--------------------------------------------------------------------*/

/* If pcFrom is the empty string, then write string pcLine to stdout
   and return 0.  Otherwise write string pcLine to stdout with each
   distinct occurrence of string pcFrom replaced with string pcTo,
   and return a count of how many replacements were made.  Make no
   assumptions about the maximum number of replacements or the
   maximum number of characters in strings pcLine, pcFrom, or pcTo. */

/* replaceAndWrite takes in 3 parameters of const char pointers
of pcLine, pcFrom, and pcTo. The function replaces each occurence of 
pcFrom within pcLine and replaces occurences of pcFrom with pcTo. After
printing out the string with replacements to std.out, the function
returns the number of replacements made as a size_t type */
static size_t replaceAndWrite(const char *pcLine,
                              const char *pcFrom, const char *pcTo)
{
   size_t replaceCount = 0;
   char* s; 
   assert(pcLine != NULL && pcFrom != NULL && pcTo != NULL);
   s = Str_search(pcLine,pcFrom);
   if(*pcFrom == '\0'){
         while(*pcLine == '\0'){
            putchar(*pcLine);
            pcLine++;
         }
         return 0;
   } 
   else{
      while(s != NULL){
         while(pcLine != s){
            putchar(*pcLine);
            pcLine++;
         }
         printf("%s", pcTo);
         pcLine = pcLine + Str_getLength(pcFrom);
         s = Str_search(pcLine,pcFrom);
         replaceCount++;
      }
      printf("%s", pcLine);
   }
   return replaceCount;
}

/*--------------------------------------------------------------------*/

/* If argc is unequal to 3, then write an error message to stderr and
   return EXIT_FAILURE.  Otherwise...
   If argv[1] is the empty string, then write each line of stdin to
   stdout, write a message to stderr indicating that 0 replacements
   were made, and return 0.  Otherwise...
   Write each line of stdin to stdout with each distinct occurrence of
   argv[1] replaced with argv[2], write a message to stderr indicating
   how many replacements were made, and return 0.
   Assume that no line of stdin consists of more than MAX_LINE_SIZE-1
   characters. */

int main(int argc, char *argv[])
{
   enum {MAX_LINE_SIZE = 4096};
   enum {PROPER_ARG_COUNT = 3};

   char acLine[MAX_LINE_SIZE];
   char *pcFrom;
   char *pcTo;
   size_t uReplaceCount = 0;

   if (argc != PROPER_ARG_COUNT)
   {
      fprintf(stderr, "usage: %s fromstring tostring\n", argv[0]);
      return EXIT_FAILURE;
   }

   pcFrom = argv[1];
   pcTo = argv[2];

   /* this while loop takes a line from stdin as long as it's null
   and calls replaceAndWrite. It then adds the return value of 
   replaceAndWrite to the total replacement count variable 
   (uReplaceCount) and outputs this value to stderr when exiting the 
   loop */
   while (fgets(acLine, MAX_LINE_SIZE, stdin) != NULL)
      uReplaceCount += replaceAndWrite(acLine, pcFrom, pcTo);
   fprintf(stderr, "%lu replacements\n", (unsigned long)uReplaceCount);
   return 0;
}
