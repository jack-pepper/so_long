# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/05 10:55:56 by mmalie            #+#    #+#              #
#    Updated: 2025/02/09 17:49:14 by mmalie           ###   ########.fr        #
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

### MLX_REPO = https://github.com/42Paris/minilibx-linux.git
MLX_DIR = ./.minilibx
MLX_LIB = $(MLX_DIR)/libmlx.a

####################
### Dependencies ###
####################

DEPS_LIBFT = ../libft.h \
DEPS =	./libxkit.h \
	./libxkit_structs.h \
#	./mlx_ai_toolkit.h \
#	./mlx_anim_toolkit.h \
#	./mlx_audio_toolkit.h \
#	./mlx_background_render_toolkit.h \
#	./mlx_camera_toolkit.h \
#	./mlx_collisions_toolkit.h \
#	./mlx_color_toolkit.h \
#	./mlx_debug_toolkit.h \
#	./mlx_draw_toolkit.h \
#	./mlx_event_on_motion.h \
#	./mlx_hero_init.toolkit.h \
#	./mlx_hero_render_toolkit.h \
#	./mlx_input_toolkit.h \
#	./mlx_loop_toolkit.h \
#	./mlx_map_init_toolkit.h \
#	./mlx_map_render_toolkit.h \
#	./mlx_map_parser_toolkit.h \
#	./mlx_map_validator_toolkit.h \
#	./mlx_map_validator_flood_count.h \
#	./mlx_memfree_toolkit.h \
#	./mlx_particles_toolkit.h \
#	./mlx_physics_toolkit.h \
#	./mlx_pixel_toolkit.h \
#	./mlx_state_init_toolkit.h \
#	./mlx_tileset_toolkit.h \
#	./mlx_ui_toolkit.h \
#	./mlx_utils_toolkit.h \

INCLUDES = -I $(MLX_DIR) -I ./includes

####################
### Source files ###
####################

LIBXKIT = ./mlx_ai_toolkit.c \
	./mlx_anim_toolkit.c \
	./mlx_audio_toolkit.c \
	./mlx_background_render_toolkit.c \
	./mlx_camera_toolkit.c \
	./mlx_collisions_toolkit.c \
	./mlx_color_toolkit.c \
	./mlx_debug_toolkit.c \
	./mlx_draw_toolkit.c \
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
	./mlx_particles_toolkit.c \
	./mlx_physics_toolkit.c \
	./mlx_pixel_toolkit.c \
	./mlx_state_init_toolkit.c \
	./mlx_tileset_toolkit.c \
	./mlx_ui_toolkit.c \
	./mlx_utils_toolkit.c \

SRC = $(LIBXKIT)

####################
### Object files ###
####################

OBJ = $(SRC:.c=.o)

### Default rules (compile the executable)
all: $(NAME)
	@echo
	@echo "===================================================================================="
	@echo "                         🖥️ ⚙️  🎮 Compiling LIBXKIT...                              "
	@echo "===================================================================================="	
	@echo "                  L       III  BBBBB  X   X  K   K  III  TTTTT                      "
	@echo "                  L        I   B   B   X X   K  K    I     T                        "
	@echo "                  L        I   BBBB     X    KKK     I     T                        "
	@echo "                  L        I   B   B   X X   K  K    I     T                        "
	@echo "                  LLLLL   III  BBBBB  X   X  K   K  III    T                        "
	@echo "===================================================================================="
	@echo "                    L I B X K I T   C O M P I L E D!   👾 ✅                        "
	@echo "                         Press [Start] to Play!  🕹️                                 "
	@echo "===================================================================================="

### Compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

### Download and build MiniLibX if not already present
$(MLX_LIB):
	make -C $(MLX_DIR)
###	if [ ! -d "$(MLX_DIR)" ]; then \
###		git clone $(MLX_REPO) $(MLX_DIR); \
###	fi
###	make -C $(MLX_DIR)

###############################
### Create a static library ###
###############################

$(NAME): $(MLX_LIB) $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	ranlib $(NAME)

#########################
### Cleaning-up rules ###
#########################

clean:
	rm -f $(OBJ)
#	if [ -d "$(MLX_DIR)" ]; then rm -rf $(MLX_DIR); fi

fclean: clean
	rm -f $(NAME)

# Rule to recompile everything (execute fclean, then re)
re: fclean all

#########################
### .PHONY Exceptions ###
#########################

.PHONY: all clean fclean re bonus
