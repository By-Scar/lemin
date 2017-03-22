#include "../include/lem_in.h"

int     get_nb_max_ant(char *str)
{
  return (atoi(str));
}

int             link_room_together(int nb_all_rooms, t_room **all_rooms, char *str)
{
  t_room_link   *current_link;
  t_room        *room_one;
  t_room        *room_two;

  current_link = analyse_line_conf_link(str);
  room_one = research_room(nb_all_rooms, all_rooms,
                           current_link->name_room_one);
  room_two = research_room(nb_all_rooms, all_rooms,
                           current_link->name_room_two);
  room_one->links[room_one->nb_liens] = room_two;
  room_two->links[room_two->nb_liens] = room_one;
  room_one->nb_liens++;
  room_two->nb_liens++;
  return (0);
}

void    Error_fd(int fd)
{
  if (fd == -1)
    {
      my_puterr("Error can't open this file\n");
      exit(EXIT_FAILURE);
    }
}

void            readFile(int argc, char **argv)
{
  int           fd;
  char          *s;
  int           nb_max_ant;
  int           i;
  int           next_line_type;
  int           nb_all_rooms;
  t_room        *all_rooms[SIZE];
  t_room        *room_start;
  t_room        *room_end;

  fd = open(argv[1], O_RDONLY);
  Error_fd(fd);
  i = 0;
  nb_all_rooms = 0;
  next_line_type = LINE_DATA;
  while ((s = get_next_line(fd)))
    {
      if (s[0] != '\0')
        {
          printf("%s\n", s);
          if (i == 0)
            {
              nb_max_ant = get_nb_max_ant(s);
            }
          else
            {
              if (s[0] == COMMENT_CHAR)
                {
                  if (strcmp(s, COMMENT_START) == 0)
                    next_line_type = LINE_START;
                  else if (strcmp(s, COMMENT_END) == 0)
                    next_line_type = LINE_END;
                }
              else if (next_line_type == LINE_START)
                {
                  room_start = create_room_start(s, nb_max_ant);
                  all_rooms[nb_all_rooms++] = room_start;
                  next_line_type = LINE_DATA;
                }
              else if (next_line_type == LINE_END)
                {
                  room_end = create_room_end(s, nb_max_ant);
                  all_rooms[nb_all_rooms++] = room_end;
                  next_line_type = LINE_DATA;
                }
              else
                {
                  if (is_line_discribing_a_room(s) == TRUE)
                    all_rooms[nb_all_rooms++] = create_room_inter(s);
                  else
                    {
                      link_room_together(nb_all_rooms, all_rooms, s);
                    }
                }
            }
          i++;
        }
    }
  close_file(fd);
  launch_dijkstra(room_start, room_end, nb_all_rooms, all_rooms);
  display_ant_column_one(room_start, nb_max_ant);
}

void     load_configuration(int argc, char **argv)
{
  readFile(argc, argv);
}
