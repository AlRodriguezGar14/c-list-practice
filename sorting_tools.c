/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alberrod <alberrod@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:22:34 by alberrod          #+#    #+#             */
/*   Updated: 2024/01/26 05:42:39 by alberrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	partitioner(int *arr, int lo, int hi)
{
	int	idx;
	int	pivot;
	int	tmp;

	idx = lo - 1;
	pivot = arr[hi];

	while (lo < hi)
	{
		if (arr[lo] <= pivot)
		{
			idx++;
			tmp = arr[idx];
			arr[idx] = arr[lo];
			arr[lo] = tmp;
		}
		lo++;
	}
	idx++;
	arr[hi] = arr[idx];
	arr[idx] = pivot;
	return (idx);
}

void	quicksort(int *arr, int lo, int hi)
{
	int	pivot_idx;

	if (lo >= hi)
		return ;
	pivot_idx = partitioner(arr, lo, hi);

	quicksort(arr, pivot_idx + 1, hi);
	quicksort(arr, lo, pivot_idx - 1);
		
}

int	is_sorted(t_dll *stack)
{
	int	idx;

	t_node *curr = stack->head;
	idx = -1;
	while (++idx < stack->len - 1)
	{
		if (curr->value >= curr->next->value)	
			return (0);
		curr = curr->next;
	}
	return (1);
}
