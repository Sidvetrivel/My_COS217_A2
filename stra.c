#include <stddef.h>

//get length implementation
size_t Str_getLength(const char pcSrc[])
{
   size_t uLength = 0;
   assert(pcSrc != NULL);
   while (pcSrc[uLength] != '\0')
      uLength++;
   return uLength;
}

size_t Str_copy(const char pcSrc[])
{

}

size_t Str_concat(const char pcSrc[])
{

}

size_t Str_compare(const char pcSrc[])
{

}

size_t Str_search(const char pcSrc[])
{

}


