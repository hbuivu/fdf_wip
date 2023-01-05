#include <stdio.h>
int	read_color(char *str)
{
	int		i;
	int		j;
	int		num;
	char	*base;

	i = 2;
	j = 0;
	num = 0;
	base = "0123456789ABCDEF";
	while (str[i])
	{
		while (base[j] != str[i])
			j++;
		num = num * 16 + j;
		i++;
		j = 0;
	}
	return (num);
}
