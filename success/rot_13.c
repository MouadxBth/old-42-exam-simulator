#include <unistd.h>

int	ft_islow(int c)
{
	return (c >= 'a' && c <= 'z');
}

int	ft_isupp(int c)
{
	return (c >= 'A' && c <= 'Z');
}

int	ft_isalpha(int c)
{
	return (ft_islow(c) || ft_isupp(c));
}

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	rot_13(char *str)
{
	int	index;
	int	c;

	index = 0;
	while (str[index])
	{
		c = str[index];
		if (ft_isupp(c))
		{
			if (c <= 'M')
				ft_putchar(c + 13);
			else
				ft_putchar(c - 13);
		}
		else if (ft_islow(c))
		{
			if (c <= 'm')
				ft_putchar(c + 13);
			else
				ft_putchar(c - 13);
		}
		else
			ft_putchar(c);
		index++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		rot_13(argv[1]);
	}
	ft_putchar('\n');
	return (0);
}
