CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
NAME = libftprintf.a
FILE = ft_printf.c \
	ft_handling.c \
	ft_handling2.c \
	ft_printf_utils.c \
	ft_printf_type.c \
	ft_printf_num.c \
	ft_printf_count_num.c \
	ft_printf_flagset.c \
	

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
