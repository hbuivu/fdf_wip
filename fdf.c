#include "./libft/libft.h"
#include <stdio.h>
#include <fcntl.h>

typedef struct point_struct
{
	int	x;
	int y;
	int z;
}	p_struct;

int main(void)
{
	int fd;
	char *str;
	char ** col;
	int columns;
	int rows;
	
	fd = open("./test_maps/basictest.fdf", O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		return (-1);
	}
	str = get_next_line(fd);
	//count columns
	if (str != NULL)
	{
		col = ft_split(str, ' ');
	}
		
	columns = 0;
	while (col[columns] != NULL)
		columns++;
	//count rows
	rows = 0;
	while (str != NULL)
	{
		rows++;
		free(str);
		str = get_next_line(fd);
	}	
	free(str);
	printf("%i\n", rows);
	printf("%i\n", columns);
	close (fd);
	

}