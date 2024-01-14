/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double-linked-list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alberrod <alberrod@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 02:38:47 by alberrod          #+#    #+#             */
/*   Updated: 2024/01/14 04:12:43 by alberrod         ###   ########.fr       */
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

int	push(t_dll *bucket, int value)
{
	t_node	*node;
	t_node	*tmp;
	if (!bucket || !value)
		return (1);
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
	return (0);
}

int	main(void)
{
	t_dll	*stack_a;
	int		err;
	int		idx;

	stack_a = new_dll();
	if (!stack_a)
		exit(EXIT_FAILURE);
	idx = 1;
	while (idx <= 10 )
	{
		err = push(stack_a, idx);
		if (err)
			exit(EXIT_FAILURE);
		idx++;
	}
	while (stack_a->head)
	{
		printf("nbr %d\n", stack_a->head->value);
		stack_a->head = stack_a->head->next;
	}
	return (EXIT_SUCCESS);
}