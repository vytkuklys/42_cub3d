# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/26 13:57:50 by tblaase           #+#    #+#              #
#    Updated: 2022/01/31 15:56:54 by tblaase          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

# directories
SRC_DIR		=	src/
OBJ_DIR		=	obj/
INC_DIR		=	include/

# controll codes
RESET		=	\033[0m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
RED			=	\033[31m
UP			=	\033[A
CUT			=	\033[K

# source files
SRC_FILES	=	ft_add_single_str.c\
				ft_atoi.c\
				ft_atol.c\
				ft_bzero.c\
				ft_calloc.c\
				ft_count_c.c\
				ft_count_lines.c\
				ft_free_str_array.c\
				ft_free_str.c\
				ft_intlen.c\
				ft_isalnum.c\
				ft_isalpha.c\
				ft_isascii.c\
				ft_isdigit.c\
				ft_isprint.c\
				ft_itoa.c\
				ft_line_length.c\
				ft_lstadd_back.c\
				ft_lstadd_front.c\
				ft_lstclear.c\
				ft_lstdelone.c\
				ft_lstiter.c\
				ft_lstlast.c\
				ft_lstmap.c\
				ft_lstnew.c\
				ft_lstsize.c\
				ft_memccpy.c\
				ft_memchr.c\
				ft_memcmp.c\
				ft_memcpy.c\
				ft_memmove.c\
				ft_memset.c\
				ft_put_unsigned_nbr.c\
				ft_putchar_fd.c\
				ft_putendl_fd.c\
				ft_putnbr_fd.c\
				ft_putstr_fd.c\
				ft_realloc_str_arr.c\
				ft_realloc_str.c\
				ft_split.c\
				ft_str_arr_dup.c\
				ft_str_arr_len.c\
				ft_strchr.c\
				ft_strcjoin.c\
				ft_strdup.c\
				ft_strjoin.c\
				ft_strlcat.c\
				ft_strlcpy.c\
				ft_strlen.c\
				ft_strmapi.c\
				ft_strncmp.c\
				ft_strndup.c\
				ft_strnjoin.c\
				ft_strnstr.c\
				ft_strrchr.c\
				ft_strstrjoin.c\
				ft_strtrim.c\
				ft_substr.c\
				ft_tolower.c\
				ft_toupper.c\
				get_next_line_utils.c\
				get_next_line.c

# object files
OBJ_FILES	=	$(SRC_FILES:.c=.o)

# paths
SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

# all rule
all: $(NAME)
	@printf "\n"
	@echo "$(GREEN)                 $(RESET)"
	@echo "$(GREEN) _ _ _   ___ _   $(RESET)"
	@echo "$(GREEN)| |_| |_|  _| |_ $(RESET)"
	@echo "$(GREEN)| | | . |  _|  _|$(RESET)"
	@echo "$(GREEN)|_|_|___|_| |_|  $(RESET)"
	@echo "$(GREEN)                 $(RESET)"
	@printf "\n"

# compiling it to .a file
$(NAME): $(OBJ)
	@ar -crs $(NAME) $(OBJ)
	@echo "$(GREEN)Finished [$(NAME)]...$(RESET)"

# compiling objects
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo "$(YELLOW)Compiling [$@]...$(RESET)"
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@
	@printf "$(UP)$(CUT)"
	@echo "$(GREEN)Finished [$@]$(RESET)"
	@printf "$(UP)$(CUT)"

# clean rule
clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
			rm -rf $(OBJ_DIR); \
			echo "$(BLUE)Deleting all objects from /libft...$(RESET)"; \
	fi;

# fclean rule
fclean: clean
	@if [ -f "$(NAME)" ]; then \
		rm -f $(NAME); \
		echo "$(BLUE)Deleting $(NAME) from /libft...$(RESET)"; else\
		echo "No $(NAME) to remove from /libft."; \
	fi;

# re rule
re : fclean all

# phony
.PHONY: all clean fclean re