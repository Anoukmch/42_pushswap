/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:36:24 by amechain          #+#    #+#             */
/*   Updated: 2023/01/11 15:16:37 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_stack *stack)
{
	free(stack->array);
	free(stack);
}

void	free_array(void **array, int sub_size)
{
	int	i;

	i = 0;
	while (i < sub_size)
		free(array[i++]);
	free(array);
}
