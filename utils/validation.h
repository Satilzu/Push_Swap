/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evillca- < evillca-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:42:08 by evillca-          #+#    #+#             */
/*   Updated: 2025/07/09 13:42:08 by evillca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_H
# define VALIDATION_H

# include "push_swap.h"

int		ft_is_number(const char *s);
int		has_duplicate(t_list *stack, int value);
long	ft_atoi_long(const char *str);

#endif
