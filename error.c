#include "../include/my_error_exit.h"

void    my_error_exit(char *err)
{
  my_puterr(err);
  exit(EXIT_FAILURE);
}
