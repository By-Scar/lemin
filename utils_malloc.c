#include "utils_malloc.h"

void    *xmalloc(unsigned int size)
{
  void  *mem;

  mem = malloc(size);
  if (mem == NULL)
    {
      my_puterr("Malloc Error!\n");
      exit(EXIT_FAILURE);
    }
  return (mem);
}
