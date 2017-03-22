#ifndef UTILS_MALLOC_H_
# define UTILS_MALLOC_H_

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include "my_display.h"

void    *xmalloc(unsigned int size);

#endif /* !UTILS_MALLOC_H_ */
