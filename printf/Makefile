NAME = libftprintf.a

SRCS = ft_printf.c		\
       ft_putchar.c		\
	   ft_putstr.c		\
	   ft_putnbr.c		\
	   ft_format.c		\
	   ft_printhex.c	\
	   ft_printunsigned.c	\
	   ft_pointer.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
