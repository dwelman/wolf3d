# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daviwel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/13 07:55:06 by daviwel           #+#    #+#              #
#    Updated: 2016/06/13 08:55:02 by daviwel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC = main.c readmap.c init_info.c

OBJ = $(SRC:.c=.o)

CFLAG = -Wall -Werror -Wextra

ATTACH = -L libft/ -lft -lmx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
	make -C libft/ fclean
	make -C libft/
	clang $(CFLAG) -I lbft/ -c $(SRC)
	clang $(CFLAG) -o $(NAME) $(OBJ) $(ATTACH)

clean:
	/bin/rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft/ fclean

re: fclean all

norme:
	norminette $(SRC) wolf3d.h

q:
	clang -I lbft/ -c $(SRC)
	clang $(CFLAG) -o $(NAME) $(OBJ) -L libft/ -lft
	make clean
