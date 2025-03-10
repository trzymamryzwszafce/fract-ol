cc = cc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = ./minilbx-linux
SRCS = $(wildcard *.c)
INCLUDES = -I$(MLX_DIR)
