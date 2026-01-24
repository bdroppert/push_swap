/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdropper <bdropper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:05:46 by bdropper          #+#    #+#             */
/*   Updated: 2026/01/23 23:25:20 by bdropper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

int					number_check(char *str);
int					error_check(int argc, char *argv[], t_node *stack);
t_node				*create_node(char *str);
void				init_lists(t_node **stack_a, int argc, char **argv);
void				print_list(t_node *stack_a);
int					no_duplicates(t_node *stack);

#endif