/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alberrod <alberrod@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:10:33 by alberrod          #+#    #+#             */
/*   Updated: 2024/01/28 16:48:54 by alberrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_input(const char *str)
{
	int		operator;
	char	*og;
	long	output;

	og = ft_strdup(str);
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	operator = 1;
	if ((*str == '-') || (*str == '+'))
	{
		if (*str++ == '-')
			operator *= -1;
	}
	output = 0;
	if (!ft_isdigit(*str))
		return (ft_error_str("Error: input format/non-numeric input", og), 1);
	while (ft_isdigit(*str))
		output = output * 10 + (*str++ - '0');
	if (*str != '\0')
		return (ft_error_str("Error: input format/non-numeric input", og), 1);
	if ((output * operator > INT_MAX) || (output * operator) < INT_MIN)
		return (free(og), ft_error("Error: not all the numbers are int"), 1);
	return (free(og), 0);
}

static char	**parse_string(int argc, char **argv)
{
	char	**input;
	int		idx;
	int		jdx;

	idx = 0;
	jdx = -1;
	if (argc < 2)
		return (NULL);
	if (argc == 2)
		input = ft_split(argv[1], ' ');
	else
	{
		input = (char **)ft_calloc(argc, sizeof(char *));
		while (++idx < argc)
		{
			if (ft_strchr(argv[idx], ' '))
			{
				ft_error("Error: multiple separators");
				return (free_str(input, argc), free(input), NULL);
			}
			input[++jdx] = ft_strdup(argv[idx]);
		}
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
	if (!input)
		return (free_dll(&stack), NULL);
	idx = 0;
	while (input[idx])
	{
		if (is_valid_input(input[idx]) == 1)
		{
			while (input[idx])
				free(input[idx++]);
			return (free(input), free_dll(&stack), NULL);
		}
		append(stack, push_swap_atoi(input[idx]));
		free(input[idx]);
		idx++;
	}
	return (free(input), stack);
}

static	int	find_duplicates(int *arr, int len)
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
				ft_error_int("Input Error: duplicate numbers found", arr[idx]);
				return (1);
			}
		}
	}
	return (0);
}

int	*sort_input(t_dll stack)
{
	int		*out;
	int		idx;
	t_node	*curr;
	int		err;

	err = 0;
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
	err = find_duplicates(out, stack.len);
	if (err)
		return (free(out), NULL);
	quicksort(out, 0, (int)stack.len - 1);
	return (out);
}
