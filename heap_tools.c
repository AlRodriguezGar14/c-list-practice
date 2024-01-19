/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alberrod <alberrod@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:10:47 by alberrod          #+#    #+#             */
/*   Updated: 2024/01/18 20:21:40 by alberrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "libft/libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
} t_node;

typedef struct s_dll
{
	size_t			len;
	struct s_node	*head;
	struct s_node	*tail;
} t_dll;

t_dll	*new_dll(void)
{
	t_dll	*new;

	new = (t_dll*)malloc(sizeof(t_dll));
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

	new = (t_node*)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

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
void	push_to(t_dll *from, t_dll *to)
{
	if (!from->head || !to)
		return ;
	push(to, from->head->value);
	pull(from);
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
void	swap(t_dll *bucket)
{
	int	tmp;

	if (bucket->len < 2)
		return ;
	tmp = bucket->head->value;
	bucket->head->value = bucket->head->next->value;
	bucket->head->next->value = tmp;
}

// r -> ra, rb rr
// Rotate from head to tail
void	rotation(t_dll *bucket)
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
}

// rr -> rra, rrb, rrr
// Rotate from tail to head
void	reverse_rotation(t_dll *bucket)
{
	t_node	*tmp;

	if (bucket->len <= 1)
		return ;
	tmp = bucket->tail;
	bucket->tail = tmp->prev;
	tmp->next = bucket->head;
	tmp->next->prev = tmp;
	bucket->head = tmp;
	tmp->prev = bucket->tail;
}