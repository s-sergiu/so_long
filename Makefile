NAME=so_long
BONUS=bonus
UNAME_S := $(shell uname -s)

CYAN=\033[0;36m
GREEN=\033[0;32m
MAGENTA=\033[0;35m
ENDCOLOR=\033[0m

CC= cc
FLAGS= -g -Wall -Werror -Wextra

OBJ= obj/main.o \
	 obj/wall_check.o \
	 obj/component_check.o \
	 obj/filename_check.o \
	 obj/read_map.o \
	 obj/path_check.o \
	 obj/errors.o \
	 obj/loop.o \
	 obj/draw_map.o \
	 obj/coord_tools.o \
	 obj/struct_utils.o \
	 obj/map_check.o \
	 obj/tiles.o \
	 obj/tiles_utils.o \
	 obj/player.o \
	 obj/collectable.o \
	 obj/put_tiles.o \

BONUS_OBJ=   obj/bonus/enemy.o \
		     obj/bonus/loop_bonus.o \
		     obj/bonus/draw_map.o \
			 obj/main.o \
			 obj/wall_check.o \
			 obj/component_check.o \
			 obj/filename_check.o \
			 obj/read_map.o \
			 obj/path_check.o \
			 obj/errors.o \
			 obj/coord_tools.o \
			 obj/struct_utils.o \
			 obj/map_check.o \
			 obj/tiles.o \
			 obj/tiles_utils.o \
			 obj/player.o \
			 obj/collectable.o \
			 obj/put_tiles.o \

MLX= lib/MLX42/libmlx42.a
MLX_DIR= lib/MLX42/
LIBFT= obj/libft/libft.o
LIBFT_DIR= src/libft
NAME_H= include/so_long.h

ifeq ($(UNAME_S),Linux)
MLX_FLAGS= -ldl -lglfw -pthread -lm
endif
ifeq ($(UNAME_S),Darwin)
MLX_FLAGS= -lglfw -L ~/.brew/Cellar/glfw/3.3.8/lib
endif

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) $(NAME_H) $(MLX)
	$(CC) $(OBJ) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)

$(BONUS): $(LIBFT) $(BONUS_OBJ) $(NAME_H) $(MLX)
	$(CC) $(BONUS_OBJ) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(BONUS)

obj/%.o: src/%.c
	$(CC) -g -Wall -Wextra -Werror -c $< -o $@

obj/bonus/%.o: src/bonus/%.c
	@if  [ ! -d obj/bonus ]; then \
		mkdir -p obj/bonus; \
	fi
	$(CC) -g -Wall -Wextra -Werror -c $< -o $@

$(LIBFT): $(LIBFT_DIR)/*.c
	@if  [ ! -d obj/libft ]; then \
		mkdir -p obj/libft; \
	fi
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/libft.a $(LIBFT)
	@make fclean -C $(LIBFT_DIR)

$(MLX): $(MLX_DIR)
	@if  [ ! -d obj/mlx ]; then \
		mkdir -p obj/mlx; \
	fi
	@make -C $(MLX_DIR)

clean:
	@echo "$(MAGENTA)Cleaning object files.. $(ENDCOLOR)"
	@$(RM) $(OBJ) $(BONUS_OBJ) $(LIBFT) $(MLX) 

fclean: clean
	@echo "$(MAGENTA)Cleaning all.. $(ENDCOLOR)"
	@$(RM) $(NAME) $(BONUS)

re: clean all

.PHONY: all clean fclean re 
