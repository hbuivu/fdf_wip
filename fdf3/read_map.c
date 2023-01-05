#include "fdf.h"

o_point	*create_o_array(char *line, int columns)
{
	char	**split_line;
	char	**split_color;
	o_point	*arr;
	int		i;

	split_line = ft_split(line, ' ');
	arr = (o_point *)malloc(sizeof(o_point) * columns);
	i = 0;
	while (i < columns)
	{
		if (find_color(split_line[i]))
		{
			split_color = ft_split(split_line[i]);
			arr[i].z = ft_atoi(split_color[0]);
			arr[i].color = read_color(split_color[1]);
			release_lines(split_color);
			//can this be recursive? no :(
		}
		else
		{
			arr[i].z = ft_atoi(split_line[i]);
			arr[i].color = WHITE;
		}
		i++;
	}
	release_lines(split_line);
	return (arr);
}

z_list	*create_zlist(int fd, char *line, m_list mlist)
{
	z_list	*head;
	z_list	*prev;
	z_list	*temp;

	head = NULL;
	while (line)
	{
		temp = (z_list*)malloc(sizeof(z_list));
		temp->array = create_o_array(line, master_list->max_col);
		temp->next = NULL;
		if (!head)
			head = temp;
		else
			prev->next = temp;
		prev = temp;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (head);
}

p_list	**create_matrix(int columns, int rows)
{
	p_list	**plist;
	int 	r;

	r = 0;
	plist = (p_list **)malloc(sizeof(p_list *) * rows);
	if (!plist)
		return (NULL);
	while(r < rows)
	{
		plist[r] = (p_list *)malloc(sizeof(p_list) * columns);
		if (!plist[r])
			return (NULL);
		r++;
	}
	return (plist);
}

p_list	**create_plist(z_list *zlist, m_list *mlist)
{
	p_list	**plist;
	int 	r;
	int		c;
	int		z;

	plist = create_matrix(columns, rows);
	if (plist == NULL)
		return (NULL);
	r = 0;
	c = 0;
	while (zlist)
	{
		while (c < columns)
		{
			z = zlist->array[c].z;
			plist[r][c].x = ft_round(mlist->scale * (c - r) * cos(mlist->angle) + mlist->xshift);
			plist[r][c].y = ft_round(mlist->scale * (c + r) * sin(mlist->angle) - (mlist->zscale * z) + mlist->yshift);
			c++;
		}
		zlist = zlist->next;
		c = 0;
		r++;
	}
	return (plist);
}

void	read_map(m_list *mlist, char *line, int fd)
{
	z_list	*zlist;

	zlist = create_zlist(line, fd, master_list);
	
	master_list->max_row = count_rows(zlist);
	master_list->p_array = create_plist(zlist, master_list)
	free_list(z_list);
}