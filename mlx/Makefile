# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/31 14:08:52 by tblaase           #+#    #+#              #
#    Updated: 2022/01/31 15:56:51 by tblaase          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libmlx.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

# sources
SRC		= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC		+= mlx_png.c mlx_mouse.m

# objects
OBJ1		= $(SRC:.c=.o)
OBJ			= $(OBJ1:.m=.o)

# addition to CFLAGS
CFLAGS	+= -O2

# controll codes
RESET	= \033[0m
GREEN	= \033[32m
YELLOW	= \033[33m
BLUE	= \033[34m
RED		= \033[31m
UP		= \033[A
CUT		= \033[K

# compiling objects
%.o: %.c
	@echo "$(YELLOW)Compiling [$@]...$(RESET)"
	@cc -O2 -w -DSTRINGPUTX11   -c -o $@ $<
	@printf "$(UP)$(CUT)"
	@echo "$(GREEN)Finished [$@]$(RESET)"
	@printf "$(UP)$(CUT)"
%.o: %.m
	@echo "$(YELLOW)Compiling [$@]...$(RESET)"
	@cc -O2 -w -DSTRINGPUTX11   -c -o $@ $<
	@printf "$(UP)$(CUT)"
	@echo "$(GREEN)Finished [$@]$(RESET)"
	@printf "$(UP)$(CUT)"

# add to match string put with X11 in size and position
CFLAGS	+= -DSTRINGPUTX11

# all rule
all: $(NAME)
	@printf "\n"
	@echo "$(GREEN)             $(RESET)"
	@echo "$(GREEN)       _     $(RESET)"
	@echo "$(GREEN) _____| |_ _ $(RESET)"
	@echo "$(GREEN)|     | |_'_|$(RESET)"
	@echo "$(GREEN)|_|_|_|_|_._|$(RESET)"
	@echo "$(GREEN)             $(RESET)"
	@printf "\n"

# $(NAME) rule
$(NAME): $(OBJ)
	@ar -rcs $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(GREEN)Finished [$(NAME)]...$(RESET)"

# clean rule
clean:
	@if [ -f "mlx_init_loop.o" ]; then \
		echo "$(BLUE)Deleting all objects from mlx\...$(RESET)"; \
		rm -f $(OBJ); \
	fi;

# fclean rule
fclean: clean
	@if [ -f "$(NAME)" ]; then \
		rm -f $(NAME); \
		echo "$(BLUE)Deleting $(NAME) from /mlx...$(RESET)"; else\
		echo "No $(NAME) to remove from /mlx."; \
	fi;

# re rule
re: clean all
