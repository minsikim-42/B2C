CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
NAME = libftprintf.a
FILE = ft_printf.c \
handling.c \
ft_printf_utils.c \
ft_printf_type.c
		

OBJECTS = $(FILE:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

clean :
	rm -rf $(OBJECTS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
