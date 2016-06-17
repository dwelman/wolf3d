# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daviwel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/13 07:55:06 by daviwel           #+#    #+#              #
#    Updated: 2016/06/17 15:13:35 by ddu-toit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC = main.c init_info.c keys.c raycasting.c draw_line.c movement.c time.c \
	  mlx_image_put_pixel.c colours.c read_levels.c next_level.c

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
	./wolf3d levels

qr: q run
