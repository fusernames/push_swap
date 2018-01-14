#include "push_swap.h"

int	main(int ac, char **av)
{
	t_pile	*a;
	t_pile	*b;

	b = NULL;
	if (ac < 2)
		return (0);
	if ((a = parser(ac, av)) == NULL || check_duplicate(a))
	{
		ft_putstr("Error\n");
		return (0);
	}
	print_lst(a);
	resolve(&a, &b);
	while (b)
		pa(&a, &b);
	ps_goto(&a, 0, 'a');
	print_lst(a);
	return (0);
}
