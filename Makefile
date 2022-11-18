NAME= so_long

CYAN=\033[0;36m
GREEN=\033[0;32m
MAGENTA=\033[0;35m
ENDCOLOR=\033[0m

CC= cc
FLAGS= -g -Wall -Werror -Wextra

OBJ= obj/main.o \
	 obj/map_wall_checks.o \
	 obj/map_components_check.o \
	 obj/test.o \
	 obj/read_map.o \
	 obj/backtracking.o \
	 obj/errors.o \
	 obj/other.o \
	 obj/struct_utils.o \
	 obj/map_check.o \

LIBFT= obj/libft/libft.o
LIBFT_DIR= src/libft
NAME_H= include/so_long.h

$(NAME): $(LIBFT) $(OBJ) $(NAME_H)
	$(CC) $(OBJ) $(GNL) $(LIBFT) lib/MLX42/libmlx42.a \
	-lglfw -L ~/.brew/Cellar/glfw/3.3.8/lib -o $(NAME)

obj/%.o: src/%.c
	$(CC) -g -Wall -Wextra -Werror -c $< -o $@

$(LIBFT): $(LIBFT_DIR)/*.c
	@if  [ ! -d obj/libft ]; then \
		mkdir -p obj/libft; \
	fi
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/libft.a $(LIBFT)
	@make fclean -C $(LIBFT_DIR)

clean:
	@echo "$(MAGENTA)Cleaning object files.. $(ENDCOLOR)"
	@$(RM) $(OBJ) $(BONUS_OBJ) $(LIBFT)

fclean: clean
	@echo "$(MAGENTA)Cleaning all.. $(ENDCOLOR)"
	@$(RM) $(NAME) $(BONUS_FILE)

re: clean all

.PHONY: bonus all clean fclean re


