/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alberrod <alberrod@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:22:34 by alberrod          #+#    #+#             */
/*   Updated: 2024/01/21 06:21:10 by alberrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Quicksort an array:
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
