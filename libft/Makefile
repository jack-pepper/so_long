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

NAME = libft.a

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

DEPS = libft.h

####################
### Source files ###
####################

LIBRARY_DIRS = libctype \
	       libstring \
	       libstdlib \
	       libutils \
	       liblist \
	       libprintf \
	       libgnl \
	       libbin \

LIBFT = ./libctype/libctype.a \
	./libstring/libstring.a \
	./libstdlib/libstdlib.a \
	./libutils/libutils.a \
	./liblist/liblist.a \
       	./libprintf/libprintf.a \
	./libgnl/libgnl.a \
	./libbin/libbin.a \

####################
### Object files ###
####################

### Default rules (compile the executable)
all: $(NAME)

### Create a static library
$(NAME):
	cd libctype && make
	ar x libctype/libctype.a
	cd libstring && make
	ar x libstring/libstring.a
	cd libstdlib && make
	ar x libstdlib/libstdlib.a
	cd libutils && make
	ar x libutils/libutils.a
	cd liblist && make
	ar x liblist/liblist.a
	cd libprintf && make
	ar x libprintf/libprintf.a
	cd libgnl && make
	ar x libgnl/libgnl.a
	cd libbin && make
	ar x libbin/libbin.a
	$(AR) $(ARFLAGS) $(NAME) *.o
	rm *.o
	ranlib $(NAME)

#########################
### Cleaning-up rules ###
#########################

clean:
	$(foreach dir, $(LIBRARY_DIRS), $(MAKE) -C $(dir) clean;)

fclean: clean
	rm -f $(NAME)

re: fclean all

#########################
### .PHONY Exceptions ###
#########################

.PHONY: all clean fclean re bonus
