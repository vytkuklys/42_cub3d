# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/11 12:13:12 by jludt             #+#    #+#              #
#    Updated: 2022/01/18 21:16:35 by tblaase          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the program
NAME = raycast_visualizer

# Color codes
RESET	= \033[0m
GREEN	= \033[32m
YELLOW	= \033[33m
BLUE	= \033[34m

# Compiling flags
FLAGS = -Wall -Wextra -Werror

# Folders
SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./includes/
LIBFT_DIR = ./libft/
MINLBX_DIR = ./mlx/

# Source files and object files
SRC_FILES = main.c
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

obj:
	@mkdir -p $(OBJ_DIR)
$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@gcc $(FLAGS) -I $(MINLBX_DIR) -I $(LIBFT_DIR) -I $(INC_DIR) -o $@ -c $<
$(LIBFT):
	@make -C $(LIBFT_DIR)
$(MINLBX):
	@make -C $(MINLBX_DIR)

# Compiling
$(NAME): $(OBJ)
	@echo "$(YELLOW)\n      -> Building $(NAME) ...$(RESET)"
	@gcc $(OBJ) $(LNK) -lm -o $(NAME)
	@echo "$(GREEN)***   Project $(NAME) successfully compiled   ***\n$(RESET)"
	@echo "$(GREEN)                        _/                        _/"$(X)
	@echo "$(GREEN)                       _/        _/_/_/          _/ "$(X)
	@echo "$(GREEN)    _/_/_/  _/    _/  _/_/_/          _/    _/_/_/  "$(X)
	@echo "$(GREEN) _/        _/    _/  _/    _/    _/_/    _/    _/   "$(X)
	@echo "$(GREEN)_/        _/    _/  _/    _/        _/  _/    _/    "$(X)
	@echo "$(GREEN) _/_/_/    _/_/_/  _/_/_/    _/_/_/      _/_/_/     "$(X)
	@printf "\n\n"



# clean rule
clean:
	@echo "$(BLUE)***   Deleting all objects from $(NAME)   ...   ***$(RESET)"
	@rm -Rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MINLBX_DIR) clean

# fclean rule
fclean: clean
	@echo "$(BLUE)***   Deleting executable file from $(NAME)   ...   ***$(RESET)"
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

# re rule
re: fclean all

# phony
.PHONY: all clean fclean re