# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/05 10:55:56 by mmalie            #+#    #+#              #
#    Updated: 2025/01/09 09:38:38 by mmalie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###################################################
### Name of the file obtained after compilation ###
###################################################

NAME = libxkit.a

############################
### Compilation settings ###
############################

CC=cc
CFLAGS=-Wall -Wextra -Werror

AR=ar
ARFLAGS=-rcs

####################
### Dependencies ###
####################

DEPS_LIBFT = ../libft.h
DEPS = ./libxkit.h

####################
### Source files ###
####################

LIBXKIT = mlx_color_toolkit.c \
	    mlx_draw_toolkit.c \

SRC = ${LIBXKIT}

####################
### Object files ###
####################

OBJ = $(SRC:.c=.o)

### Default rules (compile the executable)
all: $(NAME)
	$(info )
	$(info   L       III  BBBBB   X   X  K   K  III  TTTTT   )
	$(info   L        I   B   B    X X   K  K    I     T     )
	$(info   L        I   BBBB      X    KKK     I     T     )
	$(info   L        I   B   B    X X   K  K    I     T     )
	$(info   LLLLL   III  BBBBB   X   X  K   K  III    T     )
	$(info )
	$(info ====================================================)
	$(info       L I B X K I T   C O M P I L E D!              )
	$(info ====================================================)
	$(info )
### Compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

###############################
### Create a static library ###
###############################

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	ranlib $(NAME)

#########################
### Cleaning-up rules ###
#########################

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

# Rule to recompile everything (execute fclean, then re)
re: fclean all

#########################
### .PHONY Exceptions ###
#########################

.PHONY: all clean fclean re bonus
