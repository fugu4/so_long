NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -Ilibft -Ignl

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	MLX_DIR = minilibx-linux
	MLXFLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
	CFLAGS += -I$(MLX_DIR)
else
	MLX_DIR = minilibx_mms
	MLXFLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
	CFLAGS += -I$(MLX_DIR)
endif

SRCS = main.c \
       read_file.c \
       parse_map.c \
       correct_map.c \
       path_map.c \
       render.c \
       handle_event.c \
       init_games.c \
       gnl/get_next_line.c \
       gnl/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	@echo "📦 Building libft..."
	@$(MAKE) -C libft

$(NAME): $(OBJS) $(LIBFT)
	@echo "🧱 Linking so_long..."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLXFLAGS) -o $(NAME)
	@echo "✅ Build complete!"

clean:
	@echo "🧹 Cleaning object files..."
	@rm -f $(OBJS)
	@$(MAKE) -C libft clean

fclean: clean
	@echo "🗑️  Removing binary files..."
	@rm -f $(NAME)
	@$(MAKE) -C libft fclean

re: fclean all

mlx:
	@echo "🛠️  Building MiniLibX..."
	@$(MAKE) -C $(MLX_DIR)

.PHONY: all clean fclean re mlx
