SRCS = get_next_line.c

CC = gcc
CFLAGES = -Wall -Wextra -Werror
AR = ar rcs
NAME = libgnl.a
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@$(AR) $@ $(OBJS)

$(OBJS) : $(SRCS)
	@$(CC) $(CFLAGES) -c $(SRCS)

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re :
	@fclean all

.PHONY : all clean fclean re