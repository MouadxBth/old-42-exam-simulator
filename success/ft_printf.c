#include <unistd.h>
#include <stdarg.h>

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	length;
	
	if (!str)
		str = "(null)";
	length = -1;
	while (str[++length])
		ft_putchar(str[length]);
	return (length);
}

int	ft_putnbr(long long int number, int base)
{
	int	length;
	char	*hex = "0123456789abcdef";

	length = 0;
	if (number < 0)
	{
		number *= -1;
		length += ft_putchar('-');
	}
	if (number >= base)
		length += ft_putnbr(number / base, base);
	length += ft_putchar(hex[number % base]);
	return (length);
}

int	ft_printf(const char *str, ...)
{
	int	length;
	int	index;
	va_list	args;

	if (!str)
		return (0);
	length = 0;
	index = -1;
	va_start(args, str);
	while (str[++index])
	{
		if (str[index] == '%' && str[index + 1])
		{
			index++;
			if (str[index] == 's')
				length += ft_putstr(va_arg(args, char *));
			else if (str[index] == 'x')
				length += ft_putnbr(va_arg(args, unsigned int), 16);
			else if (str[index] == 'd')
				length += ft_putnbr(va_arg(args, int), 10);
		}
		else
			length += ft_putchar(str[index]);
	}
	return (va_end(args), length);
}
