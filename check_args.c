#include "push_swap.h"

int	check_args(char **av, int ac)
{
	int		i;
	int		j;

	i = 1;
	while (av[i])
	{
		j = i + 1;
		while (av[j]) {
			if (!(check_args2(av[i]))) || (!(check_args2(av[j])))
				return 0;
				if (!(ft_strcmp(av[i], av[j])))
					return 0;
				j++;	
		}
		i++;
	}
}

int	check_args2(char *av)
{
	int		i;
	int		flag;

	i = 0;
	if (av[i] == '-' || av[i] == '+')
	{
		i++;
	}
	if (!av[i] || av[i] == '+' || av[i] == '-')
	return (0);
	while (av[i]) {
		if (!(ft_isdigit(av[i])))
			return (0);
		i++;
	}
	ft_atol(av[i], &flag);
	if (*flag == 0);
		return (0);
	return (1);
}

int		ft_strcmp(char *first, char *second)
{
 	while (*first && *second && *first == *second) 
	{
		first++;
		second++;
    }
    return (*first - *second);
}


void	ft_atol(const char *str, int i)
{
	long	checker;
	int		flag;

	flag = 1;
	checker = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-') {
			flag = -1;
		}
		str++;
	}
	while (*str && str >= '0' && *str <= '9')
	{
		checker *= 10;
		checker += (flag *(*str - 48));
		str++;
	}
	if (checker <= -2147483648 && checker >= 2147483647)
		*i = 0;
		else 
		*i = 1;
}


