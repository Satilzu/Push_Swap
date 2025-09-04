/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evillca- < evillca-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:43:11 by evillca-          #+#    #+#             */
/*   Updated: 2025/07/09 13:43:11 by evillca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*list_to_array(t_list *list)
{
	int		size;
	int		i;
	int		*array;
	t_list	*tmp;

	tmp = list;
	size = 0;
	i = 0;
	while (tmp && ++size)
		tmp = tmp->next;
	array = malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	tmp = list;
	while (tmp)
	{
		array[i++] = tmp->value;
		tmp = tmp->next;
	}
	return (array);
}

void	insertion_sort(int *array, int size)
{
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < size)
	{
		key = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > key)
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = key;
		i++;
	}
}

void	indexer(t_list *stack, int *array, int size)
{
	int	i;

	while (stack)
	{
		i = 0;
		while (i < size)
		{
			if (stack->value == array[i])
			{
				stack->index = i;
				break ;
			}
			i++;
		}
		stack = stack->next;
	}
}
