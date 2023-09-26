int	check_args(char **av, int ac)
{
	int		i;
	int		j;

	i = 1;
	while (av[i])
	{
		j = i + 1;
		while (av[j]) {
			if (check_args2(av[i]) == 0 && check_args2([av[j]]) == 0)
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
	if (!(ft_atol(av[i])))
		return (0);
	return (1);
}

int		ft_strcmp(char *first, char *second)
{
 while (*first && *second && *first == *second) {
        first++;
        second++;
    }
    return (*str1 - *str2);
}




