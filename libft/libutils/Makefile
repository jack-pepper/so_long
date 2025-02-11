# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 09:35:38 by mmalie            #+#    #+#              #
#    Updated: 2025/02/11 09:09:58 by mmalie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###################################################
### Name of the file obtained after compilation ###
###################################################

NAME = libutils.a

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
DEPS = libutils.h

####################
### Source files ###
####################

LIBUTILS = ft_itoa.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_split.c \
	   ft_strjoin.c \
	   ft_strmapi.c \
	   ft_strtrim.c \
	   ft_substr.c \
	   ft_striteri.c \
	   ft_open_file.c \
	   ft_read_line.c \
	   ft_abs_int.c \
	   ft_init_ints.c \

SRC = ${LIBUTILS}

####################
### Object files ###
####################

OBJ = $(SRC:.c=.o)

### Default rules (compile the executable)
all: $(NAME)
	@echo
	@echo "===================================================================================="
	@echo "                         ⚡ 💡 🔧 Compiling LIBUTILS...                             "
	@echo "===================================================================================="
	@echo "              L       III  BBBBB   U   U  TTTTT  III  L       SSSSS                 "
	@echo "              L        I   B   B   U   U    T     I   L       S                     "
	@echo "              L        I   BBBB    U   U    T     I   L        SSSS                 "
	@echo "              L        I   B   B   U   U    T     I   L           S                 "
	@echo "              LLLLL   III  BBBBB    UUU     T    III  LLLLL   SSSSS                 "
	@echo "===================================================================================="
	@echo "                    L I B U T I L S   C O M P I L E D! 🛠️  ✅                       "
	@echo "                         Utility functions ready! 🚀                                "
	@echo "===================================================================================="

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

#########################
### .PHONY Exceptions ###
#########################

.PHONY: all clean fclean re bonus
