#include <stddef.h>

size_t Str_getLength(const char pcSrc[])
{
   size_t uLength = 0;
   assert(pcSrc != NULL);
   while (pcSrc[uLength] != '\0'){
        uLength++;
   }
   return uLength;
}

int* Str_copy(char dest[], const char pcSrc[])
{
    int i = 0;
    assert(pcSrc != NULL && dest != NULL);
    while(pcSrc[i] != '\0'){
        dest[i] = pcSrc[i];
    }
    dest[i] = '\0';
    return dest;
}

int* Str_concat(char dest[], const char pcSrc[])
{
    int i = 0;
    int j = 0;
    assert(pcSrc != NULL && dest != NULL);
    while(dest[i] != '\0'){
        i++;
    }
    while(pcSrc[j] != '\0'){
        dest[i] = pcSrc[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return dest;
}



