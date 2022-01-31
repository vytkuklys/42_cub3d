# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/31 15:54:32 by tblaase           #+#    #+#              #
#    Updated: 2022/01/31 15:57:38 by tblaase          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror

# directories
SRC_DIR		=	src/
OBJ_DIR		=	obj/
INC_DIR		=	include/
LIBFT_DIR	=	libft/
LIBMLX_DIR	=	mlx/

# controll codes
RESET		=	\033[0m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
RED			=	\033[31m
UP			=	\033[A
CUT			=	\033[K

# source files
SRC_FILES	=	main.c \
				init.c validation.c checkers.c minimap.c textures.c walls.c events.c \
				draw.c utils.c rays.c validation2.c setters.c doors.c

# object files
OBJ_FILES	=	$(SRC_FILES:.c=.o)

# paths
SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))
LIBFT		=	$(addprefix $(LIBFT_DIR), libft.a)
LIBMLX		=	$(addprefix $(LIBMLX_DIR), libmlx.a)

# libft and mlx linkers
LNK			=	-L $(LIBFT_DIR) -lft -L $(LIBMLX_DIR) -lmlx -framework OpenGL -framework AppKit

# all rule
all: $(LIBFT) $(LIBMLX) $(NAME)
	@printf "\n"
	@echo "$(GREEN)                     $(RESET)"
	@echo "$(GREEN)         _   ___ ___ $(RESET)"
	@echo "$(GREEN) ___ _ _| |_|_  |   |$(RESET)"
	@echo "$(GREEN)|  _| | | . |_  | | |$(RESET)"
	@echo "$(GREEN)|___|___|___|___|___|$(RESET)"
	@echo "$(GREEN)                     $(RESET)"
	@printf "\n"

# compile cub3D
$(NAME): $(OBJ)
	@echo "$(YELLOW)Compiling $(NAME)...$(RESET)"
	@$(CC) $(OBJ) $(LNK) -lm -o $(NAME)
	@echo "$(GREEN)Compiled $(NAME) successfully.$(RESET)"

# compile objects
$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling [$@]...$(RESET)"
	@$(CC) $(FLAGS) -I $(LIBMLX_DIR) -I $(LIBFT_DIR) -I $(INC_DIR) -o $@ -c $<
	@printf "$(UP)$(CUT)"
	@echo "$(GREEN)Finished [$@]$(RESET)"
	@printf "$(UP)$(CUT)"

# compile libft
$(LIBFT):
	@echo "$(YELLOW)Compiling $(LIBFT_DIR) library...$(RESET)"
	@make -C $(LIBFT_DIR)

# compile mlx
$(LIBMLX):
	@echo "$(YELLOW)Compiling $(LIBMLX_DIR) library...$(RESET)"
	@make -C $(LIBMLX_DIR)

# clean rule
clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(LIBMLX_DIR) clean
	@if [ -d "$(OBJ_DIR)" ]; then \
			rm -rf $(OBJ_DIR); \
			echo "$(BLUE)Deleting all objects from /cub3d...$(RESET)"; else \
			echo "No objects to remove from /cub3D."; \
	fi;

# fclean rule
fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@make -C $(LIBMLX_DIR) fclean
	@if [ -f "$(NAME)" ]; then \
		rm -f $(NAME); \
		echo "$(BLUE)Deleting $(NAME) from /cub3d...$(RESET)"; else \
		echo "No Executable to remove from /cub3D."; \
	fi;

# re rule
re: fclean all

# phony
.PHONY: all clean fclean re