/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evillca- < evillca-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:43:40 by evillca-          #+#    #+#             */
/*   Updated: 2025/07/09 13:43:40 by evillca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"
#include "push_swap.h"

t_list	*create_node(int value)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

static void	append_node(t_list **stack, t_list *new)
{
	t_list	*tmp;

	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

static t_list	*parse_input(int argc, char **argv)
{
	t_list	*stack;
	int		i;
	long	val;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		if (!ft_is_number(argv[i]))
			print_error("Error");
		val = ft_atoi_long(argv[i]);
		if (val < -2147483648 || val > 2147483647)
			print_error("Error");
		if (has_duplicate(stack, (int)val))
			print_error("Error");
		append_node(&stack, create_node((int)val));
		i++;
	}
	return (stack);
}

t_list	*init_stack_with_index(int argc, char **argv)
{
	t_list	*stack;
	int		size;
	int		*arr;

	stack = parse_input(argc, argv);
	size = argc - 1;
	arr = list_to_array(stack);
	if (!arr)
		print_error("array allocation failed");
	insertion_sort(arr, size);
	indexer(stack, arr, size);
	free(arr);
	return (stack);
}
