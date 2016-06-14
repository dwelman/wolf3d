# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsaunder <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/14 09:23:04 by bsaunder          #+#    #+#              #
#    Updated: 2016/06/14 09:26:37 by bsaunder         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = wolf3d

FLAG = -Wall -Wextra -Werror -g

SRC = wolf3d.c draw.c raycast.c controls.c

RM = rm -f

MLX = -lmlx -framework OpenGL -framework AppKit

LIBFT = -L./libft -lft

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re


all: $(NAME)

%.o: %.c
	gcc $(FLAG) -c -o $@ $^ $(INC)

$(NAME): $(OBJ)
		cd libft/ && make
		$(CC) $(FLAG) $(OBJ) -o $(NAME) $(INC) $(MLX) $(LIBFT)


clean:
		$(RM) $(OBJ)
		cd libft/ && make clean

fclean: clean
		$(RM) $(NAME)
		cd libft/ && make fclean

re: fclean all

.PHONY: all clean fclean re
