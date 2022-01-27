# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/26 13:57:50 by tblaase           #+#    #+#              #
#    Updated: 2022/01/27 20:06:18 by tblaase          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC_DIR = ./src/

OBJ_DIR = ./obj/

#controll codes
RESET	= \033[0m
GREEN	= \033[32m
YELLOW	= \033[33m
BLUE	= \033[34m
RED		= \033[31m
UP		= \033[A
CUT		= \033[K

#sources
SRC =		$(SRC_DIR)ft_add_single_str.c\
			$(SRC_DIR)ft_atoi.c\
			$(SRC_DIR)ft_atol.c\
			$(SRC_DIR)ft_bzero.c\
			$(SRC_DIR)ft_calloc.c\
			$(SRC_DIR)ft_count_c.c\
			$(SRC_DIR)ft_count_lines.c\
			$(SRC_DIR)ft_free_str_array.c\
			$(SRC_DIR)ft_free_str.c\
			$(SRC_DIR)ft_intlen.c\
			$(SRC_DIR)ft_isalnum.c\
			$(SRC_DIR)ft_isalpha.c\
			$(SRC_DIR)ft_isascii.c\
			$(SRC_DIR)ft_isdigit.c\
			$(SRC_DIR)ft_isprint.c\
			$(SRC_DIR)ft_itoa.c\
			$(SRC_DIR)ft_line_length.c\
			$(SRC_DIR)ft_lstadd_back.c\
			$(SRC_DIR)ft_lstadd_front.c\
			$(SRC_DIR)ft_lstclear.c\
			$(SRC_DIR)ft_lstdelone.c\
			$(SRC_DIR)ft_lstiter.c\
			$(SRC_DIR)ft_lstlast.c\
			$(SRC_DIR)ft_lstmap.c\
			$(SRC_DIR)ft_lstnew.c\
			$(SRC_DIR)ft_lstsize.c\
			$(SRC_DIR)ft_memccpy.c\
			$(SRC_DIR)ft_memchr.c\
			$(SRC_DIR)ft_memcmp.c\
			$(SRC_DIR)ft_memcpy.c\
			$(SRC_DIR)ft_memmove.c\
			$(SRC_DIR)ft_memset.c\
			$(SRC_DIR)ft_put_unsigned_nbr.c\
			$(SRC_DIR)ft_putchar_fd.c\
			$(SRC_DIR)ft_putendl_fd.c\
			$(SRC_DIR)ft_putnbr_fd.c\
			$(SRC_DIR)ft_putstr_fd.c\
			$(SRC_DIR)ft_realloc_str_arr.c\
			$(SRC_DIR)ft_realloc_str.c\
			$(SRC_DIR)ft_split.c\
			$(SRC_DIR)ft_str_arr_dup.c\
			$(SRC_DIR)ft_str_arr_len.c\
			$(SRC_DIR)ft_strchr.c\
			$(SRC_DIR)ft_strcjoin.c\
			$(SRC_DIR)ft_strdup.c\
			$(SRC_DIR)ft_strjoin.c\
			$(SRC_DIR)ft_strlcat.c\
			$(SRC_DIR)ft_strlcpy.c\
			$(SRC_DIR)ft_strlen.c\
			$(SRC_DIR)ft_strmapi.c\
			$(SRC_DIR)ft_strncmp.c\
			$(SRC_DIR)ft_strndup.c\
			$(SRC_DIR)ft_strnjoin.c\
			$(SRC_DIR)ft_strnstr.c\
			$(SRC_DIR)ft_strrchr.c\
			$(SRC_DIR)ft_strstrjoin.c\
			$(SRC_DIR)ft_strtrim.c\
			$(SRC_DIR)ft_substr.c\
			$(SRC_DIR)ft_tolower.c\
			$(SRC_DIR)ft_toupper.c\
			$(SRC_DIR)get_next_line_utils.c\
			$(SRC_DIR)get_next_line.c

#objects
OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))

#all rule
all: $(NAME)
	@printf "\n"
	@echo "$(GREEN) __    _ _   ___ _   $(RESET)"
	@echo "$(GREEN)|  |  |_| |_|  _| |_ $(RESET)"
	@echo "$(GREEN)|  |__| | . |  _|  _|$(RESET)"
	@echo "$(GREEN)|_____|_|___|_| |_|  $(RESET)"
	@printf "\n\n"

#compiling it to .a file
$(NAME): $(OBJ)
	@ar -crs $(NAME) $(OBJ)
	@echo "$(GREEN)Finished [$(NAME)]...$(RESET)"

#compiling objects
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo "$(YELLOW)Compiling [$@]...$(RESET)"
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I ./include -c $< -o $@
#	@printf "$(UP)$(CUT)"
	@echo "$(GREEN)Finished [$@]$(RESET)"
	@printf "$(UP)$(CUT)"

#clean rule
clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
			rm -rf $(OBJ_DIR); \
			echo "$(BLUE)Deleting all objects from libft...$(RESET)"; \
	fi;

#fclean rule
fclean: clean
	@echo "$(BLUE)Deleting $(NAME) from libft...$(RESET)"
	@rm -f $(NAME)

#re rule
re : fclean all

# phony
.PHONY: all clean fclean re