/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdropper <bdropper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:26:14 by bdropper          #+#    #+#             */
/*   Updated: 2026/01/22 16:16:06 by bdropper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_node	*stack_b;
	t_node	*stack_a;

	/*these are not stacks themselves they are pointers tothe first node of two linked lists*/
	stack_a = NULL;
	/*we set to null to make sure there is no garbage memory therefor the stacks are now empty*/
	stack_b = NULL;
	if (!error_check(argc, argv) || init_lists(stack_a, argc, argv))
		return (1);
	
	populate_list(stack_a);
	// build stack a
	// sort
	// free
	return (0);
}

t_node	*create_node(char *str, int i)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = atoi(str);
	new_node->index = i;
	return (new_node);
}

int	init_lists(t_node *stack_a, int argc, char **argv)
{
	int		i;
	t_node	*new_node;

	i = 1;
	while (i < argc)
	{
		new_node = create_node(argv[i], i);
		// create next node
		// add to end function new_node->next->prev = new_node;
		// set prev for cyclic
		new_node = new_node->next;
		// set next pointer to next node
		i++;
	}
	new_node->next = stack_a->head;
	// loops back around for circular linked list
	stack_a->tail = new_node; // tail is last node
	return (0);
}

void	populate_list(t_node *stack_a)
{
	t_node	*curr;

	curr = stack_a;
	while (curr != NULL)
	{
		// set values
		curr = curr->next;
	}
}
