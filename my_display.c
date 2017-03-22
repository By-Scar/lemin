#include "my_display.h"

void    my_putchar(char c)
{
  write(1, &c, 1);
}

void    my_putstr(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}

int     my_strlen(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}

int     my_puterr(char *str)
{
  int   i;

  i = 0;
  while (str[i] != 0)
    {
      if (write(2, &str[i++], 1) == -1)
        my_error_exit(ERR_WRITE);
    }
  return (0);
}
