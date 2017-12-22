#include "push_swap.h"

int	main(int ac, char **av)
{
	t_pile	*a;

	if (ac < 2)
		return (0);
	a = init_pile(ac, av);
	print_lst(a);
	resolve(a);
	/*
	while(b)
	{
		printf("%d -> ", b->nb);
		b = b->next;
	}
	printf("\n");*/
	return (0);
}
