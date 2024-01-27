/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_builder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alberrod <alberrod@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 01:54:27 by alberrod          #+#    #+#             */
/*   Updated: 2024/01/27 12:17:45 by alberrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dll	*new_dll(void)
{
	t_dll	*new;

	new = (t_dll *)malloc(sizeof(t_dll));
	if (!new)
		return (NULL);
	new->len = 0;
	new->head = NULL;
	new->tail = NULL;
	return (new);
}

t_node	*new_node(int value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->final_idx = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	push(t_dll *bucket, t_node *node)
{
	if (!bucket || !node)
		return ;
	if (!bucket->head)
	{
		bucket->head = node;
		bucket->tail = node;
	}
	else
	{
		node->next = bucket->head;
		bucket->head->prev = node;
		bucket->head = node;
	}
	bucket->len++;
}

t_node	*pull(t_dll *bucket)
{
	t_node	*node;

	if (!bucket || bucket->len == 0)
		return (NULL);
	node = bucket->head;
	if (bucket->len > 1)
	{
		bucket->head = bucket->head->next;
		bucket->head->prev = NULL;
	}
	else
	{
		bucket->head = NULL;
		bucket->tail = NULL;
	}
	bucket->len--;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	free_dll(t_dll **dll)
{
	t_node *curr;
	t_node *next;
	int		idx;
	int		len;
	
	idx = 0;
	len = (*dll)->len;
	curr = (*dll)->head;
	while ((idx++ < len) && curr != NULL)
	{
		next = curr->next;
		free(curr);
		if (next != NULL)
			curr = next;
		else
			break;
	}
	free(*dll);
	*dll = NULL;
}