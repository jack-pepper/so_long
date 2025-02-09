# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 09:35:38 by mmalie            #+#    #+#              #
#    Updated: 2025/02/09 17:19:18 by mmalie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###################################################
### Name of the file obtained after compilation ###
###################################################

NAME = libstdlib.a

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
DEPS = libstdlib.h

####################
### Source files ###
####################

LIBSTDLIB = ft_atoi.c \
	    ft_atol.c\
	    ft_calloc.c \
	    ft_memdel.c \

SRC = ${LIBSTDLIB}

####################
### Object files ###
####################

OBJ = $(SRC:.c=.o)

### Default rules (compile the executable)
all: $(NAME)
	@echo
	@echo "===================================================================================="
	@echo "                       🔢 💾 🗑️  Compiling LIBSTDLIB...                             "
	@echo "===================================================================================="
	@echo "            L      III  BBBBB  SSSSS  TTTTT  DDDD   L      III  BBBBB               "
	@echo "            L       I   B   B  S        T    D   D  L       I   B   B               "
	@echo "            L       I   BBBB   SSSSS    T    D   D  L       I   BBBB                "
	@echo "            L       I   B   B      S    T    D   D  L       I   B   B               "
	@echo "            LLLLL  III  BBBBB  SSSSS    T    DDDD   LLLLL  III  BBBBB               "
	@echo "===================================================================================="
	@echo "                   L I B S T D L I B   C O M P I L E D!   ♻️  ✅                     "
	@echo "                          Standard functions ready! ⚙️                               "
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

# Rule to recompile everything (execute fclean, then re)
re: fclean all

#########################
### .PHONY Exceptions ###
#########################

.PHONY: all clean fclean re bonus
