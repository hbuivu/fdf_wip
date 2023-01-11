#include "fdf.h"

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
		if (str[i] >= 'a' && str[i] <= 'f')
			str[i] -= 32;
		while (base[j] != str[i])
			j++;
		num = num * 16 + j;
		i++;
		j = 0;
	}
	return (num);
}


void	release_lines(char **split_line)
{
	int	i;

	i = 0;
	while (split_line[i])
	{
		free(split_line[i]);
		i++;
	}
	free(split_line[i]);
	free(split_line);
}



int	count_columns(char *s)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i] != ' ' && s[i] != '\n' && s[i] != '\0') &&
			(s[i + 1] == ' ' || s[i + 1] == '\n' || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

m_list	*init_master(char *line, int fd)
{
	m_list	*master;

	master = (m_list *)malloc(sizeof(m_list));
	if (!master)
	{
		while (line)
		{
			free(line);
			get_next_line(fd);
		}
		free(line);
		close(fd);
		//exit with error message;
		return (NULL);
	}
	master->max_col = count_columns(line);
	master->angle = 0.698132;
	master->cosa = cos(master->angle);
	master->sina = sin(master->angle);
	master->scale = 10;
	master->zscale = 2;
	master->xshift = 500;
	master->yshift = 300;
	return (master);
}

void	calculate_coordinates(p_list **plist, m_list *m)
{
	int	x;
	int	y;
	p_list *cur;

	cur = *plist;
	while (cur)
	{
		x = 0;
		y = cur->y;
		while (x < m->max_col)
		{
			cur->arr[x].newx = roundf(m->scale * (x - y) * m->cosa + m->xshift); //roundf?
			cur->arr[x].newy = roundf(m->scale * (x + y) * m->sina - 
                (cur->arr[x].z * m->zscale) + m->yshift);
			x++;
		}
		cur = cur->next;
	}
}
