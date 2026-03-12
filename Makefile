NAME = philo

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRCS = main.c

OBJS = ${SRCS:.c=.o}

all: $(NAME)

%.o : %.c
	${CC} -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS)

clean:
	rm -f $(OBJS)


fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean