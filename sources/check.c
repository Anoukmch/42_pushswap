/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:50:26 by amechain          #+#    #+#             */
/*   Updated: 2023/01/11 15:16:31 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

int	check_integers(char **sub_tab)
{
	long long int	test;
	int				i;

	test = 0;
	i = 0;
	if (sub_tab[i] == NULL || !sub_tab)
		return (0);
	while (sub_tab[i])
	{
		test = ft_atoilong(sub_tab[i]);
		if (test < -2147483648 || test > 2147483647)
			return (0);
		i++;
	}
	return (1);
}

int	check_digits(char **sub_tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (sub_tab[i] == NULL || !sub_tab)
		return (0);
	while (sub_tab[i])
	{
		j = 0;
		if (sub_tab[i][j] == '-' || sub_tab[i][j] == '+')
		{
			if (!(sub_tab[i][j + 1]))
				return (0);
			j++;
		}
		while (sub_tab[i][j])
		{
			if (!(sub_tab[i][j] >= '0' && sub_tab[i][j] <= '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_duplicates(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->top)
	{
		j = i + 1;
		while (j < (stack->top + 1))
		{
			if (stack->array[i] == stack->array[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
