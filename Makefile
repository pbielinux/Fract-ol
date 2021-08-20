# COLORS
GREEN = \033[0;32m
GREENGREEN = \033[38;5;46m
RED = \033[0;31m
BLUE = \033[0;34m
GREY = \033[38;5;240m
RESET = \033[0m

NAME	=	fractol

LIBFT	=	includes/libft

HEADERS	=	headers

DIR_S	=	srcs

DIR_O	=	obj

O_SRCS	:=	srcs/main.c \
			srcs/fractals/mandelbrot.c \
			srcs/fractals/burning_ship.c \
			srcs/fractals/julia.c \
			srcs/fractals/fractal.c \
			srcs/core/core.c \
			srcs/core/loop.c \
			srcs/core/buffer.c \
			srcs/core/render.c \
			srcs/core/utils.c \
			srcs/core/memory_utils.c \
			srcs/core/exit_error.c \
			srcs/context/context.c \
			srcs/context/viewport.c \
			srcs/context/pixel.c \
			srcs/context/palette.c \
			srcs/context/color.c \
			srcs/context/gui.c \
			srcs/control/mouse_control.c \
			srcs/control/keyboard_control.c


SRCS	:=	$(O_SRCS)

B_SRCS	:=	$(O_SRCS)

OBJS	:= $(SRCS:%.c=$(DIR_O)/%.o)

BOBJS	:= $(B_SRCS:%.c=$(DIR_O)/%.o)

SUB_DIR_O := $(shell find $(DIR_S) -type d)
SUB_DIR_O := $(SUB_DIR_O:%=$(DIR_O)/%)

DEPS	=	$(HEADERS)/core_utils.h \
			$(HEADERS)/fractol.h \
			$(HEADERS)/types.h \
			$(HEADERS)/macos_keys.h \
			$(HEADERS)/terminal_colors.h

CC		=	gcc

# Change optimization flag to -O3 for faster execution
CFLAGS	=	-O3 -Wall -Wextra -Werror

# Linux Libs
# LIBS	=	-lm -L./libft -lft -lmlx -lX11 -lbsd -lXext
# MLX		=	includes/mlx_linux

# Mac Libs
LIBS	=	-lm -L./$(LIBFT) -lft -lmlx -framework OpenGL -framework AppKit
MLX		=	includes/mlx_macos

RM		=	rm -f

INCLUDES	= -I/$(LIBFT)/ -I/headers/

$(DIR_O)/%.o: %.c
	@mkdir -p $(DIR_O)
	@mkdir -p $(SUB_DIR_O)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<
	@echo "$(GREEN)//$(RESET)\c"

$(NAME):	libft mlx $(DEPS) $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)
	@echo "\n\n[$(GREENGREEN)$(NAME)$(RESET)]: $(NAME) was created\n$(GREENGREEN)"
	@cat includes/graphic_assets/logo

all:		$(NAME)

libft:
	@echo "[$(GREENGREEN)Fract-ol$(RESET)]: Creating $(LIBFT)...$(RESET)"
	@make -C $(LIBFT)

mlx:
	@echo "$(RESET)[$(GREENGREEN)Fract-ol$(RESET)]: Creating MLX...$(GREY)"
	@make -C $(MLX)
	@echo "$(RESET)[$(GREENGREEN)Fract-ol$(RESET)]: MLX Objects were created\n"

clean:
	@make -C $(LIBFT) clean
	@make -C $(MLX) clean
	@rm -rf $(DIR_O)
	@echo "[$(GREENGREEN)Fract-ol$(RESET)]: $(RED)Objects Directory was deleted$(RESET)"
	@echo "[$(GREENGREEN)Fract-ol$(RESET)]: $(RED)Object Files were deleted$(RESET)"

fclean:	clean
	@rm -f $(MLX)/mlx.a
	@echo "[$(GREENGREEN)Fract-ol$(RESET)]: $(RED)$(MLX) was deleted$(RESET)"
	@rm -f $(LIBFT)/libft.a
	@echo "[$(GREENGREEN)Fract-ol$(RESET)]: $(RED)$(LIBFT) was deleted$(RESET)"
	@rm -f $(NAME)
	@echo "[$(GREENGREEN)Fract-ol$(RESET)]: $(RED)$(NAME) was deleted$(RESET)\n"

re:			fclean all


.PHONY:		all clean fclean cubclean re bonus
