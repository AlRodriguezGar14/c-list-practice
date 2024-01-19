/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alberrod <alberrod@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:22:34 by alberrod          #+#    #+#             */
/*   Updated: 2024/01/19 02:00:02 by alberrod         ###   ########.fr       */
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

// int	main()
// {
// 	// 9 numbers
// 	int	arr[] = {43, 56, 3, 8, 10, 2, 60, 20, 11};
	
// 	quicksort(arr, 0, 8);
// 	int	idx = 0;
// 	while (idx++ < 9)
// 		printf("%d, ", arr[idx]);
// 	return (0);	
// }