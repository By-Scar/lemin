CC      = gcc

RM      = rm -f

CFLAGS  += -Wall -pedantic

NAME    = lem_in

SRCS    = sources/main.c \
          sources/config_loader.c \
          sources/analyse_line.c \
          sources/create_room.c \
          sources/utils_malloc.c \
          sources/my_get_next_line.c \
          sources/my_display.c \
          sources/my_strcpy.c \
          sources/my_strncpy.c \
          sources/my_error_exit.c \
          sources/algo.c \
          sources/display.c \
          sources/research.c

OBJS    = $(SRCS:.c=.o)

all: $(NAME) $(NAME2)

$(NAME): $(OBJS)
        $(CC) $(OBJS) -o $(NAME)
clean:
        $(RM) $(OBJS)
fclean:
        $(RM) $(NAME)
re: fclean all
