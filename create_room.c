#include "../include/lem_in.h"

t_room          *create_room(t_room_param *current_param,
                             int nb_ant, int nb_max_ant, int mass)
{
  t_room        *current_room;

  current_room = xmalloc(sizeof(t_room));
  current_room->name = current_param->name;
  current_room->x = current_param->x;
  current_room->y = current_param->y;
  current_room->nb_ant = nb_ant;
  current_room->nb_ant_max = nb_max_ant;
  current_room->nb_liens = 0;
  current_room->mass = mass;
  current_room->analyzed = FALSE;
  current_room->display = 0;
  free(current_param);
  return (current_room);
}

t_room  *create_room_start(char *str, int nb_max_ant)
{
  return (create_room(analyse_line_conf_room(str),
                      nb_max_ant, nb_max_ant, MASS_START));
}

t_room  *create_room_end(char *str, int nb_max_ant)
{
  return (create_room(analyse_line_conf_room(str),
                      NO_ANT, nb_max_ant, MASS_NULL));
}

t_room  *create_room_inter(char *str)
{
  return (create_room(analyse_line_conf_room(str),
                      NO_ANT, ROOM_INTER_MAX_ANT, MASS_NULL));
}
