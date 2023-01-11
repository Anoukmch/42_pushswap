/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 14:14:46 by amechain          #+#    #+#             */
/*   Updated: 2023/01/11 15:16:42 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	run(char *op, t_stack *a, t_stack *b)
{
	if (ft_strncmp(op, "pa", 3) == 0)
		push(b, a);
	else if (ft_strncmp(op, "pb", 3) == 0)
		push(a, b);
	else if (ft_strncmp(op, "sa", 3) == 0)
		swap(a);
	else if (ft_strncmp(op, "sb", 3) == 0)
		swap(b);
	else if (ft_strncmp(op, "ra", 3) == 0)
		rotate(a);
	else if (ft_strncmp(op, "rb", 3) == 0)
		rotate(b);
	else if (ft_strncmp(op, "rra", 4) == 0)
		reverse_rotate(a);
	else if (ft_strncmp(op, "rrb", 4) == 0)
		reverse_rotate(b);
	ft_putendl_fd(op, STDOUT_FILENO);
}

void	swap(t_stack *stack)
{
	int	swap;

	if (stack->top <= 0)
		return ;
	swap = stack->array[stack->top];
	stack->array[stack->top] = stack->array[stack->top - 1];
	stack->array[stack->top - 1] = swap;
}

void	push(t_stack *stack_src, t_stack *stack_dst)
{
	if (stack_src->top == -1)
		return ;
	stack_dst->array[++stack_dst->top] = stack_src->array[stack_src->top--];
}

void	rotate(t_stack *stack)
{
	int	i;
	int	buffer;

	i = stack->top;
	buffer = stack->array[stack->top];
	while (i)
	{
		stack->array[i] = stack->array[i - 1];
		i--;
	}
	stack->array[0] = buffer;
}

void	reverse_rotate(t_stack *stack)
{
	int	i;
	int	buffer;

	i = 0;
	buffer = stack->array[0];
	while (i < stack->top)
	{
		stack->array[i] = stack->array[i + 1];
		i++;
	}
	stack->array[stack->top] = buffer;
}
