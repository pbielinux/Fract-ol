NAME = Fract-ol

CC = gcc
FLAGS = -Wall -Wextra
LIBRARIES = -lmlx -lm -lft\
	-L$(LIBFT_DIR) -L$(MLX_DIR)\
	-framework OpenGL -framework AppKit
INCLUDES = -I$(HEADERS_DIR) -I$(LIBFT_HEADERS) -I$(MLX_HEADERS)

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = ./libft/
LIBFT_HEADERS = $(LIBFT_DIR)include/

MLX = $(MLX_DIR)libmlx.a
MLX_DIR = ./mlx_macos/
MLX_HEADERS = $(MLX_DIR)

HEADERS_LIST = \
	fractol.h \
	macos_keys.h \
	types.h \
	core_utils.h
HEADERS_DIR = ./includes/
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

SOURCES_DIR = ./sources/
SOURCES_LIST = \
	buffer.c \
	color.c \
	context.c \
	core.c \
	exit_error.c \
	fractal.c \
	julia.c \
	keyboard_control.c \
	loop.c \
	main.c \
	mandelbrot.c \
	memory_utils.c \
	palette.c \
	pixel.c \
	render.c \
	utilities.c \
	viewport.c

SOURCES = $(addprefix $(SOURCES_DIR), $(SOURCES_LIST))

OBJECTS_DIR = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIR), $(OBJECTS_LIST))

# COLORS

GREEN = \033[0;32m
GREENGREEN = \033[38;5;46m
RED = \033[0;31m
BLUE = \033[0;34m
GREY = \033[38;5;240m
RESET = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJECTS_DIR) $(OBJECTS)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) -o $(NAME)
	@echo "\n\n[$(GREENGREEN)$(NAME)$(RESET)]: Object files were created\n"
	@echo "[$(GREENGREEN)$(NAME)$(RESET)]: $(NAME) was created\n$(GREENGREEN)"
	@cat $(HEADERS_DIR)logo

$(OBJECTS_DIR):
	@mkdir -p $(OBJECTS_DIR)
	@echo "\n[$(GREENGREEN)$(NAME)$(RESET)]: Objects Directory was created\n"

$(OBJECTS_DIR)%.o : $(SOURCES_DIR)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN)//$(RESET)\c"

$(LIBFT):
	@echo "[$(GREENGREEN)$(NAME)$(RESET)]: Creating $(LIBFT)...$(RESET)"
	@make -C $(LIBFT_DIR)

$(MLX):
	@echo "[$(GREENGREEN)$(NAME)$(RESET)]: Creating $(MLX)...$(GREY)"
	@make -C $(MLX_DIR)
	@echo "[$(GREENGREEN)$(NAME)$(RESET)]: MLX Objects were created"

clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	@rm -rf $(OBJECTS_DIR)
	@echo "[$(GREENGREEN)$(NAME)$(RESET)]: $(RED)Objects Directory was deleted$(RESET)"
	@echo "[$(GREENGREEN)$(NAME)$(RESET)]: $(RED)Object Files were deleted$(RESET)"

fclean: clean
	@rm -f $(MLX)
	@echo "[$(GREENGREEN)$(NAME)$(RESET)]: $(RED)$(MLX) was deleted$(RESET)"
	@rm -f $(LIBFT)
	@echo "[$(GREENGREEN)$(NAME)$(RESET)]: $(RED)$(LIBFT) was deleted$(RESET)"
	@rm -f $(NAME)
	@echo "[$(GREENGREEN)$(NAME)$(RESET)]: $(RED)$(NAME) was deleted$(RESET)\n"

re:
	@make fclean
	@make all
