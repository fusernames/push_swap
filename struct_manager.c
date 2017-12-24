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

t_pile 	*init_pile(int ac, char **av)
{
	t_pile	*a;
	t_pile	*tmp;
	int	i;

	a = NULL;
	i = ac - 1;
	while(i > 0)
	{
		tmp = a;
		a = malloc(sizeof(t_pile));
		a->nb = atoi(av[i]);
		a->index = atoi(av[i--]);
		a->next = NULL;
		a->previous = NULL;
		if (tmp)
		{
			a->next = tmp;
			tmp->previous = a;
		}
	}
	return (a);
}
