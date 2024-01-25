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

// The biggest number in the stack
static unsigned int find_max(t_dll **stack)
{
    t_node *curr;
    unsigned int max;

    curr = (*stack)->head;
    max = curr->final_idx;
    while (curr)
    {
        if (curr->final_idx > max)
            max = curr->final_idx;
        curr = curr->next;
    }
    return max;
}

// Function to calculate the number of bits needed to represent the maximum value
// >> is used to calculate the number of bits needed to
// represent the max value in the list
// Suppose max is 14 (1110 in binary). The loop would execute as follows:
// Iteration 1: max >> 0 (no shift) is still 1110, not equal to 0.
// Iteration 2: max >> 1 (right shift by 1) is 0111, not equal to 0.
// Iteration 3: max >> 2 (right shift by 2) is 0011, not equal to 0.
// Iteration 4: max >> 3 (right shift by 3) is 0001, not equal to 0.
// Iteration 5: max >> 4 (right shift by 4) is 0000, equal to 0. Exit the loop.
// In this example, max_bits becomes 4, indicating that 4 bits are needed to represent the maximum value 12 in binary.
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

// Function to sort the stack based on a specific bit
//  If the bit is 1, the number is rotated to the end of the stack (think of it as moving it to the end of the line). 
//  If the bit is 0, the number is pushed to another stack (think of it as moving it to a different line).
static void sort_on_bit(t_dll **stack_a, t_dll **stack_b, int bit)
{
    int idx;
    int size;
    t_node *head_a;

    size = (*stack_a)->len;  // Get the size of stack_a
    idx = -1;
    // Loop through each node in stack_a
    while (++idx < size)
    {
        head_a = (*stack_a)->head;  // Get the head node of stack_a

        // Check if the 'bit'-th bit of the value of the head node is 1
        // '>>' is the right shift operator. It shifts the bits of the number to the right and fills 0 on voids left as a result.
        // 'head_a->value >> bit' shifts the bits of the value to the right 'bit' times.
        // '& 1' is a bitwise AND operation with 1. It checks if the last bit of the number is 1.
        // If the 'bit'-th bit of the value is 1, rotate stack_a. Otherwise, push the head node of stack_a to stack_b.

        // Simplifying the logic of radix, we are reducing the bits to the minimum (>> bit number of times).
        // Then, like a deck of cards, we split the numbers in two blocks based in if the end bit is 0 of 1
        // as if we were separating between odd and even numbers.
        // When we perform radix sort on a set of numbers, we start from the least significant bit (the rightmost bit) 
        // and move towards the most significant bit (the leftmost bit).
        if (((head_a->final_idx >> bit) & 1) == 1)
            rotation(*stack_a, "ra");  // 'ra' stands for rotate stack_a
        else
            push_to(*stack_a, *stack_b, "pb");  // 'pb' stands for push to stack_b
    }
}

// Function to move all nodes back from stack b to stack a
static void move_back_to_a(t_dll **stack_a, t_dll **stack_b)
{
    while ((*stack_b)->len != 0)
        push_to(*stack_b, *stack_a, "pa");
}

// LSD sort; from the least significant bit to the most (max_bits - 1)
// Explaination of how this sorting is possible:
// https://www.youtube.com/watch?v=Uey0-GOMtT8
// How bit imeplementation works:
// https://www.youtube.com/watch?v=dPwAA7j-8o4
// https://www.youtube.com/watch?v=y52JkxUTg-o
// https://www.youtube.com/watch?v=iS0S7F2U4-o

// more information:
// https://www.cs.princeton.edu/courses/archive/spr02/cs226/lectures/radix.4up.pdf
void radix_sort(t_dll **stack_a, t_dll **stack_b)
{
    int idx;
    int max_bits;
    
    idx = -1;
    max_bits = get_max_bits(stack_a);
    while (++idx < max_bits)
    {
        sort_on_bit(stack_a, stack_b, idx);
        move_back_to_a(stack_a, stack_b);
    }
}



// Understanding the logic behind Radix algorithm:
// Let's say we have the numbers 1, 2, 3, and 4 to sort, and we'll represent them in binary:

// 1 in binary is 0001
// 2 in binary is 0010
// 3 in binary is 0011
// 4 in binary is 0100
// Now, we'll sort these numbers using the radix sort algorithm:

// First pass (least significant bit): We look at the rightmost bit (least significant bit) of each number. If the bit is 1, we move the number to the end of the line. If the bit is 0, we move the number to a different line. After this pass, our numbers are arranged as follows:

// Line A: 2 (0010), 4 (0100)

// Line B: 1 (0001), 3 (0011)

// Second pass (second bit): We now look at the second bit from the right. Again, if the bit is 1, we move the number to the end of the line. If the bit is 0, we move the number to a different line. After this pass, our numbers are arranged as follows:

// Line A: 1 (0001)

// Line B: 2 (0010), 4 (0100), 3 (0011)

// Third pass (third bit): We now look at the third bit from the right. After this pass, our numbers are arranged as follows:

// Line A: 1 (0001), 2 (0010)

// Line B: 4 (0100), 3 (0011)

// Fourth pass (most significant bit): We now look at the leftmost bit (most significant bit). After this pass, our numbers are arranged as follows:

// Line A: 1 (0001), 2 (0010), 3 (0011)

// Line B: 4 (0100)

// At the end of these four passes, our numbers are sorted in ascending order: 1, 2, 3, 4. This is how the radix sort algorithm works. It systematically sorts numbers bit by bit, starting from the least significant bit and moving to the most significant bit.