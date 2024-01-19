/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alberrod <alberrod@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 01:49:11 by alberrod          #+#    #+#             */
/*   Updated: 2024/01/19 05:19:18 by alberrod         ###   ########.fr       */
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
	size_t			len;
	struct s_node	*head;
	struct s_node	*tail;
} t_dll;

// stack builder
t_dll	*new_dll(void);
t_node	*new_node(int value);

// stack tools
void	push(t_dll *bucket, int value);
void	pull(t_dll *bucket);
void	append(t_dll *bucket, int value);



// allowed functions
	// p -> pa, pb
	// send top of x to top of y
void	push_to(t_dll *from, t_dll *to);
	// s -> sa sb ss
	// swap top numbers
void	swap(t_dll *bucket);
	// r -> ra, rb rr
	// Rotate from head to tail
void	rotation(t_dll *bucket);
	// rr -> rra, rrb, rrr
	// Rotate from tail to head
void	reverse_rotation(t_dll *bucket);

// sorting
void	quicksort(int *arr, int lo, int hi);

#endif