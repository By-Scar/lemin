#ifndef MY_GET_NEXT_LINE_H_
# define MY_GET_NEXT_LINE_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my_display.h"

#define BUFFER_SIZE             4096
# define ERR_MALLOC_GNL         "GetNextLine error: malloc failed !"
#  define ERR_CTRLD             "CTRL-D received, the program will be closed!\n"
#   define ERR_GNL_FD           "GetNextLine error: can't read this fd.\n"
#    define ERR_WRITE           "Write error.\n"

int     my_len(char *str, int x);
char    *my_cpy(char *dest, char *src, int i);
char    *my_zerofd();
char    *my_gnl(char *buffer);
char    *get_next_line(int fd);
char    *my_strncpy(char *dest, char *src, int n);
char    *my_strcpy(char *dest, char *src);

#endif /*  !MY_GET_NEXT_LINE_H_ */
