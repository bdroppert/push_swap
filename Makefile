NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra -g

SRC =	main.c \
		error_check.c \
		opperations.c \
		actions.c \
		actions_2.c \
		actions_3.c \
		radix.c \
		sort.c \
		
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	@echo "Removing object files..."
	rm -f $(OBJS)

fclean: clean
	@echo "Removing library archive $(NAME)..."
	rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re