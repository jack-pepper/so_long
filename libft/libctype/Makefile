# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 09:35:38 by mmalie            #+#    #+#              #
#    Updated: 2024/11/14 09:35:45 by mmalie           ###   ########.fr        #
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

OBJ = $(SRC:.c=.o)

### Default rules (compile the executable)
all: $(NAME)

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
