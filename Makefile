NAME = philo

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -pthread

SRCS = main.c \
		init.c \
		routine.c \
		utils.c \
		get_time.c

OBJS = ${SRCS:.c=.o}

all: $(NAME)

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)


fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean
