NAME = pipex

SRCS =	pipex.c \
		pipex_utils.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -g3 -Wall -Wextra -Werror -fsanitize=address

all: $(NAME)

$(NAME): $(OBJS)
	@make -C ./libft
	@make -C ./printf
	$(CC) $(CFLAGS) $(OBJS)	libft/libft.a printf/libftprintf.a -o $(NAME)

clean:
	rm -f $(OBJS)
	rm -rf ./libft/*.o
	rm -rf ./printf/*.o

fclean: clean
	rm -f $(NAME)
	rm -rf libft/libft.a
	rm -rf printf/libftprintf.a

re: fclean all
