CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
SILHANG = server
SILHANG2 = client
S_FILE = server.c
C_FILE = client.c

S_OBJECTS = $(S_FILE:%.c=%.o)
C_OBJECTS = $(C_FILE:%.c=%.o)

all : $(SILHANG) $(SILHANG2)

$(S_OBJECTS) : $(S_FILE)
	$(CC) $(CFLAGS) $(S_FILE)

$(C_OBJECTS) : $(C_FILE)
	$(CC) $(CFLAGS) $(C_FILE)

$(SILHANG) : $(S_OBJECTS)
	$(CC) -o $(SILHANG) $(S_OBJECTS)

$(SILHANG2) : $(C_OBJECTS)
	$(CC) -o $(SILHANG2) $(C_OBJECTS)

clean :
	rm -rf $(S_OBJECTS) $(C_OBJECTS)

fclean : clean
	rm -rf $(SILHANG) $(SILHANG2)

re : fclean all