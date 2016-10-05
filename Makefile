# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psaint-j <psaint-j@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/04 17:43:28 by psaint-j          #+#    #+#              #
#    Updated: 2016/10/05 18:59:25 by psaint-j         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1
SRC =	./src/sceneConstruct.c\
		./src/vectorFonction.c\
		./src/cameraFonction.c\
		./src/lightFonction.c\
		./src/colorFonction.c\
		./src/sphereFonction.c\
		./src/planeFonction.c\
		./src/rayFonction.c\
		./src/mlxFonction.c\
		./src/saveimgFonction.c\
		./src/materialFonction.c
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LINK_FLAG = -L./mlx -lft -L./libft -lft \
			-lmlx -framework OpenGL -framework AppKit

.PHONY: $(NAME) all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@mkdir obj
	@make -sC libft/
	@make -sC mlx/
	@gcc $(OBJ) -o $(NAME) $(CFLAGS) $(LINK_FLAG) -g3
	@mv $(OBJ) obj
	@echo "RTV1 COMPILATION DONE"

clean:
	@rm -rf obj
	@make clean -sC libft/
	@make clean -sC mlx/
	@rm -rf $(NAME)
	@rm -rf *.o
	@echo "RTV1 CLEAN DONE"

fclean: clean
	@make fclean -sC libft/
	@rm -rf $(NAME)
	@echo "RTV1 FCLEAN DONE"

re: fclean $(NAME)
