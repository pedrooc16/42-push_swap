static int	num_check(const int *n, int len, t_stack *a)
{
	int	i;
	int	j;

	i = -1;
	a->neg = 0;
	while (++i < len)
	{
		j = i;
		while (++j < len)
		{
			if (n[i] == n[j])
				return (0);
			if (!a->neg && n[i] < 0)
				a->neg = 1;
		}
	}
	return (1);
}




int	main(int argc, char **argv)
{
	int		i;
	t_stack	a;
	t_stack	b;

	b.size = 0;
	a.arr = NULL;
	arg_check(argv + 1, argc - 1);
	a.arr = (int *)malloc_n_check(sizeof(int) * (argc), &a);
	get_nums(argv, &a, a.arr, argc);
	if (!num_check(a.arr, a.size, &a))
		display_err(&a);
	if (a_search(a.arr, a.size))
		return (0);
	i = a.size;
	while (i-- > 0)
		lstadd_front(&a, lstnew(a.arr[i], &a));
	push_swap(&a, &b);
	free(a.arr);
	lstclear(&a.head);
	return (0);
}