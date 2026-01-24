/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdropper <bdropper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:26:14 by bdropper          #+#    #+#             */
/*   Updated: 2026/01/24 05:17:44 by bdropper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

#define NO 1
#define ALL_GOOD 0

int	main(int argc, char **argv)
{
	t_node	*head_a;
	t_node	*head_b;

	/*these are not stacks themselves they are pointers tothe first node of two linked lists*/
	head_a = NULL;
	head_b = NULL;
	/*we set to null to make sure there is no garbage memory therefor the stacks are now empty*/
	init_lists(&head_a, argc, argv);
	if (!error_check(argc, argv, head_a))
		return (1);
	while (head_a != NULL)
	{
		printf("%d\n", head_a->value);
		head_a = head_a->next;
	}
	// sort
	// free
	return (0);
}

t_node	*create_node(char *str)
{
	t_node	*new_node;

	new_node = calloc(1, sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = atoi(str);
	new_node->next = NULL;
	return (new_node);
}

void	init_lists(t_node **stack_a, int argc, char **argv)
{
	int	i;
	t_node *curr;

	i = 1;

	*stack_a = create_node(argv[i++]);
	if (!*stack_a)
		return ;
	
	curr = *stack_a;
	while (i < argc)
	{
		curr->next = create_node(argv[i]);
		if (!curr->next)
			return ;
		// create next node
		curr = curr->next;
		// set next pointer to next node
		i++;
	}
	curr->next = NULL;
}
dfgd

// returns the index of the given node
// the given node has to be from the given stack
// if you do not understand what it does
// then fuck your chungus life i guess ¯\_(ツ)_/¯
// size_t	node_index(t_stacks *stack, t_node *node)
// {
// 	size_t	i;
// 	t_node	*iter;

// 	i = 0;
// 	iter = stack;
// 	while (iter && iter != node)
// 	{
// 		i++;
// 		iter = iter->next;
// 	}
// 	return (i);
// }
