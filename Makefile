NAME = philo

SRC = main.c utils.c check_error.c init.c time.c routine.c utils2.c monitor.c init2.c

OBJ = $(SRC:%.c=%.o)

CC = gcc -Wall -Werror -Wextra -pthread -g

%.o : %.c
	$(CC) -c -o $@ $^

$(NAME): $(OBJ)
	$(CC) -o $@ $(SRC)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean re
