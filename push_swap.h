/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alberrod <alberrod@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 01:49:11 by alberrod          #+#    #+#             */
/*   Updated: 2024/01/23 13:50:11 by alberrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

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
} t_node;

typedef struct s_dll
{
	int				len;
	struct s_node	*head;
	struct s_node	*tail;
} t_dll;


// deal with the input
t_dll	*parse_input(int argc, char **argv);
int	*sort_input(t_dll stack);
int	push_swap_atoi(const char *str);

// stack builder
t_dll	*new_dll(void);
t_node	*new_node(int value);

// stack tools
void	push(t_dll *bucket, int value);
void	pull(t_dll *bucket);
void	append(t_dll *bucket, int value);

// stack sort
void quicksort_stack(t_dll *main_stack, t_dll *temp_stack);
void	sort_three(t_dll **a, int *sorted);
void	assign_idx(t_dll **stack, int *arr);

// allowed functions
	// p -> pa, pb
	// send top of x to top of y
void	push_to(t_dll *from, t_dll *to, char *action);
	// s -> sa sb ss
	// swap top numbers
void	swap(t_dll *bucket, char *action);
	// r -> ra, rb rr
	// Rotate from head to tail
void	rotation(t_dll *bucket, char *action);
	// rr -> rra, rrb, rrr
	// Rotate from tail to head
void	reverse_rotation(t_dll *bucket, char *action);

// sorting tools
void	quicksort(int *arr, int lo, int hi);
int	is_sorted(t_dll *inp);

#endif