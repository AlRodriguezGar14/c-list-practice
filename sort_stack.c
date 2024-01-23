/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alberrod <alberrod@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 01:52:22 by alberrod          #+#    #+#             */
/*   Updated: 2024/01/23 17:39:07y alberrod         ###   ########.fr       */
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

// void sort_stack(t_dll **a, t_dll **b)
// {
//     t_node *biggest_node;

//     // Move all but the three largest nodes from stack a to stack b
//     while ((*a)->len > 3)
//     {
//         biggest_node = find_biggest(*a);
//         while ((*a)->head != biggest_node)
//             rotation(*a, "ra");
//         push_to(*a, *b, "pb");
//     }

//     // Sort the remaining three nodes in stack a
//     sort_three(a);

//     // Move all nodes back from stack b to stack a
//     while ((*b)->len > 0)
//     {
//         biggest_node = find_biggest(*b);
//         while ((*b)->head != biggest_node)
//             rotation(*b, "rb");
//         push_to(*b, *a, "pa");
//         biggest_node = find_biggest(*a);
//         while ((*a)->head != biggest_node)
//             rotation(*a, "ra");
//     }
// }

static int get_max_bits(t_dll **stack)
{
    t_node *head;
    int max;
    int max_bits;

    head = (*stack)->head;
    max = head->value;
    max_bits = 0;
    while (head)
    {
        if (head->value > max)
            max = head->value;
        head = head->next;
    }
    while ((max >> max_bits) != 0)
        max_bits++;
    return max_bits;
}

void radix_sort(t_dll **stack_a, t_dll **stack_b)
{
    t_node *head_a;
    int i;
    int j;
    int size;
    int max_bits;

    i = 0;
    head_a = (*stack_a)->head;
    size = (*stack_a)->len;
    max_bits = get_max_bits(stack_a);
    while (i < max_bits)
    {
        j = 0;
        while (j++ < size)
        {
            head_a = (*stack_a)->head;
            if (((head_a->value >> i) & 1) == 1)
                rotation(*stack_a, "ra");
            else
                push_to(*stack_a, *stack_b, "pb");
        }
        while ((*stack_b)->len != 0)
            push_to(*stack_b, *stack_a, "pa");
        i++;
    }
}