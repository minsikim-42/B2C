CFLAGS = -Wall -Wextra -Werror
SILHANG = so_long
SILHANG_BONUS = so_long_bonus
LIB = so_long.a
MAIN = so_long_m.c
FILE = mapparsing_m.c \
		mapparsing2_m.c \
		so_long2_m.c
BONUS_MAIN = bonus.c
BONUS_FILE = mapparsing_bonus.c \
			bonus2.c \
			bonus3.c \
			bonus4.c

# gcc -g3 -L./minilibx_opengl_20191021 -lmlx -framework OpenGL -framework Appkit -fsanitize=address $(CFLAGS) $(MAIN) $(FILE) -o $(SILHANG) -L. -lgnl -I.
$(SILHANG) : $(FILE) $(MAIN)
	gcc -L./minilibx_opengl_20191021 -lmlx -framework OpenGL -framework Appkit -g3 $(CFLAGS) $(MAIN) $(FILE) -o $(SILHANG) -L./get_next_line -lgnl -L./libft -lft -I.

$(SILHANG_BONUS) : $(BONUS_FILE) $(BONUS_MAIN)
	gcc -L./minilibx_opengl_20191021 -lmlx -framework OpenGL -framework Appkit -g3 $(CFLAGS) $(BONUS_FILE) $(BONUS_MAIN) -o $(SILHANG_BONUS) -L./get_next_line -lgnl -L./libft -lft -I.

all : $(SILHANG)

bonus : $(SILHANG_BONUS) $(SILHANG)

clean :
	rm -rf $(OBJECTS) $(OBJECTS_BONUS)

fclean : clean
	rm -rf $(SILHANG) $(SILHANG_BONUS)

re : fclean all

.PHONY : all clean fclean bonus