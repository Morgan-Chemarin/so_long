NAME = libftprintf.a
FLAGS = -Werror -Wall -Wextra
CC = cc
AR = ar rcs

SRC = ft_printf.c ft_putchar_pf.c ft_puthex_pf.c ft_putnbr_pf.c ft_putstr_pf.c ft_utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all