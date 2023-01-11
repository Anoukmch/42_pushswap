/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:53:35 by amechain          #+#    #+#             */
/*   Updated: 2023/01/11 15:16:50 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort(t_stack *a, t_stack *b)
{
	if (a->top < 5)
		simple_algo(a, b);
	else
		complex_algo(a, b);
}

int	is_sorted_reverse(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->top)
	{
		if (stack->array[i + 1] > stack->array[i])
			return (0);
		i++;
	}
	return (1);
}

int	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->top)
	{
		if (stack->array[i + 1] < stack->array[i])
			return (0);
		i++;
	}
	return (1);
}

void	sort_array(int	*array, int size)
{
	int	c;
	int	a;

	c = 0;
	while (c + 1 < size)
	{
		if (array[c] < array[c + 1])
		{
			a = array[c];
			array[c] = array[c + 1];
			array[c + 1] = a;
			c = -1;
		}
		c++;
	}
}
