# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hnogi <hnogi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/06 16:58:06 by hnogi             #+#    #+#              #
#    Updated: 2025/11/02 18:36:55 by hnogi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
NAME	= libft.a

SRC		= ft_printf.c \
		  hex.c \
		  itoa.c \
		  number.c \
		  utoa.c \
		  ft_atoi.c \
		  ft_strlen.c \
		  ft_strncmp.c \
		  ft_strjoin.c \
		  ft_strdup.c \
		  ft_strchr.c \
		  ft_putstr_fd.c \
		  ft_putchar_fd.c \
		  ft_calloc.c \
		  ft_split.c \

OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
