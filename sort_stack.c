/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alberrod <alberrod@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 01:52:22 by alberrod          #+#    #+#             */
/*   Updated: 2024/01/23 15:03:56 by alberrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	t_node	*find_biggest(t_dll *a)
{
	t_node *biggest_val;	
	t_node *curr;	
	int		idx;

	idx = -1;
	curr = a->head;
	biggest_val = a->head;
	while (++idx < a->len - 1)
	{
		if (curr->final_idx > biggest_val->final_idx)
			biggest_val = curr;
		curr = curr->next;
	}
	return (biggest_val);
}

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