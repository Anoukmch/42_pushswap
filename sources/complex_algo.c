/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 18:00:01 by amechain          #+#    #+#             */
/*   Updated: 2023/01/11 15:16:34 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*convert_indexes(t_stack *a)
{
	int	*copy;
	int	i;
	int	j;

	i = a->top;
	copy = malloc((a->top + 1) * sizeof(int));
	if (!copy)
		return (NULL);
	ft_memcpy(copy, a->array, sizeof(int) * (a->top + 1));
	sort_array(copy, (a->top + 1));
	while (i >= 0)
	{
		j = a->top;
		while (j >= 0)
		{
			if (a->array[i] == copy[j])
			{
				a->array[i] = j;
				break ;
			}
			j--;
		}
		i--;
	}
	return (copy);
}

void	sort_complex(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	temp = a->top;
	while (!is_sorted(a))
	{
		j = 0;
		while (j <= temp)
		{
			if (((a->array[a->top] >> i) & 1) == 0)
				run("ra", a, NULL);
			else
				run("pb", a, b);
			j++;
		}
		while (b->top >= 0)
			run("pa", a, b);
		i++;
	}
}

void	complex_algo(t_stack *a, t_stack *b)
{
	int	*copy;

	copy = convert_indexes(a);
	sort_complex(a, b);
	free(copy);
}
