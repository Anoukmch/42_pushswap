/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:57:28 by amechain          #+#    #+#             */
/*   Updated: 2023/01/11 15:17:16 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# include "libft/libft.h"

typedef struct s_stack
{
	int				top;
	unsigned int	size;
	int				*array;
}				t_stack;

t_stack			*initialize(unsigned int size);
int				size_doublechar_array(char **sub_tab);
int				array_size(char **argv);
void			array_fill(t_stack *stack, char **argv);
void			array_rev(t_stack	*stack);
void			error(void);
int				check_integers(char **sub_tab);
int				check_digits(char **sub_tab);
int				check_duplicates(t_stack *stack);
void			convert_binary(t_stack *a);
int				*convert_indexes(t_stack *a);
void			complex_algo(t_stack *a, t_stack *b);
void			free_stack(t_stack *stack);
void			free_array(void **array, int sub_size);
void			run(char *op, t_stack *a, t_stack *b);
void			swap(t_stack *stack);
void			push(t_stack *stack_src, t_stack *stack_dst);
void			rotate(t_stack *stack);
void			reverse_rotate(t_stack *stack);
void			sort_three(t_stack *a);
void			move_number_top_a(t_stack *a, int n);
void			push_smallest_a_to_b(t_stack *a, t_stack *b);
void			sort_four_five(t_stack *a, t_stack *b);
void			simple_algo(t_stack *a, t_stack *b);
void			sort(t_stack *a, t_stack *b);
int				is_sorted(t_stack *stack);
void			sort_array(int	*array, int size);
long long int	ft_atoilong(const char *str);
void			sort_complex(t_stack *a, t_stack *b);
int				is_sorted_reverse(t_stack *stack);

#endif
