/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alberrod <alberrod@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:10:47 by alberrod          #+#    #+#             */
/*   Updated: 2024/01/23 13:44:03by alberrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_dll *bucket, int value)
{
	t_node	*node;
	t_node	*tmp;

	if (!bucket)
		return ;
	node = new_node(value);
	if (!bucket->head)
	{
		bucket->head = node;
		bucket->tail = node;
	}
	else
	{
		tmp = bucket->head;
		bucket->head = node;
		bucket->head->next = tmp;
		bucket->head->next->prev = bucket->head;
	}
	bucket->len++;
}

void	pull(t_dll *bucket)
{
  t_node *curr;

	if (!bucket || bucket->len == 0)
		return ;
  curr = bucket->head;
	bucket->head = bucket->head->next;
	bucket->head->prev = bucket->tail;
	bucket->tail->next = bucket->head;
	bucket->len--;
  free(curr);
	if (bucket->len <= 0)
		bucket = NULL;
}

// p -> pa, pb
// send top of x to top of y
void	push_to(t_dll *from, t_dll *to, char *action)
{
	if (!from->head || !to)
		return ;
	push(to, from->head->value);
	pull(from);
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
	int	tmp;

	if (bucket->len < 2)
		return ;
	tmp = bucket->head->value;
	bucket->head->value = bucket->head->next->value;
	bucket->head->next->value = tmp;
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
	bucket->head =  tmp->next;
	tmp->prev = bucket->tail;
	tmp->prev->next = tmp;
	bucket->tail = tmp;
	tmp->next = bucket->head;
	ft_printf("%s\n", action);
}

// rr -> rra, rrb, rrr
// Rotate from tail to head
void reverse_rotation(t_dll *bucket, char *action)
{
    t_node *tmp;

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