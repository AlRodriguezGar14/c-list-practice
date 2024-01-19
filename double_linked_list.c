/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alberrod <alberrod@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 02:38:47 by alberrod          #+#    #+#             */
/*   Updated: 2024/01/18 20:21:55 by alberrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "libft/libft.h"
#include "heap_tools.c"

int main()
{
	t_dll	*a;
	int		idx = 0;

	a = new_dll();
	while (idx++ < 500)
		append(a, rand());
	// append(a, 50);
	// append(a, 500);
	// append(a, 5);
	// append(a, 10);
	// append(a, 42);
	// append(a, 24);
	// append(a, 542);
	sort(a);
	idx = 0;
	t_node *curr = a->head;
	while (idx < a->len)
	{
		printf("%d ", curr->value);
		curr = curr->next;
		idx++;
	}

	return (0);
}
// void	sort_useless(t_dll *a)
// {
// 	t_dll	*b;
// 	t_node	*pivot;
// 	int		iteration;

// 	b = new_dll();
// 	iteration = 0;
// 	while (a->len > 0)
// 	{
// 		pivot = new_node(a->head->value);
// 		pull(a);
// 		while (b->len && b->head->value > pivot->value)
// 		{
// 			push_to(b, a);
// 			ft_printf("b to a\n");
// 			iteration++;
// 		}
// 		// push_to(a, b);
// 		push(b, pivot->value);
// 		ft_printf("a to b\n");
// 		iteration++;
// 	}
// 	while (b->len)
// 	{
// 		push_to(b, a);
// 		ft_printf("b to a\n");
// 		iteration++;
// 	}
// 	ft_printf("iterations: %d\n", iteration);
// }

// int	main(void)
// {
// 	t_dll	*stack_a;
// 	t_dll	*stack_b;
// 	int		idx;

// 	stack_a = new_dll();
// 	stack_b = new_dll();
// 	if (!stack_a)
// 		exit(EXIT_FAILURE);
// 	idx = 0;
// 	while (idx < 10 )
// 	{
// 		append(stack_a, idx);
// 		idx++;
// 	}
// 	idx = 0;
// 	// swap(stack_a);
// 	// pull(stack_a);
// 	// swap(stack_a);
// 	// push_to(stack_a, stack_b);
// 	// push_to(stack_a, stack_b);
// 	// push_to(stack_a, stack_b);
// 	// pull(stack_a);
// 	// pull(stack_a);
// 	// pull(stack_a);
// 	// pull(stack_a);
// 	// pull(stack_a);
// 	// push(stack_a, 42);
// 	while (idx < stack_a->len)
// 	{
// 		// pull(stack_a);
// 		// append(stack_a, 2);
// 		// ft_printf("nbr a: %d |", stack_a->head->value);
// 		// stack_a->head = stack_a->head->next;
// 		// ft_printf("| nbr b: %d\n", stack_b->head->value);
// 		// stack_b->head = stack_b->head->next;
// 		// ft_printf("nbr a head: %d\n", stack_a->head->value);
// 		// stack_a->head = stack_a->head->next;
// 		idx++;
// 	}
// 	ft_printf("\n=====\n");
// 	push_to(stack_a, stack_b);
// 	push_to(stack_a, stack_b);
// 	push_to(stack_a, stack_b);
// 	push_to(stack_a, stack_b);
// 	push_to(stack_a, stack_b);
// 	rotation(stack_b);
// 	rotation(stack_b);
// 	reverse_rotation(stack_b);
// 	reverse_rotation(stack_b);
// 	// rotation(stack_b);
// 	idx = 0;	
// 	while (idx < stack_b->len)
// 	{
// 		ft_printf("nbr b: %d\n", stack_b->head->value);
// 		stack_b->head = stack_b->head->next;
// 		idx++;
// 	}
//   while (stack_a->len)
//     pull(stack_a);
//   while (stack_b->len)
//     pull(stack_b);
//   free(stack_a);
//   free(stack_b);
// 	return (EXIT_SUCCESS);
// }
