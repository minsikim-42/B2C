CC = gcc
CFLAGS = -Wall -Wextra -Werror
SILHANG = so_long
SILHANG_BONUS = so_long_bonus
LIB = so_long.a
MAIN = so_long_m.c
BONUS_MAIN = bonus.c
BONUS_FILE = mapparsing_bonus.c \
			bonus2.c \
			bonus3.c \
			bonus4.c

FILE = mapparsing_m.c \
		mapparsing2_m.c \
		so_long2_m.c

all : $(SILHANG) $(SILHANG_BONUS)

# $(OBJECTS) : $(FILE) $(MAIN)
# 	$(CC) $(CFLAGS) $(MAIN) $(FILE)

# $(LIB) : $(OBJECTS)
# 	ar rcs $(LIB) $(OBJECTS)
#  $(LIB)
$(SILHANG) :
	gcc -g3 -L./minilibx_opengl_20191021 -lmlx -framework OpenGL -framework Appkit $(CFLAGS) $(MAIN) $(FILE) -o so_long -L. -lgnl -I.

$(OBJECTS_BONUS) : $(BONUS_FILE)
	$(CC) $(CFLAGS) $(BONUS_FILE)

bonus : $(OBJECTS_BONUS)
	gcc -g3 -L./minilibx_opengl_20191021 -lmlx -framework OpenGL -framework Appkit -o $(BONUS_FILE) $(BONUS_MAIN) -L. -lgnl -I.

# bonus : $(OBJECTS_BONUS)
# 	gcc -g3 -L./minilibx_opengl_20191021 -lmlx -framework OpenGL -framework Appkit -o $(BONUS_MAIN) $(OBJECTS_BONUS) $(SILHANG_BONUS) -L. -lgnl -I.

clean :
	rm -rf $(OBJECTS) $(OBJECTS_BONUS)

fclean : clean
	rm -rf $(SILHANG)

re : fclean all

.PHONY : bonus