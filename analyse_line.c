#include "../include/lem_in.h"

t_room_param    *analyse_line_conf_room(char *str)
{
  t_room_param  *current_room_param;

  current_room_param = xmalloc(sizeof(t_room_param));
  current_room_param->name = strtok(str, DATA_ROOM_SEPARATOR_STRING);
  current_room_param->x = atoi(strtok(NULL, DATA_ROOM_SEPARATOR_STRING));
  current_room_param->y = atoi(strtok(NULL, DATA_ROOM_SEPARATOR_STRING));
  return (current_room_param);
}

t_room_link     *analyse_line_conf_link(char *str)
{
  t_room_link   *current_room_link;

  current_room_link = xmalloc(sizeof(t_room_link));
  current_room_link->name_room_one = strtok(str, DATA_LINK_SEPARATOR_STRING);
  current_room_link->name_room_two = strtok(NULL, DATA_LINK_SEPARATOR_STRING);
  return (current_room_link);
}
