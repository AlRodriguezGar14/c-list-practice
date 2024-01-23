/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alberrod <alberrod@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 02:38:47 by alberrod          #+#    #+#             */
/*   Updated: 2024/01/23 02:46:18 by alberrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_value(int nbr, int *arr, int max_len)
{
    int	idx;

    idx = 0;
	while (idx < max_len)
	{
		if (arr[idx] == nbr) 
			return (idx);
		idx++;
	}
    return idx;
}

void	assign_idx(t_dll **stack, int *arr)
{
	int		idx;
	t_node	*curr;

	idx = 0;
	curr = (*stack)->head;
	while (idx < (*stack)->len)
	{
		curr->final_idx = find_value(curr->value, arr, (*stack)->len);
		curr = curr->next;
		idx++;
	}
}

int main(int argc, char **argv)
{
	t_dll	*stack_a;
	// t_dll	*stack_b;
	t_node 	*curr;
	int		*sorted_arr = NULL;

	// stack_b = new_dll();
	stack_a = parse_input(argc, argv);
	sorted_arr = sort_input(*stack_a);
	// pending when parse:
	//		DONE: check that no number is duplicated
	//		DONE: check that no chars are present in the input
	//		DONE: check only "" or spaces are used as separator
	// pending after parse:
	// 		DONE: copy the content of stack_a to a integer array to sort it
	//		DONE: map the indexes of the sorted array to the list

	// test that the input has been properly parsed to the dll
	assign_idx(&stack_a, sorted_arr);
	sort_three(&stack_a);
	int idx = 0;
	curr = stack_a->head;
	while (idx++ < stack_a->len)
	{
		printf(" %d ", curr->value);
		curr = curr->next;
	}
	printf("len: %d\n", stack_a->len);
	return (0);
}