CC = gcc
CFLAGS = -Wall -Wextra -Werror

EXE = music

SRC = \
	Jour04/Job02/print_album.c \
	Jour04/Job03/realloc_album.c \
	Jour04/Job04/create_album.c \
	Jour04/Job05/push_back_album.c \
	Jour04/Job06/push_front_album.c \
	Jour04/Job07/album_del_one.c \
	Jour04/Job08/sort_album_by.c \
	Jour05/Job01/main.c

OBJ = $(SRC:.c=.o)

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(OBJ) -o $(EXE)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXE) $(EXE).exe

run: all
	./$(EXE)

.PHONY: all clean fclean run
