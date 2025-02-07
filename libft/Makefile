# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 09:35:38 by mmalie            #+#    #+#              #
#    Updated: 2025/02/07 23:51:01 by mmalie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += -s
MAKEFLAGS += --no-print-directory

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
	       libsort \
	       libxkit \

LIBFT = ./libctype/libctype.a \
	./libstring/libstring.a \
	./libstdlib/libstdlib.a \
	./libutils/libutils.a \
	./liblist/liblist.a \
       	./libprintf/libprintf.a \
	./libgnl/libgnl.a \
	./libbin/libbin.a \
	./libsort/libsort.a \
	./libxkit/libxkit.a \

####################
### Object files ###
####################

### Default rules (compile the executable)
all: $(NAME)
all:
	@echo "============================================================="
	@echo "      🚀 🔥 📜 💡 🎮 🖥️ 👾 🔢 💾 🛠️ 🔗 🖨️ 💾 📊 🔍 ⚙️  🎯"
	@echo "============================================================="
	@echo ""
	@echo "   *      L       III  BBBBB   FFFFF  TTTTT     *   " 
	@echo "          L        I   B   B   F        T           "
	@echo "      *   L        I   BBBB    FFFF     T    *      "
	@echo "          L        I   B   B   F        T           "
	@echo "   *      LLLLL   III  BBBBB   F        T       *   "
	@echo ""        
	@echo "============================================================="
	@echo "========== 🏆 LIBFT - The Ultimate C Library 🏆 =========="
	@echo "============================================================="
	@echo ""
	@echo "         :::      ::::::::  |     .-\"\"\"\"\"\"\"\"\"\"-.   "  
	@echo "       :+:      :+:    :+:       /    Marvin   \\  "  
	@echo "     +:+ +:+         +:+    |   |  .-.     .-. |  "  
	@echo "   +#+  +:+       +#+           | (o)     (o)  |  "  
	@echo " +#+#+#+#+#+    +#+         |   |  '-'     '-'  |  "  
	@echo "      #+#    #+#                |     ◇◇◇     |  "  
	@echo "     ###   ########.fr      |    \\  -'---'-  /   "  
	@echo ""
	@echo " ~ 🤖 Marvin doesn't really care about your compilation... ~ "
	@echo "   ~ But it's done anyway, so congratulations! 🎉🥳 ~ "
	@echo ""
	@echo "============================================================="
	@echo "    👨‍💻 Developed by:    Jack Pepper   🚀"
	@echo "    📧 Contact:         xxx@xxx  ✉️"
	@echo "    💡 Message:         \"Code Smart, Debug Hard!\"  🔥"
	@echo "============================================================="
	@echo "          🚀🔥📜💡🎮🖥️👾🔢💾🛠️🔗🖨️💾📊🔍⚙️🎯"
	@echo "       🎉🚀 LIBFT Compilation Complete! 🚀🎉"	
	@echo "============================================================="
 


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
	cd libsort && make
	ar x libsort/libsort.a
	cd libxkit && make
	ar x libxkit/libxkit.a
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
