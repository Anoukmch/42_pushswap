/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 19:09:08 by amechain          #+#    #+#             */
/*   Updated: 2023/01/11 15:16:45 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc > 1)
	{
		stack_a = initialize(array_size(argv) * 2);
		array_fill(stack_a, argv);
		array_rev(stack_a);
		if (!(is_sorted_reverse(stack_a) || stack_a->top <= 0))
		{
			stack_b = initialize(stack_a->top + 1);
			sort(stack_a, stack_b);
			free_stack(stack_b);
		}
		free_stack(stack_a);
	}
	return (0);
}
