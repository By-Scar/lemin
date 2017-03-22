#include "../include/lem_in.h"

void    close_file(int fd)
{
  close(fd);
}

int     main(int argc, char **argv)
{
  if (argc != 2)
    {
      my_puterr(" --> usage: ./lemin <File Descriptor>\n");
      return (-1);
    }
  else
    load_configuration(argc, argv);
  return (0);
}
