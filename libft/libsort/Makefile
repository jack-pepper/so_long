# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 09:35:38 by mmalie            #+#    #+#              #
#    Updated: 2025/01/05 10:55:56 by mmalie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###################################################
### Name of the file obtained after compilation ###
###################################################

NAME = libsort.a

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
DEPS = ./libsort.h

####################
### Source files ###
####################

LIBSORT_UTILS = ft_swap_ints.c \
		ft_shift_right_ints.c \
		ft_rev_arr_int.c \
		ft_cpy_arr_int.c \

LIBSORT = ft_bub_srt.c \
	    ft_sel_srt.c \
	    ft_ins_srt.c \
	    ft_mrg_srt.c \
	    #ft_qck_srt.c \
	    #ft_hep_srt.c \
	    #ft_rdx_srt.c \

SRC = ${LIBSORT_UTILS} ${LIBSORT}

####################
### Object files ###
####################

OBJ = $(SRC:.c=.o)

### Default rules (compile the executable)
all: $(NAME)
	$(info )
	$(info   L       III  BBBBB   SSSSS  OOOOO  RRRR   TTTTT   )
	$(info   L        I   B   B   S      O   O  R   R    T     )
	$(info   L        I   BBBB    SSSSS  O   O  RRRR     T     )
	$(info   L        I   B   B       S  O   O  R  R     T     )
	$(info   LLLLL   III  BBBBB   SSSSS  OOOOO  R   R    T     )
	$(info )
	$(info ====================================================)
	$(info       L I B S O R T   C O M P I L E D!              )
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
