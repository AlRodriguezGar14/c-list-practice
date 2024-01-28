/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alberrod <alberrod@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:43:21 by alberrod          #+#    #+#             */
/*   Updated: 2024/01/28 16:47:04 by alberrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	while (ft_isdigit(*str))
		output = output * 10 + (*str++ - '0');
	return (free(og), output * operator);
}

void	free_str(char **str, int max_idx)
{
	int	idx;

	idx = 0;
	while (idx < max_idx)
		free(str[idx++]);
}
