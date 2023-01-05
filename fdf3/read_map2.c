/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:27:48 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/01/05 16:47:31 by hbui-vu          ###   ########.fr       */
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
	arr[i].x = i;
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
	z_list *node;
	z_list *head;
	int		j;

	j = 0;
	while (line)
	{
		if (count_columns(line) != master->max_col)
			break;
		node = ft_lstnew(create_array(master->max_col, line, j))
		if (!node)
		{
			ft_lstclear(&head, free);
			break;
		}
		ft_lstadd_front(&head, node);
		free(line);
		line = get_next_line(fd);
		j++;
	}
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (head);
}

