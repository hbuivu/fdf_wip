/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 00:55:31 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/01/11 14:11:06 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_gnl(char *line, int fd, p_list **plist)
{
	if (!line)
		return ;
	ft_lstclear(plist, free);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}

void	fill_zarray(char *str, z_list *zlist, m_list *m, int x, int y)
{
	char **split_color;
	
	if (ft_strchr(str, ','))
	{
		split_color = ft_split(str, ',');
		if (!split_color)
		{
			free(zlist);
			return ;
		}
		zlist[x].z = ft_atoi(split_color[0]);
		zlist[x].color = read_color(split_color[1]);
		release_lines(split_color);
	}
	else
	{
		zlist[x].z = ft_atoi(str);
		zlist[x].color = -1;
	}
	// zlist[x].newx = roundf(m->scale * (x - y) * m->cosa + m->xshift); //do i need to round this?
	// zlist[x].newy = roundf(m->scale * (x + y) * m->sina - 
	// 	(zlist[x].z * m->zscale) + m->yshift);
}

z_list	*create_array(char *line, m_list *master, int y)
{
	z_list	*zlist;
	char	**split_list;
	char	**split_color;
	int		x;

	zlist = (z_list *)malloc(sizeof(z_list) * master->max_col);
	if (!zlist)
		return (NULL);
	split_list = ft_split(line, ' ');
	if (!split_list)
	{
		free(zlist);
		return(NULL);	
	}
	x = -1;
	while (++x < master->max_col)
		fill_zarray(split_list[x], zlist, master, x, y);
	release_lines(split_list);
	return (zlist);
}

p_list	*create_node(char *line, m_list *master, int y)
{
	p_list	*new_node;
	char	**split_line;

	new_node = (p_list *)malloc(sizeof(p_list));
	if (!new_node)
		return (NULL);
	new_node->arr = create_array(line, master, y);
	if (!new_node->arr)
	{
		free(new_node);
		return(NULL);
	}
	new_node->y = y;
	new_node->next = NULL;
	return (new_node);
}

p_list	**read_map(int fd, char *line, m_list *master)
{
	p_list	**plist;
	p_list	*temp;
	int		y;

	y = 0;
	plist = (p_list **)ft_calloc(1, sizeof(p_list*));
	if (!plist)
		return (NULL);
	while (line)
	{
		if (count_columns(line) != master->max_col)
			break ;
		temp = create_node(line, master, y);
		if (!temp)
			break;
		ft_lstadd_front(plist, temp);
		free(line);
		line = get_next_line(fd);
		y++;
	}
	clear_gnl(line, fd, plist);
	//free(line);
	return (plist);
}

