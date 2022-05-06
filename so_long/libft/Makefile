# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybong <ybong@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/28 00:12:32 by ybong             #+#    #+#              #
#    Updated: 2022/02/15 17:33:02 by ybong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = isto_functions/ft_atoi.c\
isto_functions/ft_isalnum.c\
isto_functions/ft_isalpha.c\
isto_functions/ft_isascii.c\
isto_functions/ft_isdigit.c\
isto_functions/ft_isprint.c\
isto_functions/ft_itoa.c\
isto_functions/ft_tolower.c\
isto_functions/ft_toupper.c\
\
lst_functions/ft_lstadd_back.c\
lst_functions/ft_lstadd_front.c\
lst_functions/ft_lstclear.c\
lst_functions/ft_lstdelone.c\
lst_functions/ft_lstiter.c\
lst_functions/ft_lstlast.c\
lst_functions/ft_lstmap.c\
lst_functions/ft_lstnew.c\
lst_functions/ft_lstsize.c\
\
malloc_functions/ft_calloc.c\
malloc_functions/ft_strdup.c\
malloc_functions/ft_substr.c\
\
mem_functions/ft_bzero.c\
mem_functions/ft_memccpy.c\
mem_functions/ft_memchr.c\
mem_functions/ft_memcmp.c\
mem_functions/ft_memcpy.c\
mem_functions/ft_memmove.c\
mem_functions/ft_memset.c\
\
put_fd_functions/ft_putchar_fd.c\
put_fd_functions/ft_putendl_fd.c\
put_fd_functions/ft_putnbr_fd.c\
put_fd_functions/ft_putstr_fd.c\
\
str_functions/ft_split.c\
str_functions/ft_strchr.c\
str_functions/ft_strjoin.c\
str_functions/ft_strlcat.c\
str_functions/ft_strlcpy.c\
str_functions/ft_strlen.c\
str_functions/ft_strmapi.c\
str_functions/ft_strncmp.c\
str_functions/ft_strnstr.c\
str_functions/ft_strrchr.c\
str_functions/ft_strtrim.c


CC = gcc
CFLAGES = -Wall -Wextra -Werror
AR = ar rcs
NAME = libft.a
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@$(AR) $@ $(OBJ)

%.o:%.c
	@$(CC) $(CFLAGES) -c $< -o $@

clean :
	@rm -f ./isto_functions/*.o
	@rm -f ./lst_functions/*.o
	@rm -f ./malloc_functions/*.o
	@rm -f ./mem_functions/*.o
	@rm -f ./put_fd_functions/*.o
	@rm -f ./str_functions/*.o

fclean : clean
	@rm -f $(NAME)

re : fclean all
