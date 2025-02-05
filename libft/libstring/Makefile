# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmalie <mmalie@student.42nice.fr           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 09:35:38 by mmalie            #+#    #+#              #
#    Updated: 2025/01/02 12:35:05 by mmalie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###################################################
### Name of the file obtained after compilation ###
###################################################

NAME = libstring.a

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
DEPS = libstring.h

####################
### Source files ###
####################

LIBSTRING = ft_bzero.c \
	    ft_memchr.c \
	    ft_memcmp.c \
	    ft_memcpy.c \
	    ft_memmove.c \
	    ft_memset.c \
	    ft_strchr.c \
	    ft_strdel.c \
	    ft_strdup.c \
	    ft_strlcat.c \
	    ft_strlcpy.c \
	    ft_strlen.c \
	    ft_strncmp.c \
	    ft_strnew.c \
	    ft_strnopbrk.c \
	    ft_strnstr.c \
	    ft_strpbrk.c \
	    ft_strrchr.c \
	    ft_strrev.c \

SRC = ${LIBSTRING}

####################
### Object files ###
####################

OBJ = $(SRC:.c=.o)

### Default rules (compile the executable)
all: $(NAME)
	$(info )
	$(info   L       III  BBBBB   SSSSS  TTTTT  RRRR   III  N   N  GGGG   )
	$(info   L        I   B   B   S        T    R   R   I   NN  N  G       )
	$(info   L        I   BBBB    SSSSS    T    RRRR    I   N N N  G  GG   )
	$(info   L        I   B   B      S     T    R  R    I   N  NN  G   G   )
	$(info   LLLLL   III  BBBBB   SSSSS    T    R   R  III  N   N  GGGG    )
	$(info )
	$(info ================================================================)
	$(info       L I B S T R I N G   C O M P I L E D!                      )
	$(info ================================================================)
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
