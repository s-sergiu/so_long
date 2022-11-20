NAME= so_long

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
	 obj/coord_tools.o \
	 obj/struct_utils.o \
	 obj/map_check.o \
	 obj/draw_map.o \
	 obj/tiles.o \
	 obj/old.o \

LIBFT= obj/libft/libft.o
LIBFT_DIR= src/libft
NAME_H= include/so_long.h


$(NAME): $(LIBFT) $(OBJ) $(NAME_H)
	$(CC) $(OBJ) $(GNL) $(LIBFT) lib/MLX42/libmlx42.a \
	-lglfw -L ~/.brew/Cellar/glfw/3.3.8/lib -o $(NAME)

#$(NAME): $(LIBFT) $(OBJ) $(NAME_H)
#	$(CC) $(OBJ) $(GNL) $(LIBFT) -o $(NAME)

obj/%.o: src/%.c
	$(CC) -g -Wall -Wextra -Werror -c $< -o $@

$(LIBFT): $(LIBFT_DIR)/*.c
	@if  [ ! -d obj/libft ]; then \
		mkdir -p obj/libft; \
	fi
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/libft.a $(LIBFT)
	@make fclean -C $(LIBFT_DIR)

all: $(NAME)

clean:
	@echo "$(MAGENTA)Cleaning object files.. $(ENDCOLOR)"
	@$(RM) $(OBJ) $(BONUS_OBJ) $(LIBFT)

fclean: clean
	@echo "$(MAGENTA)Cleaning all.. $(ENDCOLOR)"
	@$(RM) $(NAME) $(BONUS_FILE)

re: clean all

.PHONY: bonus all clean fclean re
