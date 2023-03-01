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
    /*char* i;
    char* j;
    assert(str1 != NULL && str2 != NULL);
    i = (char*)str1;
    j = (char*)str2;
    if(*str2 == '\0'){
        return (char*)str1;
    }
    while(*str1 != '\0'){
        while(*i == *j && *j != '\0'){
            j++;
            i++;
        }
        if(*j == '\0'){
            return (char*)str1;
        }
        str1++;
    }
    return NULL;
    */

    /*
    char* p1 = str1;
    char* p2 = str2;
    char* p3 = str1;
    
    while (*p1 != '\0' && *p2 != '\0') {
        if (*p1 == *p2) {
            if (p3 == str1) {
                p3 = p1;
            }
            p2++;
        } 
        else {
            p2 = str2;
            if (p3 != str1) {
                p1 = p3 + 1;
                p3 = str1;
            }
            if (*p1 == *p2) {
                p3 = p1;
                p2++;
            }
        }
        p1++;
    }
    
    if (*p2 == '\0') {
        return (char*)(p3);
    }
    return NULL;
    */
    if (*str2 == '\0') {
        // Special case: empty string is always found
        return (char*)str1;
    }

    const char* p1 = str1;
    while (*p1 != '\0') {
        const char* p1Begin = p1;
        const char* p2 = str2;

        while (*p1 != '\0' && *p2 != '\0' && *p1 == *p2) {
            p1++;
            p2++;
        }

        if (*p2 == '\0') {
            // Found
            return (char*)p1Begin;
        }

        if (*p1 == '\0') {
            // Not found
            return NULL;
        }

        p1 = p1Begin + 1;
    }

    return NULL;
    
}