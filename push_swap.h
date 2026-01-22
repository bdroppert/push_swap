/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdropper <bdropper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:05:46 by bdropper          #+#    #+#             */
/*   Updated: 2026/01/21 18:28:50 by bdropper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP
# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_reference
{
	struct s_node	*head;
	struct s_node	*tail;
} t_reference;

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*head;
	struct s_node	*tail;
}					t_node;

int					number_check(char *str);
int					error_check(int argc, char **argv);
t_node	*create_node(char *str, int i);
int	init_lists(t_node *stack_a, int argc, char **argv);
void	populate_list(t_node *stack_a);

#endif