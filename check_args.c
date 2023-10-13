#include "./includes/push_swap.h"
#include "./libft/libft.h"

int    is_valid(char **av, int i)
{
	int		j;

	if (!(check_digits(av[i])))
		return (0);
    while (av[i])
    {
        j = i + 1;
        while (av[j]) 
        {
            if (!(check_digits(av[j])))
              return (0);
                if (!(ft_strcmp(av[i], av[j])))
                  return (0);
                j++;    
        }
        i++;
    }
	return (1);
}

int	check_digits(char *av)
{
	int		i;
	int		flag;

	i = 0;
	if (av[i] == '-' || av[i] == '+')
	{
		i++;
		if (av[i] == '0' || av[i] == '+' || av[i] == '-')
			return (0);
	}
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

int		check_args(char **av, int ac)
{
	char	**args;
	int		i;

	if (ac == 2) 
	{
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
	if(!(is_valid(args, i)))
		return (0);
	ft_free_array(args, ac);
	return (1);
}



