/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evillca- < evillca-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:42:24 by evillca-          #+#    #+#             */
/*   Updated: 2025/07/09 13:42:24 by evillca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack, char name, int print)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	if (print)
	{
		write(1, "s", 1);
		write(1, &name, 1);
		write(1, "\n", 1);
	}
}

void	push(t_list **from, t_list **to, char name, int print)
{
	t_list	*temp;

	if (!from || !*from)
		return ;
	temp = *from;
	*from = temp->next;
	temp->next = *to;
	*to = temp;
	if (print)
	{
		write(1, "p", 1);
		write(1, &name, 1);
		write(1, "\n", 1);
	}
}

void	ss(t_list **a, t_list **b)
{
	swap(a, 'a', 0);
	swap(b, 'b', 0);
	write(1, "ss\n", 3);
}
