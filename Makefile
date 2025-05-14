# Compiler
CC = cc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -I includes -I libft -I $(MLX_DIR)

# Executable Name
NAME = fract_ol

# Source Files (all .c files in the current directory)
SRCS = $(wildcard *.c)

# Object Files
OBJS = $(SRCS:.c=.o)

# MiniLibX
MLX_DIR = ./minilibx-linux
MLX_LIB = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

# Libft
LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_LNK = -L$(LIBFT_DIR) -lft

# Default target
all: $(MLX_DIR)/libmlx.a $(LIBFT_LIB) $(NAME)

# Build executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_LIB) $(LIBFT_LNK)

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Build MiniLibX
$(MLX_DIR)/libmlx.a:
	make -C $(MLX_DIR)

# Build Libft
$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

# Clean object files
clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean

# Remove executables and object files
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re

