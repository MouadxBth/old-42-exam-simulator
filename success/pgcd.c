#include <stdio.h>
#include <stdlib.h>

void	pgcd(int a, int b)
{
	int index, res;

	index = 1;
	res = 0;
	while (index < a && index < b)
	{
		if (a % i == 0 && b % i == 0)
			res = i;
		i++;
	}
	printf("%d", res);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		pgcd(atoi(argv[1]), atoi(argv[2]));
	printf("\n");
	return (0);
}
