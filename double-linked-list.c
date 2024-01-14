/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double-linked-list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alberrod <alberrod@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 02:38:47 by alberrod          #+#    #+#             */
/*   Updated: 2024/01/14 09:11:14 by alberrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>


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

// p -> pa, pb
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
	bucket->head = bucket->head->next;
	bucket->head->prev = bucket->tail;
	bucket->tail->next = bucket->head;
	bucket->len--;
}

// s -> sa sb ss
void	swap(t_dll *bucket)
{
	int	tmp;

	if (bucket->len < 2)
		return ;
	tmp = bucket->head->value;
	bucket->head->value = bucket->head->next->value;
	bucket->head->next->value = tmp;
}
// void swap(t_dll *bucket)
// {
// 	t_node *tmp;

// 	if (bucket->len < 2)
// 		return;

// 	tmp = bucket->head;
// 	bucket->head = bucket->head->next;
// 	bucket->head->prev = NULL;
// 	tmp->next = bucket->head->next;
// 	tmp->prev = bucket->head;
// 	bucket->head->next = tmp;
// 	if (tmp->next)
// 		tmp->next->prev = tmp;
// 	if (bucket->tail == bucket->head)
// 		bucket->tail = tmp;
// }



int	main(void)
{
	t_dll	*stack_a;
	int		idx;

	stack_a = new_dll();
	if (!stack_a)
		exit(EXIT_FAILURE);
	idx = 0;
	while (idx <= 10 )
	{
		push(stack_a, idx);
		idx++;
	}
	idx = 0;
	swap(stack_a);
	pull(stack_a);
	swap(stack_a);
	while (idx < stack_a->len)
	{
		printf("nbr %d\n", stack_a->head->value);
		stack_a->head = stack_a->head->next;
		idx++;
	}
	return (EXIT_SUCCESS);
}