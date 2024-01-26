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
    while (++idx < a->len)
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

static unsigned int find_max(t_dll **stack)
{
    t_node *curr;
    unsigned int    max;
    int    idx;

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
    return max;
}

static unsigned int get_max_bits(t_dll **stack)
{
    unsigned int max;
    unsigned int max_bits;

    max = find_max(stack);
    max_bits = 0;
    while ((max >> max_bits) != 0)
        max_bits++;
    return max_bits;
}

static void sort_on_bit(t_dll **stack_a, t_dll **stack_b, int bit)
{
    int idx;
    int size;
    t_node *head_a;

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

static void move_back_to_a(t_dll **stack_a, t_dll **stack_b)
{
    while ((*stack_b)->len != 0)
        push_to(*stack_b, *stack_a, "pa");
}

void    sort_five(t_dll **a, t_dll **b)
{
    int moved_b = 0;
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

void radix_sort(t_dll **stack_a, t_dll **stack_b)
{
    int idx;
    int max_bits;
    
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
