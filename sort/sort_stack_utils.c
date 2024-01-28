/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alberrod <alberrod@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 07:15:39 by alberrod          #+#    #+#             */
/*   Updated: 2024/01/26 07:26:02 by alberrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_biggest(t_dll *a)
{
	t_node	*biggest_val;	
	t_node	*curr;	
	int		idx;

	idx = -1;
	curr = a->head;
	biggest_val = a->head;
	while (++idx < a->len)
	{
		if (curr->final_idx > biggest_val->final_idx)
			biggest_val = curr;
		curr = curr->next;
	}
	return (biggest_val);
}

unsigned int	find_max(t_dll **stack)
{
	t_node			*curr;
	unsigned int	max;
	int				idx;

	curr = (*stack)->head;
	max = curr->final_idx;
	idx = 0;
	while (idx < (*stack)->len)
	{
		if (curr->final_idx > max)
			max = curr->final_idx;
		curr = curr->next;
		idx++;
	}
	return (max);
}

unsigned int	get_max_bits(t_dll **stack)
{
	unsigned int	max;
	unsigned int	max_bits;

	max = find_max(stack);
	max_bits = 0;
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	sort_on_bit(t_dll **stack_a, t_dll **stack_b, int bit)
{
	int		idx;
	int		size;
	t_node	*head_a;

	size = (*stack_a)->len;
	idx = -1;
	while (++idx < size)
	{
		head_a = (*stack_a)->head;
		if (((head_a->final_idx >> bit) & 1) == 1)
			rotation(*stack_a, "ra");
		else
			push_to(*stack_a, *stack_b, "pb");
	}
}

void	move_back_to_a(t_dll **stack_a, t_dll **stack_b)
{
	while ((*stack_b)->len != 0)
		push_to(*stack_b, *stack_a, "pa");
}
