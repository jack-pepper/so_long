# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 09:35:38 by mmalie            #+#    #+#              #
#    Updated: 2025/02/11 09:05:49 by mmalie           ###   ########.fr        #
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
	@echo
	@echo "====================================================================================" 
	@echo "                         🔠 🔢 🔣 Compiling LIBCTYPE...                             "
	@echo "===================================================================================="
	@echo "               L       III  BBBBB   CCCC  TTTTT  Y   Y  PPPP   EEEEE                "
	@echo "               L        I   B   B  C        T     Y Y   P   P  E                    "
	@echo "               L        I   BBBB   C        T      Y    PPPP   EEEE                 "
	@echo "               L        I   B   B  C        T      Y    P      E                    "
	@echo "               LLLLL   III  BBBBB   CCCC    T      Y    P      EEEEE                "
	@echo "===================================================================================="
	@echo "                     L I B C T Y P E   C O M P I L E D! 🆗  ✅                      "
	@echo "                            Ready to check types! 🔍                                "
	@echo "===================================================================================="

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
