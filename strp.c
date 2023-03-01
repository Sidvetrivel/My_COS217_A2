#include <stddef.h>
#include <assert.h>

size_t Str_getLength(const char *pcSrc)
{
   const char *pcEnd;
   assert(pcSrc != NULL);
   pcEnd = pcSrc;
   while (*pcEnd != '\0')
      pcEnd++;
   return (size_t)(pcEnd - pcSrc);
}

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

int Str_compare(const char* str1, const char* str2)
{
    assert(str1 != NULL && str2 != NULL);
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return (*(char*)str1)-(*(char*)str2);
}

char* Str_search(const char* str1, const char* str2)
{
    char* i;
    char* j;
    assert(str1 != NULL && str2 != NULL);
    i = &str1;
    j = &str2;
    if(*str2 == '\0'){
        return (char*)str1;
    }
    while(*str1 != '\0'){
        while(*i == *j && *j != '\0'){
            i++;
            j++;
        }
        if(*j == '\0'){
            return (char*)str1;
        }
        str1++;
    }
    return NULL;
}