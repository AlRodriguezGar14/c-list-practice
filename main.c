/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alberrod <alberrod@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 02:38:47 by alberrod          #+#    #+#             */
/*   Updated: 2024/01/19 10:14:34 by alberrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**parse_string(int argc, char **argv)
{
	char	**input;
	int		idx;
	int		jdx;

	idx = 0;
	jdx = -1;
	if (argc < 2)
		exit (1);
	if (argc == 2)
		input = ft_split(argv[1], ' ');
	else
	{
		input = (char **)ft_calloc(argc, sizeof(char *));
		while (++idx < argc)
			input[++jdx] = ft_strdup(argv[idx]);
	}
	return (input);
}

t_dll	*parse_input(int argc, char **argv)
{
	int		idx;
	char	**input;
	t_dll	*stack;

	stack = new_dll();
	input = parse_string(argc, argv);
	idx = 0;
	while (input[idx])
	{
		append(stack, ft_atoi(input[idx]));
		idx++;
	}
	return (stack);
}

int	*sort_input(t_dll stack)
{
	int		*out;
	size_t	idx;
	t_node	*curr;

	out = (int *)malloc(stack.len * sizeof(int));
	if (!out)	
		return (NULL);
	idx = 0;
	curr = stack.head;
	while (idx < stack.len)
	{
		out[idx++] = curr->value;
		curr = curr->next;
	}
	quicksort(out, 0, (int)stack.len - 1);
	return (out);	
}

int main(int argc, char **argv)
{
	t_dll	*stack_a;
	int		*sorted_arr = NULL;

	stack_a = parse_input(argc, argv);
	sorted_arr = sort_input(*stack_a);
	// pending when parse:
	//		check that no number is duplicated
	//		check that no chars are present in the input
	// pending after parse:
	// 		DONE: copy the content of stack_a to a integer array to sort it
	//		map the indexes of the sorted array to the list

	// test that the input has been properly parsed to the dll
	size_t idx = 0;
	while (idx < stack_a->len)
		printf("%d, ", sorted_arr[idx++]);

	return (0);
}