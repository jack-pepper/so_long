# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 09:35:38 by mmalie            #+#    #+#              #
#    Updated: 2024/12/27 17:15:23 by mmalie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###################################################
### Name of the file obtained after compilation ###
###################################################

NAME = so_long

############################
### Compilation settings ###
############################

CC=cc
CFLAGS=-g -Wall -Wextra -Werror

####################
### Dependencies ###
####################

DEPS = so_long.h \
	mlx_draw_toolkit.h \
	mlx_color_toolkit.h \
	./libft/libft.h \
#DEPS_LIBFT = ./libft/libft.h
LIBFT = ./libft/libft.a

####################
### Source files ###
####################

SRC = so_long.c \
	mlx_draw_toolkit.c \
	mlx_color_toolkit.c \
	event_handler.c \

### Object files
OBJ = $(SRC:.c=.o)

##############################################
### Default rules (compile the executable) ###
##############################################

all: $(LIBFT) $(NAME)

$(LIBFT):
	cd libft && make

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) -Llibft -lft -lm -Lminilibx -lmlx -lXext -lX11 -o $(NAME)

######################################
### Compile .c files into .o files ###
######################################

$(OBJ): %.o: %.c $(DEPS) $(DEPS_LIBFT)
	$(CC) $(CFLAGS) -c $< -o $@

#########################
### Cleaning-up rules ###
#########################

clean:
	cd libft && make clean
	rm -f $(OBJ)

fclean: clean
	cd libft && make fclean
	rm -f $(NAME)

re: fclean all

#########################
### .PHONY Exceptions ###
#########################

.PHONY: all clean fclean re bonus
