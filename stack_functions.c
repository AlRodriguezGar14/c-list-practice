/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alberrod <alberrod@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:10:47 by alberrod          #+#    #+#             */
/*   Updated: 2024/01/28 03:44:54 by alberrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// p -> pa, pb
// send top of x to top of y
void	push_to(t_dll *from, t_dll *to, char *action)
{
	t_node	*node;

	if (!from->head || !to)
		return ;
	node = pull(from);
	push(to, node);
	ft_printf("%s\n", action);
}

// to build the input
void	append(t_dll *bucket, int value)
{
	t_node	*node;
	t_node	*tmp;

	if (!bucket)
		return ;
	node = new_node(value);
	if (!bucket->tail)
	{
		bucket->tail = node;
		bucket->head = node;
	}
	else
	{
		tmp = bucket->tail;
		bucket->tail = node;
		bucket->tail->prev = tmp;
		bucket->tail->prev->next = bucket->tail;
	}
	bucket->len++;
}

// s -> sa sb ss
// swap top numbers
void	swap(t_dll *bucket, char *action)
{
	t_node	*tmp;

	if (bucket->len < 2)
		return ;
	tmp = bucket->head;
	bucket->head = bucket->head->next;
	bucket->head->prev = tmp->prev;
	tmp->next = bucket->head->next;
	bucket->head->next = tmp;
	tmp->prev = bucket->head;
	if (tmp->next != NULL)
		tmp->next->prev = tmp;
	if (bucket->tail == tmp)
		bucket->tail = bucket->head;
	ft_printf("%s\n", action);
}

// r -> ra, rb rr
// Rotate from head to tail
void	rotation(t_dll *bucket, char *action)
{
	t_node	*tmp;

	if (bucket->len <= 1)
		return ;
	tmp = bucket->head;
	bucket->head = tmp->next;
	tmp->prev = bucket->tail;
	tmp->prev->next = tmp;
	bucket->tail = tmp;
	tmp->next = bucket->head;
	ft_printf("%s\n", action);
}

// rr -> rra, rrb, rrr
// Rotate from tail to head
void	reverse_rotation(t_dll *bucket, char *action)
{
	t_node	*tmp;

	if (bucket->len <= 1)
		return ;
	tmp = bucket->tail;
	bucket->tail = tmp->prev;
	bucket->tail->next = bucket->head;
	tmp->prev = bucket->tail;
	tmp->next = bucket->head;
	bucket->head->prev = tmp;
	bucket->head = tmp;
	ft_printf("%s\n", action);
}
