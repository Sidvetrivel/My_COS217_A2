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
    char* concat = dest + Str_getLength(dest);
    assert(pcSrc != NULL && dest != NULL);
    while(*dest != '\0'){
        *dest++ = *pcSrc++;
    }
    
    *concat = '\0';
    return dest;
}

int Str_compare(const char str1[], const char str2[])
{
    int i = 0;
    assert(str2 != NULL && str1 != NULL);
    while (str1[i] && (str1[i] == str2[i])) {
        i++;
    }
    return (str1[i] - str2[i]);
}

char* Str_search(const char str1[], const char str2[])
{
    int i = 0;
    int j = 0;
    assert(str2 != NULL && str1 != NULL);
    for (i = 0; str1[i]; i++) {
        for (j = 0; str2[j]; j++) {
            if (str1[i+j] != str2[j])
                break;
        }
        if (!str2[j])
            return &str1[i];
    }
    return NULL;
}

int main(){
    return 0;
}
