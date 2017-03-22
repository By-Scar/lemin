#include "../include/lem_in.h"

void            display_ant_column_one(t_room *room_start, int nb_max_ant)
{
  int           x;
  t_room        *child;

  x = 1;
  while (x <= nb_max_ant)
    {
      child = room_start->child;
      while (child != NULL)
        {
          printf("P%i-%s\n", x, child->name);
          child = child->child;
        }
      x++;
    }
}
