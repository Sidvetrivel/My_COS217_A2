/* pointer implemenetation of string.h functions */
#include <stddef.h>
#include <assert.h>

/* getLength takes char pointer of pcSrc and returns the length of the 
string that the pointer is pointing to as a size_t type */
size_t Str_getLength(const char *pcSrc)
{
   const char *pcEnd;
   assert(pcSrc != NULL);
   pcEnd = pcSrc;
   while (*pcEnd != '\0')
      pcEnd++;
   return (size_t)(pcEnd - pcSrc);
}

/* copy takes char pointers dest and pcSrc and copies the string that
pcSrc is pointing to and copies it to the addresses that the dest 
pointer is pointing to. It then returns the char pointer that points
to the new copied string*/
char* Str_copy(char* dest, const char* pcSrc)
{
    char* copy = dest;
    assert(pcSrc != NULL && dest != NULL);
    while(*pcSrc != '\0'){
        *dest++ = *pcSrc++;
    }
    *dest = '\0';
    return copy;
}

/* concat takes in char pointers of dest and pcSrc and copies over
the string that pcSrc is pointing to and adds it to the string that the
dest pointer is pointing to. Then it returns the dest pointer which now
is pointing to the full concatenated string.*/
char* Str_concat(char* dest, const char* pcSrc)
{
    char* concat;
    assert(pcSrc != NULL && dest != NULL);
    concat = dest + Str_getLength(dest);
    while(*pcSrc != '\0'){
        *concat++ = *pcSrc++;
    }
    *concat = '\0';
    return dest;
}

/* compare takes in char pointers for two seperate strings returns an
int that denotes whether they are equal or not (0 if they are equal, 
positive int value means str1 > str2, negative int value means str1 <
str2).*/
int Str_compare(const char* str1, const char* str2)
{
    assert(str1 != NULL && str2 != NULL);
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return (*(char*)str1)-(*(char*)str2);
}

/*search takes two pointer parameters str1 and str2 and returns a char*
pointing to the first occurence of the string that str2 points to
within the string that str1 is pointing to*/
char* Str_search(const char* str1, const char* str2)
{     
    char* i = (char*)str1;
    char* j = (char*)str2;
    assert(str2 != NULL && str1 != NULL);
    if (*str2 == '\0') {
        return (char*)str1;
    }
    while (*i != '\0') {
        while (*i != '\0' && *j != '\0' && *i == *j) {
            i++;
            j++;
        }
        if (*j == '\0') {
            return (char*) (i - j);
        }
        if (*i == '\0') {
            return NULL;
        }
        i = (char*)(i - j + 1);
        j = (char*)str2;
    }
    return NULL;
}