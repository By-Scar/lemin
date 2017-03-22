CC      = gcc

RM      = rm -f

CFLAGS  += -Wall -pedantic

NAME    = lem_in

SRCS    = main.c \
          config_loader.c \
          analyse_line.c \
          create_room.c \
          utils_malloc.c \
          my_get_next_line.c \
          my_display.c \
          my_strcpy.c \
          my_strncpy.c \
          my_error_exit.c \
          algo.c \
          display.c \
          research.c

OBJS    = $(SRCS:.c=.o)

all: $(NAME) $(NAME2)

$(NAME): $(OBJS)
        $(CC) $(OBJS) -o $(NAME)
clean:
        $(RM) $(OBJS)
fclean:
        $(RM) $(NAME)
re: fclean all
