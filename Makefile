# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alberrod <alberrod@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/19 02:07:14 by alberrod          #+#    #+#              #
#    Updated: 2024/01/27 12:58:59 by alberrod         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC       = cc
HEADERS_DIR = .
CFLAGS   = -Wall -Wextra -Werror -g3 -I $(HEADERS_DIR) -I $(LIBFT_DIR)
NAME     = push_swap
RM       = rm -rf
# CHECKER  = checker_linux
CHECKER  = checker_Mac 

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


test3: $(NAME)
	@NUM=3; \
	ARG=(); \
	for i in $$(seq $$NUM); do \
		rand=$$((RANDOM)); \
		while echo "$${ARG[@]}" | grep -q -w $$rand; do \
			rand=$$((RANDOM)); \
		done; \
		ARG+=($$rand); \
	done; \
	ARG="$${ARG[*]}"; \
	echo "ARG: $$ARG"; \
	./push_swap $$ARG | ./$(CHECKER) $$ARG && ./push_swap $$ARG | wc -l 
test5: $(NAME)
	@NUM=5; \
	ARG=(); \
	for i in $$(seq $$NUM); do \
		rand=$$((RANDOM)); \
		while echo "$${ARG[@]}" | grep -q -w $$rand; do \
			rand=$$((RANDOM)); \
		done; \
		ARG+=($$rand); \
	done; \
	ARG="$${ARG[*]}"; \
	echo "ARG: $$ARG"; \
	./push_swap $$ARG | ./$(CHECKER) $$ARG && ./push_swap $$ARG | wc -l 
test100: $(NAME)
	@NUM=100; \
	ARG=(); \
	for i in $$(seq $$NUM); do \
		rand=$$((RANDOM)); \
		while echo "$${ARG[@]}" | grep -q -w $$rand; do \
			rand=$$((RANDOM)); \
		done; \
		ARG+=($$rand); \
	done; \
	ARG="$${ARG[*]}"; \
	echo "ARG: $$ARG"; \
	./push_swap $$ARG | ./$(CHECKER) $$ARG && ./push_swap $$ARG | wc -l 
test500: $(NAME)
	@NUM=500; \
	ARG=(); \
	for i in $$(seq $$NUM); do \
		rand=$$((RANDOM)); \
		while echo "$${ARG[@]}" | grep -q -w $$rand; do \
			rand=$$((RANDOM)); \
		done; \
		ARG+=($$rand); \
	done; \
	ARG="$${ARG[*]}"; \
	echo "ARG: $$ARG"; \
	./push_swap $$ARG | ./$(CHECKER) $$ARG && ./push_swap $$ARG | wc -l 


.PHONY: all clean fclean re test3 test5 test100 test500
 
