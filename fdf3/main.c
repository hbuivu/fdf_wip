void	fdf(char *filename)
{
	mlist	*master_list;
	char	*line;
	int 	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		
	line = get_next_line(fd);
	master_list = init_mlist(line);
	// read_map(master_list, line, fd);
	//create zlist
	//add rows to master
	//create plist
	close(fd);
	draw_image(master, plist);
}

int main(int argv, char **argc)
{
	if (argv == 2)
	{
		fdf(argc[1]);
	}	
	return (0);
}