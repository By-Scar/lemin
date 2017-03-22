#include "my_strncpy.h"

char    *my_strncpy(char *dest, char *src, int n)
{
  int   i;
  int   x;

  i = 0;
  x = 0;
  while (i < n)
    {
      dest[i] = src[i];
      i = i + 1;
    }
  while (src[x] != 0)
    x = x + 1;
  if (n > x)
    dest[i] = '\0';
  return (dest);
}
