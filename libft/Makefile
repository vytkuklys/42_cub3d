# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/22 09:51:20 by jludt             #+#    #+#              #
#    Updated: 2022/01/20 15:26:51 by tblaase          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC_DIR = ./src/

OBJ_DIR = ./obj/

# Color codes
RESET	= \033[0m
GREEN	= \033[32m
YELLOW	= \033[33m
BLUE	= \033[34m
RED		= \033[31m
UP		= \033[A

SRC = $(SRC_DIR)ft_atoi.c $(SRC_DIR)ft_bzero.c $(SRC_DIR)ft_calloc.c $(SRC_DIR)ft_isalnum.c $(SRC_DIR)ft_isalpha.c \
			$(SRC_DIR)ft_isascii.c $(SRC_DIR)ft_isdigit.c $(SRC_DIR)ft_isprint.c $(SRC_DIR)ft_itoa.c \
			$(SRC_DIR)ft_memccpy.c $(SRC_DIR)ft_memchr.c $(SRC_DIR)ft_memcmp.c $(SRC_DIR)ft_memcpy.c \
			$(SRC_DIR)ft_memmove.c $(SRC_DIR)ft_memset.c $(SRC_DIR)ft_putchar_fd.c \
			$(SRC_DIR)ft_putendl_fd.c $(SRC_DIR)ft_putnbr_fd.c $(SRC_DIR)ft_putstr_fd.c \
			$(SRC_DIR)ft_split.c $(SRC_DIR)ft_strchr.c $(SRC_DIR)ft_strdup.c $(SRC_DIR)ft_strjoin.c \
			$(SRC_DIR)ft_strlcat.c $(SRC_DIR)ft_strlcpy.c $(SRC_DIR)ft_strlen.c $(SRC_DIR)ft_strmapi.c \
			$(SRC_DIR)ft_strncmp.c $(SRC_DIR)ft_strnstr.c $(SRC_DIR)ft_strrchr.c $(SRC_DIR)ft_strtrim.c \
			$(SRC_DIR)ft_substr.c $(SRC_DIR)ft_tolower.c $(SRC_DIR)ft_toupper.c $(SRC_DIR)get_next_line.c \
			$(SRC_DIR)ft_lstadd_back.c $(SRC_DIR)ft_lstadd_front.c $(SRC_DIR)ft_lstclear.c \
			$(SRC_DIR)ft_lstdelone.c $(SRC_DIR)ft_lstiter.c $(SRC_DIR)ft_lstlast.c $(SRC_DIR)ft_lstmap.c \
			$(SRC_DIR)ft_lstnew.c $(SRC_DIR)ft_lstsize.c

OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))

all: $(NAME)
	@echo "$(GREEN)Compiled libft library successfully.$(RESET)"

$(OBJ_DIR)%.o :$(SRC_DIR)%.c
#	@echo "$(YELLOW)Compiling [$@]...$(RESET)"
#	@printf "$(UP)"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c -o $@ $<
#	@echo "$(GREEN)Finished [$@]$(RESET)"
#	@printf "$(UP)"

$(NAME): $(OBJ)
	@ar cr $(NAME) $(OBJ)
#	@echo "$(GREEN)Finished [$(NAME)]$(RESET)"

.PHONY: clean fclean re

clean:
#	@rm -f *.o
	@if [ -d "$(OBJ_DIR)" ]; then \
			rm -rf $(OBJ_DIR); \
			echo "$(BLUE)***   Deleting all objects from libft...   ***$(RESET)"; \
	fi;

fclean: clean
	@echo "$(BLUE)***   Deleting $(NAME) from libft...   ***$(RESET)"
	@rm -f $(NAME)

re : fclean all
