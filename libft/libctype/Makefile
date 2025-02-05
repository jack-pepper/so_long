# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 09:35:38 by mmalie            #+#    #+#              #
#    Updated: 2024/12/29 01:19:36 by mmalie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###################################################
### Name of the file obtained after compilation ###
###################################################

NAME = libctype.a

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
DEPS = libctype.h

####################
### Source files ###
####################

LIBCTYPE = ft_isalpha.c \
	   ft_isdigit.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_ispunct.c \
	   ft_isspace.c \
	   ft_isupper.c \
	   ft_islower.c \
           ft_toupper.c \
	   ft_tolower.c \

SRC = ${LIBCTYPE}

####################
### Object files ###
####################

all: $(NAME)
	$(info )
	$(info   L       III  BBBBB   CCCC  TTTTT  Y   Y  PPPP  EEEEE   )
	$(info   L        I   B   B  C        T    Y   Y  P   P E       )
	$(info   L        I   BBBB   C        T     Y Y   PPPP  EEEE    )
	$(info   L        I   B   B  C        T      Y    P     E       )
	$(info   LLLLL   III  BBBBB   CCCC    T      Y    P     EEEEE   )
	$(info )
	$(info =========================================================)
	$(info              L I B C T Y P E   C O M P I L E D!          )
	$(info =========================================================)

OBJ = $(SRC:.c=.o)

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

re: fclean all

########################
# .PHONY Exceptions  ###
########################
.PHONY: all clean fclean re bonus
