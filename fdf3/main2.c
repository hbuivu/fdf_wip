/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:06:26 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/01/03 15:35:10 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

//place exits at all mallocs and possible NULL returns
	//ft_split (if NULL, exit)
	//ft_calloc (if NULL, exit)
//if error, must free all previous mallocs
o_point	*create_o_array(char *line, int columns)
{
	char	**split_line;
	char	**split_color;
	o_point	*arr;
	int		i;

	split_line = ft_split(line, ' ');
	arr = (o_point *)ft_calloc(sizeof(o_point) * columns);
	i = -1;
	while (++i < columns)
	{
		if (find_color(split_line[i]))
		{
			split_color = ft_split(split_line[i], ',');
			arr[i].z = ft_atoi(split_color[0]);
			arr[i].color = read_color(split_color[1]);
			release_lines(split_color);
		}
		else
		{
			arr[i].z = ft_atoi(split_line[i]);
			arr[i].color = WHITE;
		}
	}
	release_lines(split_line);
	return (arr);
}

// int main(int argv, char **argc)
// {
// 	int fd = open(argc[1], O_RDONLY);
// 	// if (fd < 0)
// 	// 	//perror("invalid file");
// 	// 	printf("%s\n", strerror(errno));
// 	return (0);
// }

int main(void)
{
	int i = -1;
	int j = 10;
	char *str = "acdedfghadfklfadfad";
	while (++i < j)
	{
		printf("%c: ", str[i]);
		printf("%i\n", i);
	}
}
