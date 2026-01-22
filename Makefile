# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdropper <bdropper@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/08 15:36:08 by bdropper          #+#    #+#              #
#    Updated: 2026/01/21 16:30:06 by bdropper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)ft_printf.a

SRC =	main.c \
		error_check.c \

		
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	@echo "Linking library $@"
	$(AR) $@ $^

%.o: %.c push_swap.h
	@echo "Compiling $<"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Removing object files..."
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)fclean
	$(MAKE) -C $(PRINTF_DIR)fclean

fclean: clean
	@echo "Removing library archive $(NAME)..."
	rm -f $(NAME)
	rm -f $(LIBFT) $(PRINTF)
	$(MAKE) -C $(LIBFT_DIR)fclean
	$(MAKE) -C $(PRINTF_DIR)fclean
	
re: fclean all

.PHONY: all clean fclean re