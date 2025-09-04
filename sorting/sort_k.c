/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_k.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evillca- < evillca-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:43:15 by evillca-          #+#    #+#             */
/*   Updated: 2025/07/09 14:28:47 by evillca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Devuelve el tamaño del stack
static int	stack_size(t_list *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

static int	get_max_position(t_list *stack)
{
	int	max;
	int	pos;
	int	i;

	max = stack->index;
	pos = 0;
	i = 0;
	while (stack)
	{
		if (stack->index > max)
		{
			max = stack->index;
			pos = i;
		}
		stack = stack->next;
		i++;
	}
	return (pos);
}

static void	bring_max_to_top(t_list **stack, char name)
{
	int	pos;
	int	size;

	pos = get_max_position(*stack);
	size = stack_size(*stack);
	if (pos <= size / 2)
		while ((*stack)->index != -1 && get_max_position(*stack) != 0)
			rotate(stack, name, 1);
	else
		while ((*stack)->index != -1 && get_max_position(*stack) != 0)
			reverse_rotate(stack, name, 1);
}

void	ksort_range_in_b(t_list **a, t_list **b, int size)
{
	int	chunk;
	int	i;

	if (size <= 100)
		chunk = 20;
	else
		chunk = 30;
	i = 0;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			push(a, b, 'b', 1);
			i++;
		}
		else if ((*a)->index <= i + chunk)
		{
			push(a, b, 'b', 1);
			rotate(b, 'b', 1);
			i++;
		}
		else
			rotate(a, 'a', 1);
	}
}

void	ksort_back_to_a(t_list **a, t_list **b)
{
	while (*b)
	{
		bring_max_to_top(b, 'b');
		push(b, a, 'a', 1);
	}
}
