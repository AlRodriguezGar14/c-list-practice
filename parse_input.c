/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alberrod <alberrod@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:10:33 by alberrod          #+#    #+#             */
/*   Updated: 2024/01/21 17:25:15 by alberrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**parse_string(int argc, char **argv)
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

static	void	find_duplicates(int *arr, int len)
{
	int	idx;	
	int	jdx;	
	int	matches;

	idx = -1;
	while (++idx < len)
	{
		jdx = idx;
		matches = 0;
		while (jdx < len)
		{
			if (arr[idx] == arr[jdx++])
				matches++;
			if (matches == 2)
			{
				ft_printf("Error: duplicate numbers found\n");
				exit(1);
			}
		}
	}
	
}

int	*sort_input(t_dll stack)
{
	int		*out;
	int		idx;
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
	find_duplicates(out, stack.len);
	quicksort(out, 0, (int)stack.len - 1);
	return (out);	
}
