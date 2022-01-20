
# Color codes
RESET	= \033[0m
GREEN	= \033[32m
YELLOW	= \033[33m
BLUE	= \033[34m
RED		= \033[31m
UP		= \033[A
# CUT		= \033[K

NAME=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2
# added the following 4 lines to silence all the warnings created
%.o : %.c
	@cc -O2 -w -DSTRINGPUTX11   -c -o $@ $<
%.o : %.m
	@cc -O2 -w -DSTRINGPUTX11   -c -o $@ $<

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11

all: $(NAME)

$(NAME):	$(OBJ)
	@ar cr $(NAME) $(OBJ)
#	@printf "$(UP)"
	@ranlib $(NAME)
	@echo "$(GREEN)Compiled mlx library successfully.$(RESET)"

clean:
	@echo "$(BLUE)***   Deleting all objects from mlx   ...   ***$(RESET)"
	@rm -f $(NAME) $(OBJ) *~
	@echo "$(BLUE)***   Deleting $(NAME) from mlx...   ***$(RESET)"
#	@rm -f mlx_app
	@rm -f $(NAME)

re: clean all
