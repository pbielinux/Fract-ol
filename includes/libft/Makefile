NAME = libft.a

CC = gcc
FLAGS = -O3 -Wall -Wextra -Werror
AR = ar rcs

HEADER 	= include

SRC_DIR = src
SOURCES =	ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memset.c \
			ft_memmove.c \
			ft_atoi.c \
			ft_itoa.c \
			ft_putnbr.c \
			ft_putchar.c \
			ft_putendl.c \
			ft_putstr.c \
			ft_split.c \
			ft_strchr.c \
			ft_strcpy.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strcat.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strndup.c \
			ft_strnlen.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strstr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_isspace.c \
			ft_isupper.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_wrdcnt.c \
			ft_counter.c \
			ft_putnbr_base.c \
			ft_numLength.c \
			ft_numLengthBase.c \
			ft_uitoa.c \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_map.c \
			ft_lerpi.c


OBJS_DIR = objects/
OBJS = $(addprefix $(OBJS_DIR)/,$(SOURCES:.c=.o))


DONE = @cat ./graphic_assets/done
GREEN = \033[0;32m
GREENGREEN = \033[38;5;46m
RED = \033[0;31m
BLUE = \033[0;34m
RESET = \033[0m

all: logo $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(GREENGREEN)"
	$(DONE)
	@echo "\n"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@echo "\n[$(GREENGREEN) LIB_FT $(RESET)]: Objects Directory was created \n$(RESET)"

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(FLAGS) -I $(HEADER) -c $< -o $@
	@echo "$(GREEN)/$(RESET)\c"

clean:
	@rm -rf $(OBJS_DIR)
	@echo "\n[$(GREENGREEN) LIB_FT $(RESET)]: $(RED)Object files were removed! $(RESET)"

fclean: clean
	@rm -rf $(NAME)
	@echo "\n[$(GREENGREEN) LIB_FT $(RESET)]: $(RED)Executable was removed!$(RESET)"

re: fclean all

logo:
	@echo "$(GREENGREEN)"
	@cat ./graphic_assets/logo
	@echo "$(RESET)"



