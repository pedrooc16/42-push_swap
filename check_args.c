//#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_atol(const char *str, int * i);
int    check_args(char **av, int ac);
int	check_args2(char *av);
int		ft_strcmp(char *first, char *second);
void	ft_atol(const char *str, int * i);
char	**ft_split(char const *s, char c);
int		count_args(char **av, int ac); 
int	ft_isdigit(int c);

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int    word_count(char const *s, char c) 
{
    int i;
    int counter;
    int words;
    
    counter = 0; 
    i = 0;
    while(s[i])
    {
      words = 0;
      while (s[i] == c && s[i] != '\0')
      i++;
       while (s[i] != c && s[i] != '\0'){
        i++;
        words = 1;
       }
        if (words == 1)
        counter++;
    }
    return(counter);
}

//descobrir o tamanho para alocar ao array[i]
static int	get_size(char const *s, char c, int counter)
{
	int	size;

	size = 0;
	while (s[counter] == c && s[counter] != '\0')
		counter++;
	while (s[counter] != c && s[counter] != '\0')
	{
		counter++;
		size++;
	}
	return (size);
}

static char	**make_split(char **array, char c, char const *s)
{
	int	size;
	int	counter;    //para percorrer a string
	int	index;
	int	seccounter;

	counter = 0;
	index = 0;
	while (s[counter] != '\0')
	{
		seccounter = 0;
		while (s[counter] == c && s[counter] != '\0')
			counter++;
		size = get_size(s, c, counter);
		array[index] = (char *) malloc ((size + 1) * sizeof(char));
		if (!array[index])
			return (NULL);
		while (s[counter] != c && s[counter] != '\0')
			array[index][seccounter++] = s[counter++];
		array[index][seccounter] = '\0';
		index++;
	}
	array[index] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**array;

	if (s == NULL)
		return (NULL);
	words = word_count(s, c);
	array = (char **) malloc ((words + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	array = make_split(array, c, s);
	return (array);
}

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


int main(int ac, char **av)
{
	if (!(count_args(av, ac))){
		write(1, "error", 4);
			return 0;
		}
	//printf("successful");
	write(1, "successful", 11);
	return 1;
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
	return (1);
}


