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
	   handle_key.c \
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
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hnogi <hnogi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/05 17:00:00 by hnogi             #+#    #+#              #
#    Updated: 2025/11/05 17:00:00 by hnogi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -Ilibft -Ignl

# OS detection
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

# Source files
SRCS = main.c \
       read_file.c \
       parse_map.c \
       correct_map.c \
       path_map.c \
       render.c \
       handle_event.c \
       handle_key.c \
       init_games.c \
       cleanup.c \
       gnl/get_next_line.c \
       gnl/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a

# Colors
GREEN = \033[0;32m
BLUE = \033[0;34m
RED = \033[0;31m
RESET = \033[0m

# Rules
all: $(LIBFT) $(NAME)

$(LIBFT):
	@echo "$(BLUE)📦 Building libft...$(RESET)"
	@$(MAKE) -C libft

$(NAME): $(OBJS) $(LIBFT)
	@echo "$(BLUE)🧱 Linking so_long...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLXFLAGS) -o $(NAME)
	@echo "$(GREEN)✅ Build complete!$(RESET)"

%.o: %.c
	@echo "$(BLUE)🔨 Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)🧹 Cleaning object files...$(RESET)"
	@rm -f $(OBJS)
	@$(MAKE) -C libft clean

fclean: clean
	@echo "$(RED)🗑️  Removing binary files...$(RESET)"
	@rm -f $(NAME)
	@$(MAKE) -C libft fclean

re: fclean all

mlx:
	@echo "$(BLUE)🛠️  Building MiniLibX...$(RESET)"
	@$(MAKE) -C $(MLX_DIR)

norm:
	@echo "$(BLUE)📏 Checking Norm...$(RESET)"
	@norminette $(SRCS) so_long.h

.PHONY: all clean fclean re mlx norm
