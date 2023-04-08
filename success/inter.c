#include <unistd.h>

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_contains(char *str, int c)
{
	int	index;

	if (!str)
		return (0);
	index = -1;
	while (str[++index])
		if (str[index] == c)
			return (1);
	return (0);
}

void	ft_inter(char *first, char *second)
{
	int	done[256];
	int	index;

	if (!first || !second)
	{
		ft_putchar('\n');
		return ;
	}
	index = -1;
	while (++index < 256)
		done[index] = 0;
	index = -1;
	while (first[++index])
	{
		if (ft_contains(second, first[index]) && !done[(int)first[index]])
			done[(int)first[index]] = ft_putchar(first[index]);
	}
	ft_putchar('\n');
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (ft_putchar('\n'));
	ft_inter(argv[1], argv[2]);
	return (0);
}
