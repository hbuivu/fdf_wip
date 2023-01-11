//mlx functions:
int mlx_destroy_window ( void *mlx_ptr, void *win_ptr ); //destroy window
int mlx_clear_window ( void *mlx_ptr, void *win_ptr ); //clear window in black

unsigned int mlx_get_color_value ( void *mlx_ptr, int color ); //takes standard rgb color param and returns unsigned int value

void mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask, int (*f)(), void *param);
int mlx_loop_hook ( void *mlx_ptr, int (*funct_ptr)(), void *param );
int mlx_expose_hook ( void *win_ptr, int (*funct_ptr)(), void *param );
int mlx_mouse_hook ( void *win_ptr, int (*funct_ptr)(), void *param );
int mlx_key_hook ( void *win_ptr, int (*funct_ptr)(), void *param );

//funct_ptr -> pointer to function to be called when event occurs
//param ->stores 



int close(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int main(void)
{
	t_vars vars;

	mlx_hook(vars.win, 2, 0, close, &vars);
	mlx_loop(vars.mlx);
}