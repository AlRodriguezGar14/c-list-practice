/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double-linked-list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alberrod <alberrod@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 02:38:47 by alberrod          #+#    #+#             */
/*   Updated: 2024/01/14 03:32:32 by alberrod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>


typedef struct s_node
{
	void			*content;
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

t_node	*new_node(void *content)
{
	t_node	*new;

	new = (t_node*)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	push(t_dll *bucket, void *content)
{
	t_node	*node;
	t_node	*tmp;
	if (!bucket || !content)
		return ;
	node = new_node(content);
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

int	main(void)
{
	t_dll	*stack_a;

	stack_a = new_dll();
	// printf("stack head: %s\n", (char*)stack_a->head->content);
	// printf("stack tail: %s\n", (char*)stack_a->tail->content);
	push(stack_a, "hola");
	printf("pushed hola\n");
	printf("stack head: %s\n", (char*)stack_a->head->content);
	printf("stack tail: %s\n", (char*)stack_a->tail->content);
	push(stack_a, "adios");
	printf("pushed adios\n");
	printf("stack head: %s\n", (char*)stack_a->head->content);
	printf("stack tail: %s\n", (char*)stack_a->tail->content);
	push(stack_a, "que tal");
	printf("pushed que tal\n");
	printf("stack head: %s\n", (char*)stack_a->head->content);
	printf("stack tail: %s\n", (char*)stack_a->tail->content);
	return (0);
}