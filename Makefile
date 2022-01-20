# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/11 12:13:12 by jludt             #+#    #+#              #
#    Updated: 2022/01/20 15:33:24 by tblaase          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the program
NAME = raycast_visualizer

# Color codes
RESET	= \033[0m
GREEN	= \033[32m
YELLOW	= \033[33m
BLUE	= \033[34m
RED		= \033[31m
UP		= \033[A

# Compiling flags
FLAGS = -Wall -Wextra -Werror

# Folders
SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./includes/
LIBFT_DIR = ./libft/
MINLBX_DIR = ./mlx/

# Source files and object files
SRC_FILES = main.c init.c validation.c
OBJ_FILES = $(SRC_FILES:.c=.o)

# Paths
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)
MINLBX	= $(addprefix $(MINLBX_DIR), libmlx.a)

# Libft and Minilibx linkers
LNK  = -L $(LIBFT_DIR) -lft -L $(MINLBX_DIR) \
			-lmlx -framework OpenGL -framework AppKit

# all rule
all: obj $(LIBFT) $(MINLBX) $(NAME)
	@printf "\n\n"
	@echo "$(GREEN)                        _/                        _/"$(X)
	@echo "$(GREEN)                       _/        _/_/_/          _/ "$(X)
	@echo "$(GREEN)    _/_/_/  _/    _/  _/_/_/          _/    _/_/_/  "$(X)
	@echo "$(GREEN) _/        _/    _/  _/    _/    _/_/    _/    _/   "$(X)
	@echo "$(GREEN)_/        _/    _/  _/    _/        _/  _/    _/    "$(X)
	@echo "$(GREEN) _/_/_/    _/_/_/  _/_/_/    _/_/_/      _/_/_/     "$(X)
	@printf "\n\n"

obj:
	@mkdir -p $(OBJ_DIR)
$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@gcc $(FLAGS) -I $(MINLBX_DIR) -I $(LIBFT_DIR) -I $(INC_DIR) -o $@ -c $<
$(LIBFT):
	@echo "$(YELLOW)Compiling $(LIBFT_DIR) library...$(RESET)"
	@make -C $(LIBFT_DIR)
$(MINLBX):
	@echo "$(YELLOW)Compiling $(MINLBX_DIR) library...$(RESET)"
	@make -C $(MINLBX_DIR)

# Compiling
$(NAME): $(OBJ)
#	@printf "$(UP)"
	@echo "$(YELLOW)Compiling $(NAME)...$(RESET)"
	@gcc $(OBJ) $(LNK) -lm -o $(NAME)
	@echo "$(GREEN)Compiled $(NAME) successfully.$(RESET)"

# clean rule
clean:
	@make -C $(MINLBX_DIR) clean
	@make -C $(LIBFT_DIR) clean
	@if [ -d "$(OBJ_DIR)" ]; then \
			rm -rf $(OBJ_DIR); \
			echo "$(BLUE)***   Deleting all objects from cub3d...   ***$(RESET)"; else \
			echo "No objects to remove from cub3d."; \
	fi;

# fclean rule
fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@echo "$(BLUE)***   Deleting $(NAME) from cub3d...   ***$(RESET)"
	@rm -f $(NAME)

# re rule
re: fclean all

# phony
.PHONY: all clean fclean re