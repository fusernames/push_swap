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

void	lst_print(t_pile *a)
{
	while (a)
	{
		printf("%d - ", a->nb);
		a = a->next;
	}
	printf("\n");
}

void	lst_free(t_pile *a)
{
	t_pile	*cpy;
	t_pile	*tmp;

	cpy = NULL;
	if (a && a->previous)
		cpy = a->previous;
	while (cpy)
	{
		tmp = cpy->previous;
		free(cpy);
		cpy = tmp;
	}
	while (a)
	{
		tmp = a->next;
		free(a);
		a = tmp;
	}
}

t_pile	*lst_getlast(t_pile *a)
{
	while (a->next)
		a = a->next;
	return (a);
}
