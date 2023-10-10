#include "./includes/push_swap.h"
#include "./libft/libft.h"


int    check_args(char **av, int i)
{
	int		j;

	printf("%s\n", av[0]);
	printf("%s\n", av[1]);
	if (!(check_args2(av[i])))
		return (0);
    while (av[i])
    {
        j = i + 1;
        while (av[j]) 
        {
            if (!(check_args2(av[j])))
              return (0);
                if (!(ft_strcmp(av[i], av[j])))
                  return (0);
                j++;    
        }
        i++;
    }
	return (1);
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
	if ( av[i] == '0' || av[i] == '+' || av[i] == '-')
	return (0);
	while (av[i]) 
	{
		if (!(ft_isdigit(av[i])))
			return (0);
		i++;
	}
	ft_atol(av, &flag);
	if (flag == 0)
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


void	ft_atol(const char *str, int * i)
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
	while (*str && *str >= '0' && *str <= '9')
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

int		count_args(char **av, int ac)
{
	char	**args;
	int		i;

	if (ac < 2)
		return (0);
	if (ac == 2) {
	args = ft_split(av[1], ' ');
	i = 0;
	if (args[1] == 0)
		return (0);
	}
	else 
	{
		args = av;
		i = 1;
	}
	if(!(check_args(args, i)))
		return (0);
	ft_free_array(args, ac);
	return (1);
}



