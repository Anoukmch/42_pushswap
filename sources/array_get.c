/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:42:51 by amechain          #+#    #+#             */
/*   Updated: 2023/01/11 15:16:16 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	size_doublechar_array(char **sub_tab)
{
	int	sub_size;

	sub_size = 0;
	while (sub_tab[sub_size])
		sub_size++;
	return (sub_size);
}

int	array_size(char **argv)
{
	int		i;
	int		j;
	size_t	count;
	char	**sub_tab;
	int		sizedoublechar;

	i = 1;
	count = 0;
	while (argv[i])
	{
		sub_tab = ft_split(argv[i], ' ');
		j = 0;
		if (!sub_tab[j] || !sub_tab || check_digits(sub_tab) == 0
			|| check_integers(sub_tab) == 0)
			error();
		sizedoublechar = size_doublechar_array(sub_tab);
		count = count + sizedoublechar;
		free_array((void **)sub_tab, sizedoublechar);
		i++;
	}
	return (count);
}

void	array_fill(t_stack *stack, char **argv)
{
	int		i;
	int		j;
	char	**sub_tab;

	i = 1;
	while (argv[i])
	{
		sub_tab = ft_split(argv[i], ' ');
		j = 0;
		if (!sub_tab[j] || !sub_tab)
			error();
		while (sub_tab[j])
		{
			stack->array[++stack->top] = ft_atoi(sub_tab[j]);
			j++;
		}
		free_array((void **)sub_tab, size_doublechar_array(sub_tab));
		i++;
	}
	if (check_duplicates(stack) == 0)
		error();
}

void	array_rev(t_stack	*stack)
{
	int	i;
	int	swap;
	int	size;

	i = 0;
	size = stack->top + 1;
	while (i < (size / 2))
	{
		swap = stack->array[i];
		stack->array[i] = stack->array[size - 1 - i];
		stack->array[size - 1 - i] = swap;
		i++;
	}
}
