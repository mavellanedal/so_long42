NAME = libftprintf.a

SRC = ft_printf.c \
      ft_print_string.c \
	  ft_print_char.c \
	  ft_print_int.c \
	  ft_print_unsigned.c \
	  ft_putunsigned.c \
	  ft_print_hex.c \
	  ft_print_pointer.c

OBJ = $(SRC:.c=.o)

LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

MAKEFILE = Makefile
PRINTF = printf.h

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_DIR)
	cp $(LIBFT) ./
	$(AR) $(NAME) $(OBJ) libft.a
	echo "libftprintf.a creado exitosamente."

%.o: %.c $(MAKEFILE) $(PRINTF)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean  # Limpia libft
	rm -f $(OBJ)

fclean: clean
	make -C $(LIBFT_DIR) fclean  # Limpia completamente libft
	rm -f $(NAME) libft.a

re: fclean all

.PHONY: all clean fclean re
