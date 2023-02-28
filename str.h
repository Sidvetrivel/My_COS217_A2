#include <stddef.h>
#ifndef STRA_INCLUDED
#define STRA_INCLUDED

/*getLength*/
size_t Str_getLength(const char pcSrc[]);

/*copy*/
char* Str_copy(char dest[], const char pcSrc[]);

/*concat*/
char* Str_concat(char dest[], const char pcSrc[]);

/*compare*/
int Str_compare(const char str1[], const char pcSrc[]);

/*search*/
char* Str_search(const char str1[], const char pcSrc[]);

#endif
