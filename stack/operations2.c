/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evillca- < evillca-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:42:30 by evillca-          #+#    #+#             */
/*   Updated: 2025/07/09 14:04:17 by evillca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack, char name, int print)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
	if (print)
	{
		write(1, "r", 1);
		write(1, &name, 1);
		write(1, "\n", 1);
	}
}

void	reverse_rotate(t_list **stack, char name, int print)
{
	t_list	*prev;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
	if (print)
	{
		write(1, "rr", 2);
		write(1, &name, 1);
		write(1, "\n", 1);
	}
}

void	rr(t_list **a, t_list **b)
{
	rotate(a, 'a', 0);
	rotate(b, 'b', 0);
	write(1, "rr\n", 3);
}

void	rrr(t_list **a, t_list **b)
{
	reverse_rotate(a, 'a', 0);
	reverse_rotate(b, 'b', 0);
	write(1, "rrr\n", 4);
}
