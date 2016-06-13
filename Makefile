# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daviwel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/13 07:55:06 by daviwel           #+#    #+#              #
#    Updated: 2016/06/13 09:46:21 by daviwel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC = main.c readmap.c init_info.c keys.c

OBJ = $(SRC:.c=.o)

CFLAG = -Wall -Werror -Wextra

ATTACH = -L libft/ -lft -lmlx -framework OpenGL -framework AppKit

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
	norminette $(SRC) wolf.h

q:
	clang -I lbft/ -c $(SRC)
	clang $(CFLAG) -o $(NAME) $(OBJ) $(ATTACH)
	make clean

run:
	./wolf3d map 10 10

qr: q run
