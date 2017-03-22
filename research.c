#include "lem_in.h"

int     is_line_discribing_a_room(char *str)
{
  int   result;
  int   i;

  result = FALSE;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == DATA_ROOM_SEPARATOR_CHAR)
        {
          result = TRUE;
        }
      i++;
    }
  return (result);
}

t_room          *research_room(int nb_all_rooms,
                               t_room **all_rooms, char *room_name)
{
  t_room        *result;
  int           i;

  i = 0;
  while (i < nb_all_rooms)
    {
      if (strcmp(all_rooms[i]->name, room_name) == 0)
        {
          result = all_rooms[i];
        }
      i++;
    }
  return (result);
}
