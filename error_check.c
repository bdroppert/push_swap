/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdropper <bdropper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:26:14 by bdropper          #+#    #+#             */
/*   Updated: 2026/02/17 18:35:02 by bdropper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_overflow(char *str)
{
	long	n;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	n = 0;
	while (str[i])
	{
		n = n * 10 + (str[i] - '0');
		if (n * sign > 2147483647 || n * sign < -2147483648)
			return (1);
		i++;
	}
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int	number_check(char *str)
{
	int	i;

	if (!str || !*str)
		return (0);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (!is_overflow(str));
}

int	no_duplicates(t_node *stack)
{
	t_node	*curr;
	t_node	*check;

	curr = stack;
	while (curr)
	{
		check = curr->next;
		while (check)
		{
			if (curr->value == check->value)
				return (1);
			check = check->next;
		}
		curr = curr->next;
	}
	return (0);
}

int	error_check(int argc, char *argv[], t_node *stack)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!number_check(argv[i]))
		{
			write(1, "error\n", 6);
			return (0);
		}
		i++;
	}
	if (no_duplicates(stack))
	{
		write(1, "error\n", 6);
		return (0);
	}
	return (1);
}
