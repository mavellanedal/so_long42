# Source files
SRCS =  src/so_long.c \
	src/map_checks.c \
	src/map_checks2.c \
	src/map_checks3.c \
	src/utils.c \
	src/ft_error.c \
	src/renders.c \
	src/make_images.c \
	src/player_movments.c \

OBJS = ${SRCS:.c=.o}

# Target binary name
NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra #-g -fsanitize=address
RM = rm -f

# Configuracion de libft y printf
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/ft_printf.a

# Configuración de MLX42
MLX_DIR = MLX
MLX_LIB = $(MLX_DIR)/build/libmlx42.a
MLX_INCLUDE = -I$(MLX_DIR)/include
MLX_FLAGS = -ldl -lglfw -pthread -lm
HEADER = includes/so_long.h

# Build everything
all: make_mlx make_libft make_printf $(NAME)

# Compile .c to .o
.c.o:
	${CC} ${CFLAGS} $(MLX_INCLUDE) -c $< -o $@

# Build the program
$(NAME): $(OBJS) Makefile $(HEADER)
	${CC} ${CFLAGS} $(OBJS) $(MLX_LIB) $(MLX_FLAGS) $(FT_PRINTF) $(LIBFT) -o ${NAME}

make_libft:
	$(MAKE) -C $(LIBFT_DIR)

make_printf:
	$(MAKE) -C $(FT_PRINTF_DIR)

# Build MLX42
make_mlx:
	cmake -S $(MLX_DIR) -B $(MLX_DIR)/build
	cmake --build $(MLX_DIR)/build

# Clean objects
clean:
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean
	${RM} ${OBJS}
	${RM} -r $(MLX_DIR)/build

# Clean all files
fclean: clean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	$(MAKE) -C $(LIBFT_DIR) fclean
	${RM} ${NAME}

# Rebuild project
re: fclean all
.PHONY: all clean fclean re
