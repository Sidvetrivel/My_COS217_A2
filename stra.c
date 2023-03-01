#include <stddef.h>
#include <assert.h>

size_t Str_getLength(const char pcSrc[])
{
   size_t uLength = 0;
   assert(pcSrc != NULL);
   while (pcSrc[uLength] != '\0'){
        uLength++;
   }
   return uLength;
}

char* Str_copy(char dest[], const char pcSrc[])
{
    int i = 0;
    assert(pcSrc != NULL && dest != NULL);
    while(pcSrc[i] != '\0'){
        dest[i] = pcSrc[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}


char* Str_concat(char dest[], const char pcSrc[])
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

int Str_compare(const char str1[], const char pcSrc[])
{
    int i = 0;
    assert(pcSrc != NULL && str1 != NULL);
    while (str1[i] && (str1[i] == pcSrc[i])) {
        i++;
    }
    return (str1[i] - pcSrc[i]);
}

char* Str_search(const char str1[], const char pcSrc[])
{
   int i, j, k;
    if (pcSrc[0] == '\0') {
        return (char*)str1;
    }
    for (i = 0; str1[i] != '\0'; i++) {
        for (j = i, k = 0; str1[j] == pcSrc[k] && pcSrc[k] != '\0'; j++, k++);
        if (pcSrc[k] == '\0') {
            return (char*)&str1[i];
        }
    }
    return NULL;
}

