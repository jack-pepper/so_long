# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/05 10:55:56 by mmalie            #+#    #+#              #
#    Updated: 2025/02/15 19:59:04 by mmalie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###################################################
### Name of the file obtained after compilation ###
###################################################

NAME = libxkit.a

############################
### Compilation settings ###
############################

CC=cc
CFLAGS=-Wall -Wextra -Werror

AR=ar
ARFLAGS=-rcs

###########################
### MiniLibX repository ###
###########################

MLX_DIR = ./.minilibx
MLX_LIB = $(MLX_DIR)/libmlx.a

####################
### Dependencies ###
####################

DEPS_LIBFT = ../libft.h \
DEPS =	./libxkit.h \
	./libxkit_structs.h \

INCLUDES = -I $(MLX_DIR) -I ./includes

####################
### Source files ###
####################

LIBXKIT = ./mlx_background_render_toolkit.c \
	./mlx_camera_toolkit.c \
	./mlx_collisions_toolkit.c \
	./mlx_color_toolkit.c \
	./mlx_draw_toolkit.c \
	./mlx_enemy_init_toolkit.c \
	./mlx_enemy_movement_toolkit.c \
	./mlx_enemy_render_toolkit.c \
	./mlx_event_on_motion.c \
	./mlx_hero_init_toolkit.c \
	./mlx_hero_render_toolkit.c \
	./mlx_input_toolkit.c \
	./mlx_loop_toolkit.c \
	./mlx_map_init_toolkit.c \
	./mlx_map_parser_toolkit.c \
	./mlx_map_render_toolkit.c \
	./mlx_map_validator_toolkit.c \
	./mlx_map_validator_flood_count.c \
	./mlx_memfree_toolkit.c \
	./mlx_memfree_enemies_toolkit.c \
	./mlx_paths_to_assets_toolkit.c \
	./mlx_pixel_toolkit.c \
	./mlx_state_init_toolkit.c \
	./mlx_tileset_toolkit.c \
	./mlx_ui_toolkit.c \
	./mlx_utils_toolkit.c \

SRC = $(LIBXKIT)

####################
### Object files ###
####################

OBJ_DIR = ./obj

##OBJ = $(SRC:.c=.o)

OBJ = $(patsubst %.c,$(OBJ_DIR)/%.o, $(SRC))

### Default rules (compile the executable)
all: $(NAME)
	@echo
	@echo "===================================================================================="
	@echo "                         🖥️ 🎨 🎮 Compiling LIBXKIT...                              "
	@echo "===================================================================================="	
	@echo "                  L       III  BBBBB  X   X  K   K  III  TTTTT                      "
	@echo "                  L        I   B   B   X X   K  K    I     T                        "
	@echo "                  L        I   BBBB     X    KKK     I     T                        "
	@echo "                  L        I   B   B   X X   K  K    I     T                        "
	@echo "                  LLLLL   III  BBBBB  X   X  K   K  III    T                        "
	@echo "===================================================================================="
	@echo "                    L I B X K I T   C O M P I L E D! 👾 ✅                          "
	@echo "                         Press [Start] to Play!  🕹️                                 "
	@echo "===================================================================================="

###############################
### Create a static library ###
###############################

$(NAME): | $(MLX_LIB) $(OBJ_DIR) $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	ranlib $(NAME)

### Compile .c files into .o files and store in ./obj
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ 

### Create ./obj folder if missing
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

### Build MiniLibx
$(MLX_LIB):
	make -C $(MLX_DIR)

#########################
### Cleaning-up rules ###
#########################

clean:
	rm -f $(OBJ)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

# Rule to recompile everything (execute fclean, then re)
re: fclean all

#########################
### .PHONY Exceptions ###
#########################

.PHONY: all clean fclean re bonus
