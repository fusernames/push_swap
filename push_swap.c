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
		lst_free(a);
		ft_putstr("Error\n");
		return (0);
	}
	lst_print(a);
	if (lst_len(a) > 10)
		resolve(&a, &b);
	else
		short_resolve(&a, &b);
	while (b)
		pa(&a, &b);
	ps_goto(&a, 0, 'a');
	lst_print(a);
	lst_free(a);
	return (0);
}
