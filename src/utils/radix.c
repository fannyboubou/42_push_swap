#include "../../inc/push_swap.h"

static int get_maxbits_lst(t_node_int *one_stack)
{
	t_node_int *current;
	int max;
	int max_b;

	current = one_stack;
	max = current->index;
	max_b = 0;

	while (current)
	{
		if (current->index > max)
			max = current->index;
		current = current->next;
	}
	while ((max >> max_b) != 0)
		max_b++;
	return (max_b);
}

void radix_sort(t_node_int **one_stack, t_node_int **another_stack)
{
	t_node_int *current;
	int	i;
	int	j;
	int	size;
	int	max_b;

	max_b = get_maxbits_lst(*one_stack);
	size = ft_lstsize(*one_stack);
	i = -1;
	while (++i < max_b)
	{
		j = -1;
		while (++j < size)
		{
			current = *one_stack;
			if (((current->index >> i) & 1) == 0)
				push_head(one_stack, another_stack);
			else
				rotate_one(one_stack);
		}
		while(ft_lstsize(*another_stack) != 0)
			push_head(another_stack, one_stack);
	}
}

