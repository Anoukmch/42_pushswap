/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:53:21 by amechain          #+#    #+#             */
/*   Updated: 2023/01/11 15:16:47 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack *a)
{
	int	*arr;

	arr = a->array;
	if (arr[0] > arr[1] && arr[1] < arr[2] && arr[2] < arr[0])
		run("sa", a, NULL);
	else if (arr[0] < arr[1] && arr[1] < arr[2] && arr[2] > arr[0])
	{
		run("sa", a, NULL);
		run("rra", a, NULL);
	}
	else if (arr[0] > arr[1] && arr[1] < arr[2] && arr[2] > arr[0])
		run("ra", a, NULL);
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[2] < arr[0])
	{
		run("sa", a, NULL);
		run("ra", a, NULL);
	}
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[2] > arr[0])
		run("rra", a, NULL);
}

void	move_number_top_a(t_stack *a, int n)
{
	int	i;

	i = 0;
	if (n < (a->top / 2))
	{
		while (i++ <= n)
			run("rra", a, NULL);
	}
	else
	{
		while (n < a->top)
		{
			run("ra", a, NULL);
			n++;
		}
	}
}

void	push_smallest_a_to_b(t_stack *a, t_stack *b)
{
	int	i;
	int	n;
	int	j;

	i = 0;
	n = 0;
	j = i + 1;
	while (j <= a->top)
	{
		if (a->array[i] > a->array[j])
		{
			n = j;
			i++;
		}
		else
			j++;
	}
	if (n != a->top)
		move_number_top_a(a, n);
	run("pb", a, b);
}

void	sort_four_five(t_stack *a, t_stack *b)
{
	push_smallest_a_to_b(a, b);
	push_smallest_a_to_b(a, b);
	sort_three(a);
	run("pa", a, b);
	run("pa", a, b);
}

void	simple_algo(t_stack *a, t_stack *b)
{
	if (a->top == 1)
		run("sa", a, NULL);
	else if (a->top == 2)
		sort_three(a);
	else
		sort_four_five(a, b);
}
