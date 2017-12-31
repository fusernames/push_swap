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
	//resolve(&a, &b);
	split(&a, &b, 0, lst_len(a) - 1);
	//test(&a, &b);
	//insertion_sort(&a, &b, 0, lst_len(b) - 1);
	print_lst(b);
	return (0);
}
