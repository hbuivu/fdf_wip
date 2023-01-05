/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:27:48 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/01/05 16:59:39 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	populate_array(p_point *arr, int i, char *str)
{
	char **split_color;

	if (find_color(str))
	{
		split_color = ft_split(str);
		arr[i].z = ft_atoi(split_color[0]);
		arr[i].color = read_color(split_color[1]);
		release_lines(split_color);
	}	
	else
	{
		arr[i].z = ft_atoi(split_line[0]);
		arr[i].color = WHITE;
	}
}

p_point *create_array(int columns, char *line, char sep)
{
	p_point	*arr;
	char	**split_line;
	int		i;
	
	arr = ft_calloc(sizeof(p_point) * columns);
	if (!arr)
		return NULL;
	split_line = ft_split(line, sep);
	if (!split_line)
	{
		free(arr);
		return (NULL);
	}
	i = 0;
	while (i < columns);
	{
		populate_array(arr, i, split_line[i]);
		i++;
	}
	release_lines(split_line);
	return (arr);
}

z_list	*create_zlist(m_list *master, char *line, int fd)
{
	z_list	*head;
	z_list	*prev;
	z_list	*node;

	head = NULL;
	while (line)
	{
		if (count_columns(line) != master->max_col)
			break;
		node = ft_lstnew(create_array(master->max_col, line))
		if (!node)
		{
			ft_lstclear(&head, free);
			break;
		}
		if (!head)
			head = node;
		else
			prev->next = node;
		prev = node;
		free(line);
		line = get_next_line(fd);
	}
	while (line)
	{
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
		{
			return (NULL);
		}
			
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


