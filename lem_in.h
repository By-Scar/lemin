#ifndef LEM_IN_H_
# define LEM_IN_H_

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include "my_get_next_line.h"
#include "utils_malloc.h"
#include "my_error_exit.h"
#include "my_display.h"

#  define COMMENT_CHAR                          '#'
#   define COMMENT_START                        "##start"
#    define COMMENT_END                         "##end"
#     define LINE_START                         1
#      define LINE_END                          2
#       define LINE_DATA                        3
#        define DATA_ROOM_SEPARATOR_STRING      " "
#         define DATA_ROOM_SEPARATOR_CHAR       ' '
#          define DATA_LINK_SEPARATOR_STRING    "-"
#           define NO_ANT                       0
#            define ROOM_INTER_MAX_ANT          1
#             define FALSE                      0
#              define TRUE                      1
#               define MASS_NULL                -1
#                define MASS_START              0
#                 define MASS_PATH              1
#                  define SIZE                  8192

typedef struct  t_room_param
{
  char          *name;
  int           x;
  int           y;
}               t_room_param;

typedef struct  t_room_link
{
  char          *name_room_one;
  char          *name_room_two;
}               t_room_link;

typedef struct          t_room
{
  char                  *name;
  int                   x;
  int                   y;
  int                   nb_ant;
  int                   nb_ant_max;
  int                   nb_liens;
  struct t_room         *links[SIZE];
  int                   mass;
  int                   analyzed;
  struct t_room         *father;
  struct t_room         *child;
  int                   display;
}                       t_room;

void            readFile(int argc, char **argv);
t_room          *create_room(t_room_param *current_param,
                             int nb_ant, int nb_max_ant, int mass);
t_room          *create_room_start(char *str, int nb_max_ant);
t_room          *create_room_end(char *str, int nb_max_ant);
t_room          *create_room_inter(char *str);
t_room          *find_thelightest_room(int nb_all_rooms, t_room **all_rooms);
void            update_room_mass(t_room *parent_room, t_room *linked_room);
void            analyse_room_links(t_room *room);
void            find_path_from_start_to_end(t_room *room_start, t_room *room_end);
void            launch_dijkstra(t_room *start_room, t_room *end_room,
                                int nb_all_rooms, t_room **all_rooms);
void            load_configuration(int argc, char **argv);
t_room_param    *analyse_line_conf_room(char *str);
t_room_link     *analyse_line_conf_link(char *str);
void            display_ant_column_one(t_room *room_start, int nb_max_ant);
void            close_file(int fd);
void            read_with_strcmp(char *s, int next_line_type);
void            line_inter_and_line(char *s,
                                    int nb_all_rooms, t_room *all_rooms[SIZE]);
void            read_comment_char(char *s, int next_line_type,
                                  int nb_all_rooms, t_room *all_rooms[SIZE], int nb_max_ant,
                                  t_room room_start, t_room room_end);
void            read_buffer(int nb_max_ant, char *s, int i,
                            t_room *all_rooms[SIZE], int nb_all_rooms,
                            int next_line_type, t_room room_start, t_room room_end);
int             is_line_discribing_a_room(char *str);
int             link_room_together(int nb_all_rooms, t_room **all_rooms, char *str);
int             get_nb_max_ant(char *str);
t_room          *research_room(int nb_all_rooms, t_room **all_rooms,
                               char *rooms_anme);

#endif /* !LEM_IN_H_ */
