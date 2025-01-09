CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes -I./MLX42/include -I./ft_printf/includes
MLX_DIR = MLX
MLX_LIB = $(MLX_DIR)/build/libmlx42.a
PRINTF_DIR = ft_printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a
LIBS = -ldl -lglfw -pthread -lm

NAME = so_long
SRCS = src/so_long.c \
	src/ft_error.c \
	src/checks.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(MLX_LIB) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) $(PRINTF_LIB) $(LIBS) -o $(NAME)

$(MLX_LIB):
	cmake -S $(MLX_DIR) -B $(MLX_DIR)/build
	$(MAKE) -C $(MLX_DIR)/build

$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

clean:
	rm -f $(OBJS)
	@if [ -d $(MLX_DIR)/build ]; then \
		$(MAKE) -C $(MLX_DIR)/build clean; \
	fi
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	@if [ -d $(MLX_DIR)/build ]; then \
		rm -rf $(MLX_DIR)/build; \
	fi
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
