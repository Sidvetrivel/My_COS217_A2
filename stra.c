#include <stddef.h>

size_t Str_getLength(const char pcSrc[])
{
   size_t uLength = 0;
   assert(pcSrc != NULL);
   while (pcSrc[uLength] != '\0')
      uLength++;
   return uLength;
}

char* Str_copy(char dest[], const char pcSrc[])
{
    int i = 0;
    while(pcSrc[i] != '\0'){
        dest[i] = pcSrc[i];
    }
    dest[i] = '\0';
    return dest;
}

size_t Str_concat(char dest[], const char pcSrc[])
{

}

size_t Str_compare(const char pcSrc[])
{

}

size_t Str_search(const char pcSrc[])
{

}


