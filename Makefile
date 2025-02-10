# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 09:35:38 by mmalie            #+#    #+#              #
#    Updated: 2025/02/11 00:08:06 by mmalie           ###   ########.fr        #
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
	./textures/assets.h \
	./libft/libxkit/libxkit.h \
	./libft/libft.h \

LIBFT = ./libft/libft.a
LIBXKIT = ./libft/libxkit/libxkit.a
#TEXTURES_SRC = ./textures/
#TEXTURES_DEST = ./libft/libxkit/textures/

####################
### Source files ###
####################

SRC = ./src/so_long.c \
      ./src/sl_screens.c \
      ./src/sl_events.c \
      ./src/sl_ice_level.c \
      ./src/sl_sand_level.c \
      ./src/sl_pacman_level.c \

### Object files
OBJ = $(SRC:.c=.o)

##############################################
### Default rules (compile the executable) ###
##############################################

all: $(LIBFT) $(NAME)

$(LIBFT):
	@cd libft && make

##copy_textures:
##	@mkdir -p $(TEXTURES_DEST)
##	@cp -r $(TEXTURES_SRC)/* $(TEXTURES_DEST)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) -Llibft -lft -lm -Llibft/libxkit/.minilibx -lmlx -lXext -lX11 -o $(NAME)

######################################
### Compile .c files into .o files ###
######################################

$(OBJ): %.o: %.c $(DEPS)
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
#	rm -rf $(TEXTURES_DEST)

re: fclean all

#########################
### .PHONY Exceptions ###
#########################

.PHONY: all clean fclean re bonus
