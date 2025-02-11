# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 09:35:38 by mmalie            #+#    #+#              #
#    Updated: 2025/02/11 09:11:38 by mmalie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###################################################
### Name of the file obtained after compilation ###
###################################################

NAME = liblist.a

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
DEPS = liblist.h

####################
### Source files ###
####################

LIBLIST = ft_lstnew.c \
	  ft_lstadd_front.c \
	  ft_lstsize.c \
	  ft_lstlast.c \
	  ft_lstadd_back.c \
	  ft_lstdelone.c \
	  ft_lstclear.c \
	  ft_lstmap.c \
	  ft_lstiter.c \

SRC = ${LIBLIST}

####################
### Object files ###
####################

OBJ = $(SRC:.c=.o)

### Default rules (compile the executable)
all: $(NAME)
	@echo
	@echo "====================================================================================" 
	@echo "                         📜 📋 📂 Compiling LIBLIST...                              "
	@echo "===================================================================================="
	@echo "                 L       III  BBBBB   L       III  SSSSS  TTTTT                     "
	@echo "                 L        I   B   B   L        I   S        T                       "
	@echo "                 L        I   BBBB    L        I    SSSS    T                       "
	@echo "                 L        I   B   B   L        I       S    T                       "
	@echo "                 LLLLL   III  BBBBB   LLLLL   III  SSSSS    T                       "
	@echo "===================================================================================="
	@echo "                      L I B L I S T   C O M P I L E D! ➡️  ✅                        "
	@echo "                        Linked lists ready for action! 🔗                           "
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
