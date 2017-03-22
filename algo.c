#include "../include/lem_in.h"

t_room          *find_the_lightest_room(int nb_all_rooms, t_room **all_rooms)
{
  t_room        *result;
  int           mass;
  int           k;

  mass = nb_all_rooms * nb_all_rooms;
  k = 0;
  while (k < nb_all_rooms)
    {
      if (all_rooms[k]->analyzed == FALSE
          && all_rooms[k]->mass > MASS_NULL
          && all_rooms[k]->mass < mass)
        {
          mass = all_rooms[k]->mass;
          result = all_rooms[k];
        }
      k++;
    }
  return (result);
}

void    update_room_mass(t_room *parent_room, t_room *linked_room)
{
  if ((linked_room->analyzed == FALSE)
      && ((parent_room->mass + MASS_PATH < linked_room->mass)
          || (linked_room->mass == MASS_NULL)))
    {
      linked_room->mass = parent_room->mass + MASS_PATH;
      linked_room->father = parent_room;
    }
}

void    analyse_room_links(t_room *room)
{
  int   k;

  k = 0;
  while (k < room->nb_liens)
    {
      update_room_mass(room, room->links[k]);
      k++;
    }
  room->analyzed = TRUE;
}

void            find_path_from_start_to_end(t_room *room_start, t_room *room_end)
{
  t_room        *father;
  t_room        *new_father;

  father = room_end->father;
  father->child = room_end;
  while (strcmp(room_start->name, father->name) != 0)
    {
      new_father = father->father;
      if (new_father != NULL && father != NULL)
        {
          new_father->child = father;
        }
      father = new_father;
    }
}

void            launch_dijkstra(t_room *start_room, t_room *end_room,
                                int nb_all_rooms, t_room **all_rooms)
{
  t_room        *smally;

  smally = find_the_lightest_room(nb_all_rooms, all_rooms);
  while (strcmp(end_room->name, smally->name) != 0)
    {
      smally = find_the_lightest_room(nb_all_rooms, all_rooms);
      analyse_room_links(smally);
    }
  find_path_from_start_to_end(start_room, end_room);
}
