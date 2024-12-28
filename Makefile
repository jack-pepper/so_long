# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 09:35:38 by mmalie            #+#    #+#              #
#    Updated: 2024/12/28 21:49:42 by mmalie           ###   ########.fr        #
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

DEPS = ./inc/so_long.h \
	./inc/assets.h \
	./lib/libxkit/mlx_draw_toolkit.h \
	./lib/libxkit/mlx_color_toolkit.h \
	./lib/libft/libft.h \
#DEPS_LIBFT = ./libft/libft.h
LIBFT = ./lib/libft/libft.a

####################
### Source files ###
####################

SRC = ./src/so_long.c \
	./src/event_handler.c \
	./lib/libxkit/mlx_draw_toolkit.c \
	./lib/libxkit/mlx_color_toolkit.c \

### Object files
OBJ = $(SRC:.c=.o)

##############################################
### Default rules (compile the executable) ###
##############################################

all: $(LIBFT) $(NAME)

$(LIBFT):
	cd lib/libft && make

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) -Llib/libft -lft -lm -Lminilibx -lmlx -lXext -lX11 -o $(NAME)

######################################
### Compile .c files into .o files ###
######################################

$(OBJ): %.o: %.c $(DEPS) $(DEPS_LIBFT)
	$(CC) $(CFLAGS) -c $< -o $@

#########################
### Cleaning-up rules ###
#########################

clean:
	cd lib/libft && make clean
	rm -f $(OBJ)

fclean: clean
	cd lib/libft && make fclean
	rm -f $(NAME)

re: fclean all

#########################
### .PHONY Exceptions ###
#########################

.PHONY: all clean fclean re bonus
