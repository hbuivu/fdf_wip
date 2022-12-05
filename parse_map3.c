#include "./libft/libft.h"
#include <stdio.h>
#include <fcntl.h>

//remember to account for errors later!!!!

typedef struct p_list
{
	int *num_array;
	struct p_list *next;
} p_list;

int	count_col(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (str[i])
	{
		if (str[i] == ' ')
			count++;
		i++;
	}
	return (count);
}

int	*create_numarr(char *line, int col)
{
	char	**tmp;
	int		*num_array;

	tmp = ft_split(line, ' ');
	num_array = (int *)malloc(sizeof(int) * col);
	free(tmp[col]);
	while (col > 0)
	{
		num_array[col - 1] = ft_atoi(tmp[col - 1]);
		free(tmp[col-1]);
		col--;
	}
	free(tmp);
	return (num_array);
}

p_list	*create_list(char *first_line, int col, int fd)
{
	p_list	*head;
	p_list	*prev;
	p_list	*tmp;
	char	*line;

	tmp = (p_list *)malloc(sizeof(p_list));
	tmp->num_array = create_numarr(first_line, col);
	tmp->next = NULL;
	head = tmp;
	prev = head;
	line = get_next_line(fd);
	printf("%s\n", line);
	while (line != NULL)
	{
		tmp = (p_list *)malloc(sizeof(p_list));
		tmp->num_array = create_numarr(line, col);
		tmp->next = NULL;
		prev->next = tmp;
		prev = tmp;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return(head);
}

int main(void)
{
	int 	fd;
	char	*filename;
	char	*line;
	int		columns;
	p_list	*plist;

	filename = "./test_maps/basictest.fdf";
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	columns = count_col(line);
	plist = create_list(line, columns, fd);
}

// line = "0 0 1 2 3 4 5 6 7 8 9";
// int *arr = create_numarr(line, columns);
	// for (int i = 0; i < columns; i++)
	// 	printf("%i\n", arr[i]);
	// free(arr);

	// p_list	*tmp;
	// tmp = plist;
	// while (tmp)
	// {
	// 	printf("%i\n", (tmp->num_array)[10]);
	// 	tmp = tmp->next;
	// }

