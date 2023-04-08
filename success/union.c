#include <unistd.h>

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

void	ft_union(char *first, char *second)
{
	int	done[256];
	int	index;

	index = -1;
	while (++index < 256)
		done[index] = 0;
	while (*first)
	{
		if (!done[(int)*first])
			done[(int)*first] = ft_putchar(*first);
		first++;
	}
	while (*second)
	{
		if (!done[(int)*second])
			done[(int)*second] = ft_putchar(*second);
		second++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (ft_putchar('\n'), 0);
	ft_union(argv[1], argv[2]);
	ft_putchar('\n');
	return (0);
}
