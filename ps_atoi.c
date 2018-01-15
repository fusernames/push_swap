#include "push_swap.h"

int			ps_atoi(char *s, int *nb)
{
	int			is_negative;
	int			found;

	is_negative = 0;
	while (ft_isspace(*s))
		(s)++;
	if (*s == '+')
		(s)++;
	else if (*s == '-')
	{
		is_negative = 1;
		(s)++;
	}
	while (*s >= '0' && *s <= '9')
	{
		found = 1;
		*nb = (*nb * 10) + *s - '0';
		(s)++;
	}
	if (!found)
		return (1);
	*nb = is_negative ? -(*nb) : *nb;
	return (0);
}