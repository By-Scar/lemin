#ifndef MY_DISPLAY_H_
# define MY_DISPLAY_H_

#include <unistd.h>
#include "my_error_exit.h"

void    my_putchar(char c);
void    my_putstr(char *str);
int     my_strlen(char *str);
int     my_puterr(char *str);

#endif /* !MY_DISPLAY_H_ */
