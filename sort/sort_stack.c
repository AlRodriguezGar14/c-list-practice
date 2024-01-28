/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alberrod <alberrod@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 01:52:22 by alberrod          #+#    #+#             */
/*   Updated: 2024/01/26 07:22:39 by alberrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_dll **a)
{
	t_node	*biggest_node;

	biggest_node = find_biggest(*a);
	if (biggest_node->value == (*a)->head->value)
		rotation(*a, "ra");
	else if (biggest_node->value == (*a)->head->next->value)
		reverse_rotation(*a, "rra");
	if ((*a)->head->value > (*a)->head->next->value)
		swap(*a, "sa");
}

void	sort_five(t_dll **a, t_dll **b)
{
	int	moved_b;

	moved_b = 0;
	while ((*a)->head->final_idx != 0)
	{
		rotation(*a, "ra");
		if ((*a)->head->final_idx == 1)
		{
			push_to(*a, *b, "pb");
			moved_b = 1;
		}
	}
	push_to(*a, *b, "pb");
	if (moved_b == 0)
	{
		while ((*a)->head->final_idx != 1)
			rotation(*a, "ra");
		push_to(*a, *b, "pb");
	}
	if ((*b)->head->final_idx < (*b)->head->next->final_idx)
		swap(*b, "sb");
	sort_three(a);
	move_back_to_a(a, b);
}

void	radix_sort(t_dll **stack_a, t_dll **stack_b)
{
	int	idx;
	int	max_bits;

	idx = -1;
	max_bits = get_max_bits(stack_a);
	while (++idx < max_bits && idx < 100)
	{
		sort_on_bit(stack_a, stack_b, idx);
		move_back_to_a(stack_a, stack_b);
		if (is_sorted(*stack_a))
			break ;
	}
}
