/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alberrod <alberrod@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 01:49:11 by alberrod          #+#    #+#             */
/*   Updated: 2024/01/27 12:12:01 by alberrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				value;
	unsigned int	final_idx;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_dll
{
	int				len;
	struct s_node	*head;
	struct s_node	*tail;
}	t_dll;

// deal with the input
t_dll			*parse_input(int argc, char **argv);
int				*sort_input(t_dll stack);
int				push_swap_atoi(const char *str);

// stack builder
t_dll			*new_dll(void);
t_node			*new_node(int value);
void			free_dll(t_dll **dll);
void			push(t_dll *bucket, t_node *node);
t_node			*pull(t_dll *bucket);

// stack tools
// void	push(t_dll *bucket, int value);
void			push(t_dll *bucket, t_node *node);
// void	pull(t_dll *bucket);
t_node			*pull(t_dll *bucket);
void			append(t_dll *bucket, int value);

// stack sort
void			quicksort_stack(t_dll *main_stack, t_dll *temp_stack);
void			assign_idx(t_dll **stack, int *arr);

void			sort_three(t_dll **a);
void			sort_five(t_dll **a, t_dll **b);
void			radix_sort(t_dll **a, t_dll **b);

// stack sort utils
t_node			*find_biggest(t_dll *a);
unsigned int	find_max(t_dll **stack);
unsigned int	get_max_bits(t_dll **stack);
void			sort_on_bit(t_dll **stack_a, t_dll **stack_b, int bit);
void			move_back_to_a(t_dll **stack_a, t_dll **stack_b);

// allowed functions
	// p -> pa, pb
	// send top of x to top of y
void			push_to(t_dll *from, t_dll *to, char *action);
	// s -> sa sb ss
	// swap top numbers
void			swap(t_dll *bucket, char *action);
	// r -> ra, rb rr
	// Rotate from head to tail
void			rotation(t_dll *bucket, char *action);
	// rr -> rra, rrb, rrr
	// Rotate from tail to head
void			reverse_rotation(t_dll *bucket, char *action);

// sorting tools
void			quicksort(int *arr, int lo, int hi);
int				is_sorted(t_dll *inp);

// end with error
void			ft_error_int(char *str, int nbr);
void			ft_error_str(char *str, char *err);
void			ft_error(char *str);

#endif
