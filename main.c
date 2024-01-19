/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alberrod <alberrod@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 02:38:47 by alberrod          #+#    #+#             */
/*   Updated: 2024/01/19 05:21:00 by alberrod         ###   ########.fr       */
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

int main(int argc, char **argv)
{
	t_dll	*stack_a;

	stack_a = parse_input(argc, argv);
	// pending when parse:
	//		check that no number is duplicated
	//		check that no chars are present in the input
	// pending after parse:
	// 		copy the content of stack_a to a integer array to sort it
	//		map the indexes of the sorted array to the list

	// test that the input has been properly parsed to the dll
	size_t idx = 0;
	t_node	*curr = stack_a->head;
	while (idx < stack_a->len)
	{
		printf("%d, ", curr->value);
		curr = curr->next;
		idx++;
	}

	return (0);
}