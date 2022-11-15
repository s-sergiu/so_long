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
	 obj/backtracking.o

LIBFT= obj/libft/libft.o
GNL= obj/gnl/gnl.o
LIBFT_DIR= src/libft
GNL_DIR= src/gnl

$(NAME): $(GNL) $(LIBFT) $(OBJ) 
	$(CC) $(OBJ) $(GNL) $(LIBFT) -o $(NAME)

obj/%.o: src/%.c
	$(CC) -g -Wall -Wextra -Werror -c $< -o $@

$(GNL): $(GNL_DIR)/*.c
	@if  [ ! -d obj/gnl ]; then \
		mkdir -p obj/gnl; \
	fi
	@make -C $(GNL_DIR)
	@cp $(GNL_DIR)/gnl.a $(GNL)
	@make fclean -C $(GNL_DIR)

$(LIBFT): $(LIBFT_DIR)/*.c
	@if  [ ! -d obj/libft ]; then \
		mkdir -p obj/libft; \
	fi
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/libft.a $(LIBFT)
	@make fclean -C $(LIBFT_DIR)

clean:
	@echo "$(MAGENTA)Cleaning object files.. $(ENDCOLOR)"
	@$(RM) $(OBJ) $(BONUS_OBJ) $(LIBFT) $(GNL)

fclean: clean
	@echo "$(MAGENTA)Cleaning all.. $(ENDCOLOR)"
	@$(RM) $(NAME) $(BONUS_FILE)

re: clean all

.PHONY: bonus all clean fclean re


