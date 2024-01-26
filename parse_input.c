/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alberrod <alberrod@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:10:33 by alberrod          #+#    #+#             */
/*   Updated: 2024/01/26 07:12:45 by alberrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

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
		{
			if (ft_strchr(argv[idx], ' '))
				ft_error("Input Error: multiple separator types used");
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
	idx = 0;
	while (input[idx])
	{
		append(stack, push_swap_atoi(input[idx]));
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
				ft_error_int("Input Error: duplicate numbers found", arr[idx]);
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

int	push_swap_atoi(const char *str)
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
		ft_error_str("Wrong input format or non-numeric input", og);
	while (ft_isdigit(*str))
		output = output * 10 + (*str++ - '0');
	if (*str != '\0')
		ft_error_str("Wrong input format or non-numeric input", og);
	if ((output * operator > INT_MAX) || (output * operator) < INT_MIN)
		ft_error("Wrong input format: not all the numbers are integers");
	return (output * operator);
}
