# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alberrod <alberrod@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/19 02:07:14 by alberrod          #+#    #+#              #
#    Updated: 2024/01/26 07:30:32 by alberrod         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC       = cc
HEADERS_DIR = .
CFLAGS   = -Wall -Wextra -Werror -g3 -fsanitize=address -I $(HEADERS_DIR) -I $(LIBFT)
NAME     = push_swap
RM       = rm -rf

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a
CFILES = main.c sorting_array_tools.c stack_builder.c stack_functions.c \
		parse_input.c sort_stack.c exit_error.c sort_stack_utils.c

OFILES = $(CFILES:.c=.o)

all: $(NAME)

# -L = library dir
# -lft = link the library.a
$(NAME): $(LIBFT) $(OFILES)
	$(CC) $(CFLAGS) -o $(NAME) $(OFILES) -L $(LIBFT_DIR) -lft

# -C = execute the command in the following directory
$(LIBFT):
	make -C $(LIBFT_DIR)
clean:
	$(RM) $(OFILES)
	make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
 
