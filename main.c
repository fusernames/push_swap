#include "push_swap.h"

int	main(int ac, char **av)
{
	t_pile	*a;
	t_pile	*b;

	b = NULL;
	if (ac < 2)
		return (0);
	a = init_pile(ac, av);
	print_lst(a);
	quick_sort(&a, &b, 0, lst_len(a) - 1);
	/*
	while(b)
	{
		printf("%d -> ", b->nb);
		b = b->next;
	}
	printf("\n");*/
	go_to(&a, 0, 'a');
	print_lst(a);
	return (0);
}
