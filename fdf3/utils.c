#include "fdf.h"

int	count_columns(char *s)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != ' ' && (s[i + 1] == ' ' || s[i + 1] == '\n'))
			count++;
		i++;
	}
	return (count);
}

int	count_rows(zlist *list)
{
	int	count;

	count = 0;
	while (list)
	{
		count++;
		list = list->next;
	}
	return (count);
}

mlist	*init_mlist(char *str)
{
	int		columns;
	mlist	*master_list;

	columns = count_columns(str);
	master_list->max_col = columns;
	master_list->max_row = 0;
	master_list->scale = 10;
	master_list->xshift = 200;
	master_list->yshift = 200;
	master_list->zscale = scale/5;
	master_list->p_array = NULL;
	
}

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

int	find_color(char *str)
{
	while (*str)
	{
		if (*str == ',')
			return (1);
		str++;
	}
	return (0);
}

