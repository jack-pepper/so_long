# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 09:35:38 by mmalie            #+#    #+#              #
#    Updated: 2025/02/07 23:26:14 by mmalie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###################################################
### Name of the file obtained after compilation ###
###################################################

NAME = libgnl.a

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
DEPS = libgnl.h

####################
### Source files ###
####################

LIBGNL = ft_gnl.c \
	 ft_gnl_utils.c \

SRC = ${LIBGNL}

####################
### Object files ###
####################

OBJ = $(SRC:.c=.o)

### Default rules (compile the executable)
all: $(NAME)
	@echo
	@echo "   L       III  BBBBB   GGGG  N   N  L       "
	@echo "   L        I   B   B  G      NN  N  L       "
	@echo "   L        I   BBBB   G  GG  N N N  L       "
	@echo "   L        I   B   B  G   G  N  NN  L       "
	@echo "   LLLLL   III  BBBBB   GGG   N   N  LLLLL   "
	@echo
	@echo "   📖  📜  📝  📂  💾  🔁  ⚡  🔄  🔠  📑  "
	@echo
	@echo "============================================"
	@echo "   L I B G N L   C O M P I L E D!   📚 ✅ "
	@echo "============================================"
	@echo "     Ready to read lines efficiently!  📖 "
	@echo

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
