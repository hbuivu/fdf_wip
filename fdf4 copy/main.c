/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:35:42 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/01/11 16:12:07 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// int esc_press(int key, v_list *vlist)
// {
// 	if (key == 53)
// 		mlx_destroy_window(vlist->mlx->mlx_ptr, data->mlx->mlx_win);
// 	return (0);
// }

int	close_win(t_vars *data)
{
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	//free everything
	exit (0);
}

int	key_transform(int key, v_list *vlist)
{

	if (key == 53)
	{
		mlx_destroy_window(vlist->mlx.mlx_ptr, vlist->mlx.mlx_win);
		//free everything
		exit (0);
	}
	if (key == 24)
		vlist->master->scale += 2;
	else if (key == 27)
		vlist->master->scale -= 2;
	mlx_clear_window(vlist->mlx.mlx_ptr, vlist->mlx.mlx_win);
	mlx_destroy_image(vlist->mlx.mlx_ptr, vlist->img.img);
	//check if need to free image pointer
	calculate_coordinates(vlist->plist, vlist->master);
	vlist->img.img = mlx_new_image(vlist->mlx.mlx_ptr, WIDTH, HEIGHT);
	vlist->img.addr = mlx_get_data_addr(vlist->img.img, &vlist->img.bpp, &					vlist->img.line_length, &vlist->img.endian);
	draw_img(&vlist->img, vlist->plist, vlist->master);
	mlx_put_image_to_window(vlist->mlx.mlx_ptr, vlist->mlx.mlx_win, vlist->img.img, 0, 0);
	return (0);
}

// int clear (v_list *vlist)
// {
// 	mlx_clear_window(vlist->mlx.mlx_ptr, vlist->mlx.mlx_win);
// 	calculate_coordinates(vlist->plist, vlist->master);
// 	draw_img(&vlist->img, vlist->plist, vlist->master);
// 	mlx_put_image_to_window(vlist->mlx.mlx_ptr, vlist->mlx.mlx_win, vlist->img.img, 0, 0);
// 	return (0);
// }

void	init_window(v_list *vlist)
{
	vlist->mlx.mlx_ptr = mlx_init();
	if (vlist->mlx.mlx_ptr == NULL)
	{
		//return error message;
		perror("ptr not malloc'd");
		return ;
	}
	vlist->mlx.mlx_win = mlx_new_window(vlist->mlx.mlx_ptr, WIDTH, HEIGHT, "Test");
	if (vlist->mlx.mlx_win == NULL)
	{
		perror("ptr not malloc'd");
		free(vlist->mlx.mlx_ptr);
		//return with error message
	}
	vlist->img.img = mlx_new_image(vlist->mlx.mlx_ptr, WIDTH, HEIGHT);
	vlist->img.addr = mlx_get_data_addr(vlist->img.img, &vlist->img.bpp, &					vlist->img.line_length, &vlist->img.endian);
	calculate_coordinates(vlist->plist, vlist->master);
	draw_img(&vlist->img, vlist->plist, vlist->master);
	mlx_put_image_to_window(vlist->mlx.mlx_ptr, vlist->mlx.mlx_win, vlist->img.img, 0, 0);

	//esc and x
	// mlx_hook(data.mlx_win, 2, 0, esc_press, &data);
	mlx_hook(vlist->mlx.mlx_win, 17, 0, close_win, &vlist->mlx);

	// //key hooks
	mlx_hook(vlist->mlx.mlx_win, 2, 0, key_transform, &vlist->mlx);
	//mlx_loop_hook(vlist->mlx.mlx_ptr, key_transform, &vlist->mlx);
	mlx_loop(vlist->mlx.mlx_ptr);
}

int	main(int argv, char **argc)
{
	int		fd;
	char	*line;
	v_list	vlist;
	m_list	*master;
	p_list	**plist;

	if (argv != 2)
	{
		perror("please submit only one filename");
		return (-1);
	}
	fd = open(argc[1], O_RDONLY);
	if (fd < 0)
	{
		perror("invalid file");
		exit(-1);
	}
	line = get_next_line(fd);
	vlist.master = init_master(line, fd);
	vlist.plist = read_map(fd, line, vlist.master);
	
	close(fd);
	init_window(&vlist);

	// master = init_master(line, fd);
	// plist = read_map(fd, line, master);
	//free linked list
	//free mlx pointers
	return (0);
}