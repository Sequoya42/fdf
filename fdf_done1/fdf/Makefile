#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/04 14:27:29 by rbaum             #+#    #+#              #
#    Updated: 2015/02/05 20:20:32 by rbaum            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY: clean, fclean, re

CC = gcc

CFLAG = -Wall -Wextra -Werror

NAME = ./exe

SRC = 	./srcs/draw.c\
		./srcs/ft_coord.c\
		./srcs/ft_put_pixel.c\
		./srcs/main.c\

OBJ = $(subst srcs/,, $(SRC:.c=.o))

LIBFT = libft/

MLX = -L/usr/x11/lib -lmlx -lXext -lX11 
XLIB = -I /opt/X11/include/X11 

all:    $(NAME)

$(NAME): 
		@make -k -s -C $(LIBFT)
		@$(CC) $(CFLAG) -I ./ -I  $(LIBFT)  -c $(SRC) $(XLIB)
		@$(CC) $(CFLAG) -L $(LIBFT) -lft -o $(NAME)  $(OBJ) $(MLX)

clean:	
		@rm -f  $(OBJ)
		@make -C $(LIBFT) clean

fclean: 
		@rm -f  $(OBJ)	
		@rm -f $(NAME)
		@make -C $(LIBFT) fclean

re:		fclean all

