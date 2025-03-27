NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -I/usr/include -L/usr/lib -lmlx -lX11 -lXext

SRCS = main.c src/map_parser.c src/free_and_close.c src/validate.c src/render.c src/utils.c src/controls.c \
		src/pathfinding.c get-next-line/get_next_line.c get-next-line/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

SRCS_PRINTF = ft_printf/ft_printf.c ft_printf/ft_putchar_pf.c ft_printf/ft_puthex_pf.c \
			ft_printf/ft_putnbr_pf.c ft_printf/ft_putstr_pf.c
OBJS_PRINTF = $(SRCS_PRINTF:.c=.o)

HEADERS = includes/so_long.h

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(OBJS_PRINTF) $(MLX_FLAGS) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@
clean:
	rm -f $(OBJS) $(OBJS_PRINTF)

fclean: clean
	rm -f $(NAME)

re: fclean all
