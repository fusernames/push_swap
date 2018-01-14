#include "push_swap.h"

int	lst_len(t_pile *a)
{
	int	i;

	i = 0;
	while (a)
	{
		a = a->next;
		i++;
	}
	return (i);
}

void	print_lst(t_pile *a)
{
	while (a)
	{
		printf("%d - ", a->nb);
		a = a->next;
	}
	printf("\n");
}

t_pile	*get_last_elem(t_pile *a)
{
	while (a->next)
		a = a->next;
	return (a);
}
