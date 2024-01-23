/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alberrod <alberrod@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 01:52:22 by alberrod          #+#    #+#             */
/*   Updated: 2024/01/23 16:17:20 by alberrod         ###   ########.fr       */
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
        if (curr->value > biggest_val->value) // Compare values, not final_idx
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

void sort_stack(t_dll **a, t_dll **b, int *sorted_arr)
{
	(void)sorted_arr;
    while ((*a) && (*a)->len > 3)
    {
        push_to(*a, *b, "pb");
    }
    sort_three(a);
	// assign_idx(a, sorted_arr);
	// assign_idx(b, sorted_arr);
    while ((*b) && (*b)->len > 0)
    {
        push_to(*b, *a, "pa");
    }
	// assign_idx(a, sorted_arr);
	// assign_idx(b, sorted_arr);
}

// TODO:
// Fix the push_to and reverse rotation functions. They are not
// moving the indexes