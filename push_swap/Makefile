CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
SILHANG = push_swap
NAME = libpush_swap.a
FILE = push_swap.c \
		ft_split.c \
		push_spr.c \
		push_spr2.c \
		push_spr3.c \
		push_utils.c \
		push_utils2.c \
		push_utils3.c \
		push_utils4.c \
		push_check.c \
		push_check2.c \
		push_check3.c \
		push_check4.c

OBJECTS = $(FILE:%.c=%.o)

all : $(SILHANG)

$(OBJECTS) : $(FILE)
	$(CC) $(CFLAGS) $(FILE)

$(NAME) : $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

$(SILHANG) : $(NAME) push_swap.c
	gcc push_swap.c -o push_swap -L. -lpush_swap

clean :
	rm -rf $(OBJECTS)

fclean : clean
	rm -rf $(SILHANG) $(NAME)

re : fclean all