# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgarczyn <lgarczyn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/22 17:11:22 by lgarczyn          #+#    #+#              #
#    Updated: 2015/06/03 12:16:11 by lgarczyn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mod1

SRC =	main.c \
		math.c \
		math2.c \
		error.c \
		read.c \
		gnl.c \
		update.c \
		color.c \
		hook.c \
		opt.c \
		spin.c \
		turn.c \
		thread.c \
		set.c \
		pixel.c \
		draw.c
		
OBJ = $(SRC:.c=.o)

FLG = -Wall -Werror -Wextra
	
LIB =	-L libft/ -lft \
		-I minilibx_macos \
		-lm -L libft/ -lft -lmlx \
		-framework OpenGL -framework AppKit \
		-lpthread \

DEB = -g

OPT = -O3 -ffast-math

all: $(NAME)

libft:

$(NAME):$(OBJ)
	cd libft && make
	gcc $(FLG) $(OPT) $(OBJ) $(LIB) $(DEB) -o $(NAME)
	
%.o: %.c
	gcc $(FLG) $(OPT) $(DEB) -c $< $  -pthread

clean:
	rm -rf $(OBJ)
	cd libft && make clean

fclean:
	rm -rf $(OBJ)
	rm -rf $(NAME)
	cd libft && make fclean

re: fclean all

optire: fclean opti