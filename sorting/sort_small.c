/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evillca- < evillca-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:43:20 by evillca-          #+#    #+#             */
/*   Updated: 2025/07/09 13:43:20 by evillca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_list **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->index;
	b = (*stack)->next->index;
	c = (*stack)->next->next->index;
	if (a > b && b < c && a < c)
		swap(stack, 'a', 1);
	else if (a > b && b > c)
	{
		swap(stack, 'a', 1);
		reverse_rotate(stack, 'a', 1);
	}
	else if (a > b && b < c && a > c)
		rotate(stack, 'a', 1);
	else if (a < b && b > c && a < c)
	{
		swap(stack, 'a', 1);
		rotate(stack, 'a', 1);
	}
	else if (a < b && b > c && a > c)
		reverse_rotate(stack, 'a', 1);
}

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

static int	find_min_index(t_list *stack)
{
	int	min;

	min = stack->index;
	while (stack)
	{
		if (stack->index < min)
			min = stack->index;
		stack = stack->next;
	}
	return (min);
}

static void	push_min_to_b(t_list **a, t_list **b)
{
	t_list	*tmp;
	int		min;
	int		pos;

	min = find_min_index(*a);
	tmp = *a;
	pos = 0;
	while (tmp && tmp->index != min)
	{
		pos++;
		tmp = tmp->next;
	}
	if (pos <= stack_size(*a) / 2)
		while ((*a)->index != min)
			rotate(a, 'a', 1);
	else
		while ((*a)->index != min)
			reverse_rotate(a, 'a', 1);
	push(a, b, 'b', 1);
}

void	medium_sort(t_list **a, t_list **b)
{
	int	total;
	int	pushes;

	total = stack_size(*a);
	pushes = total - 3;
	while (pushes--)
		push_min_to_b(a, b);
	small_sort(a);
	while (*b)
		push(b, a, 'a', 1);
}
