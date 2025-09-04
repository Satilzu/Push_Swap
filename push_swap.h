/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evillca- < evillca-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:42:17 by evillca-          #+#    #+#             */
/*   Updated: 2025/07/09 13:42:17 by evillca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

/* stack */
typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}	t_list;

/* indexer*/
int		*list_to_array(t_list *list);
void	insertion_sort(int *array, int size);
void	indexer(t_list *stack, int *array, int size);

/* stack operations */
void	swap(t_list **stack, char name, int print);
void	push(t_list **from, t_list **to, char name, int print);
void	ss(t_list **a, t_list **b);
void	rotate(t_list **stack, char name, int print);
void	reverse_rotate(t_list **stack, char name, int print);
void	rr(t_list **a, t_list **b);
void	rrr(t_list **a, t_list **b);

/* parser */
t_list	*create_node(int value);
t_list	*init_stack_with_index(int argc, char **argv);

/*sorting*/
void	small_sort(t_list **stack);
void	medium_sort(t_list **a, t_list **b);

void	ksort_range_in_b(t_list **a, t_list **b, int size);
void	ksort_back_to_a(t_list **a, t_list **b);

/* utils */
void	print_error(const char *msg);
int		is_sorted(t_list *stack);
void	free_stack(t_list **stack);

#endif
