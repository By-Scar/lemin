#include "../include/my_get_next_line.h"

int     my_len(char *str, int x)
{
  int   i;
  int   n;

  i = 0;
  n = 0;
  while (str[n] != 0)
    n = n + 1;
  while (str[i] != x)
    {
      if (i >= n)
        return (--i);
      i = i + 1;
    }
  return (i);
}

char    *my_cpy(char *dest, char *src, int i)
{
  int   n;

  n = 0;
  while (src[i] != 0)
    {
      dest[n] = src[i];
      n = n + 1;
      i = i + 1;
    }
  dest[n] = 0;
  return (dest);
}

char            *my_zerofd()
{
  int           ret;
  int           i;
  static char   buffer[BUFFER_SIZE];
  char          *str;

  ret = read(0, buffer, BUFFER_SIZE);
  if (ret == -1)
    return (NULL);
  if (ret == 0)
    my_error_exit(ERR_CTRLD);
  i = my_len(buffer, '\n');
  if ((str = xmalloc((i + 1) * sizeof(*str))) == NULL)
    my_error_exit(ERR_MALLOC_GNL);
  my_strncpy(str, buffer, i);
  str[i] = 0;
  return (str);
}

char            *my_gnl(char *buffer)
{
  int           x;
  char          *str;
  static char   save[BUFFER_SIZE];
  static int    i;

  x = 0;
  while (buffer[i] != '\n')
    {
      if (buffer[i] == 0)
        return (0);
      save[x++] = buffer[i++];
    }
  save[x] = 0;
  if ((str = xmalloc(sizeof(char *) * (i + 1))) == NULL)
    my_error_exit(ERR_MALLOC_GNL);
  my_strcpy(str, save);
  str[i] = 0;
  my_cpy(save, buffer, ++i);
  return (str);
}

char            *get_next_line(int fd)
{
  int           ret;
  static char   buffer[BUFFER_SIZE];

  if (fd == 0)
    return (my_zerofd());
  ret = read(fd, buffer, BUFFER_SIZE);
  if (ret == -1)
    my_error_exit(ERR_GNL_FD);
  return (my_gnl(buffer));
}
