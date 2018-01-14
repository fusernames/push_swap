#include "push_swap.h"

int		check_characters(char **av, int ac)
{
	int	i;
	int	j;

	while (j < ac)
	{
		while (av[j][i])
		{
			if (!ft_isdigit(av[j][i]) && !ft_isspace(av[j][i]))
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

int		check_duplicate(t_pile *a)
{
	t_pile	*cpy;

	while (a)
	{
		cpy = a->next;
		while (cpy)
		{
			if (cpy->nb == a->nb)
				return (1);
			cpy = cpy->next;
		}
		a = a->next;
	}
	return (0);
}
