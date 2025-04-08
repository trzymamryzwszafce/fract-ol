CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rf -f

MLX_DIR = ./minilbx-linux
SRC = $(wildcard *.c)
INCLUDES = -I$(MLX_DIR)
OBJ = $(SRC:.c=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
