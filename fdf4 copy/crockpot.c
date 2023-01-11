	/*PRINT RESULTS*/
	for (int i = 0; i < master->max_col; i++)
		printf("%i ", zlist[i].z);
	printf("\n");
	for (int j = 0; j < master->max_col; j++)
		printf("%i ", zlist[j].color);
	printf("\n");
	for (int k = 0; k < master->max_col; k++)
		printf("%f ", zlist[k].newx);
	printf("\n");
	for (int l = 0; l < master->max_col; l++)
		printf("%f ", zlist[l].newy);
	printf("\n");
	/*DELETE LATER*/


/*PRINT ZLIST*/
	printf("****************ZLIST***************\n");
	p_list *temp = *plist;
	while (temp)
	{
		for (int i = 0; i < master->max_col; i++)
			printf("%i ", temp->arr[i].z);
		printf("\n");
		temp = temp->next;
	}
	
	/*PRINT COLOR LIST*/
	printf("**********COLOR LIST********************\n");
	temp = *plist;
	while (temp)
	{
		for (int i = 0; i < master->max_col; i++)
			printf("%i ", temp->arr[i].color);
		printf("\n");
		temp = temp->next;
	}
	/*PRINT NEWX, NEWY*/
		printf("**********NEW COORDINATES****************\n");
	temp = *plist;
	while (temp)
	{
		for (int i = 0; i < master->max_col; i++)
			printf("(%f, %f)", temp->arr[i].newx, temp->arr[i].newy);
		printf("\n");
		temp = temp->next;
	}
	/*DELETE LATER*/



int ft_round(float i)
{
	if (i - (int)(i) > 0.5)
		return ((int)(i) + 1);
	else
		return ((int)(i));
}

//valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes
//also added -g in gcc

int ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\0')
		return (1);
	return (0);
}

// void	init_window(p_list **plist, m_list *master)
// {
// 	t_vars	data;
// 	t_data	img;
	
// 	data.mlx_ptr = mlx_init();
// 	if (data.mlx_ptr == NULL)
// 	{
// 		//return error message;
// 		perror("ptr not malloc'd");
// 		return ;
// 	}
// 	data.mlx_win = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "Test");
// 	if (data.mlx_win == NULL)
// 	{
// 		perror("ptr not malloc'd");
// 		free(data.mlx_ptr);
// 		//return with error message
// 	}
// 	data.img.img = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);
// 	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bpp, &data.img.line_length, &data.img.endian);
// 	draw_img(&data.img, plist, master);
// 	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.img.img, 0, 0);

// 	//esc and x
// 	// mlx_hook(data.mlx_win, 2, 0, esc_press, &data);
// 	// mlx_hook(data.mlx_win, 17, 0, close_win, &data);

// 	// //key hooks
// 	// mlx_hook(data.mlx_win, 2, 0, key_transform, &data)
// 	mlx_loop(data.mlx_ptr);
// }
