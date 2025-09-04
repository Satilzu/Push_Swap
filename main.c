/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evillca- < evillca-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:40:12 by evillca-          #+#    #+#             */
/*   Updated: 2025/07/09 13:40:12 by evillca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	dispatch_sort(t_list **a, t_list **b, int size)
{
	if (size == 2)
	{
		if (!is_sorted(*a))
			swap(a, 'a', 1);
	}
	else if (size <= 3)
		small_sort(a);
	else if (size <= 5)
		medium_sort(a, b);
	else
	{
		ksort_range_in_b(a, b, size);
		ksort_back_to_a(a, b);
	}
}

int	main(int argc, char **argv)
{
	int		size;
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return (0);
	size = argc - 1;
	stack_a = init_stack_with_index(argc, argv);
	stack_b = NULL;
	if (!is_sorted(stack_a))
		dispatch_sort(&stack_a, &stack_b, size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
