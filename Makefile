# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 09:35:38 by mmalie            #+#    #+#              #
#    Updated: 2025/02/14 00:15:37 by mmalie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += -s
MAKEFLAGS += --no-print-directory

###################################################
### Name of the file obtained after compilation ###
###################################################

NAME = so_long

############################
### Compilation settings ###
############################

CC=cc
CFLAGS=-g -Wall -Wextra -Werror

####################
### Dependencies ###
####################

DEPS = ./inc/so_long.h \
	./textures/assets.h \
	./libft/libxkit/libxkit.h \
	./libft/libft.h \

LIBFT = ./libft/libft.a
LIBXKIT = ./libft/libxkit/libxkit.a

####################
### Source files ###
####################

SRC = ./src/so_long.c \
      ./src/sl_screens.c \
      ./src/sl_events.c \

### Object files
OBJ = $(SRC:.c=.o)

##############################################
### Default rules (compile the executable) ###
##############################################

all: check_clean_mandatory copy_header_mandatory $(LIBFT) $(NAME)

bonus: check_clean_bonus copy_header_bonus $(LIBFT) $(NAME)

$(LIBFT):	
	@echo "📚 Compiling LIBFT... Shelving functions and indexing pointers..."
	@cd libft && make

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) -Llibft -lft -lm -Llibft/libxkit/.minilibx -lmlx -lXext -lX11 -o $(NAME)

######################################
### Compile .c files into .o files ###
######################################

##$(OBJ): %.o: %.c $(DEPS)
##	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

copy_header_mandatory:
	@if [ ! -f ./libft/libxkit/libxkit.h ] || ! cmp -s ./inc/libxkit.h ./libft/libxkit/libxkit.h; then \
		cp ./inc/libxkit.h ./libft/libxkit/libxkit.h; \
		echo "Loaded: mandatory libxkit.h"; \
		echo "mandatory" > .last_build; \
	fi

copy_header_bonus:
	@if [ ! -f ./libft/libxkit/libxkit.h ] || ! cmp -s ./bonus/libxkit.h ./libft/libxkit/libxkit.h; then \
		cp ./bonus/libxkit.h ./libft/libxkit/libxkit.h; \
		echo "Loaded: bonus libxkit.h"; \
		echo "bonus" > .last_build; \
	fi

######################################
### Check for cleanup necessity ###
######################################

check_clean_mandatory:
	@if [ -f .last_build ] && grep -q "bonus" .last_build; then \
		echo "🔄 Switching from BONUS to MANDATORY. Running fclean..."; \
		$(MAKE) fclean; \
	fi

check_clean_bonus:
	@if [ -f .last_build ] && grep -q "mandatory" .last_build; then \
		echo "🔄 Switching from MANDATORY to BONUS. Running fclean..."; \
		$(MAKE) fclean; \
	fi

#########################
### Cleaning-up rules ###
#########################

clean:
	@echo "🧹 Sweeping away the dust... but leaving the mess behind!"
	@cd libft && make clean
	@rm -f $(OBJ)

fclean: clean
	@echo "🔥 Full wipe! If it was alive, it's gone now."
	@cd libft && make fclean
	@rm -f $(NAME)

re: fclean all

#########################
### .PHONY Exceptions ###
#########################

.PHONY: all clean fclean re bonus
