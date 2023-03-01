#include <stddef.h>
#ifndef STRA_INCLUDED
#define STRA_INCLUDED

/*getLength takes in string pcSrc and returns the length as a size_t*/
size_t Str_getLength(const char pcSrc[]);

/*copy takes in both a string dest and string 
pcSrc, copies pcSrc to dest, and returns the pointer of the copied 
destination buffer*/
char* Str_copy(char dest[], const char pcSrc[]);

/*concat takes a pcSrc array and dest array and adds pcSrc to the dest
buffer and returns the pointer of the concatenated destination*/
char* Str_concat(char dest[], const char pcSrc[]);

/*compare takes str1 and pcSrc arrays and returns an int denoting 
whether the strings are equal or if one or the other is greater*/
int Str_compare(const char str1[], const char pcSrc[]);

/*search takes in a haystack and needle string arguments 
(str1 and pcSrc) and finds the needle argument within the haystack 
and returns the pointer to the first occurence of needle in haystack*/
char* Str_search(const char str1[], const char pcSrc[]);

#endif
