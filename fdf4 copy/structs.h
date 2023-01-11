#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct z_list
{
	int		z;
	int		color;
	float	newx;
	float	newy;
}	z_list;

typedef struct points_list
{
	int				y;
	z_list			*arr;
	struct points_list	*next;
}	p_list;

typedef struct master_list
{
	int		max_col;
	int		max_row;
	float	angle;
	float	cosa;
	float	sina;
	int		scale;
	int		zscale;
	int		xshift;
	int		yshift;
}	m_list;

typedef struct  s_data 
{
	void	*img;
	char	*addr;
	int		bpp; /*bits per pixel*/
	int		line_length;
	int		endian;
}	t_data;

typedef struct  s_vars 
{
	void	*mlx_ptr;
	void	*mlx_win;
}	t_vars;

typedef struct variables_list
{
	t_vars	mlx;
	t_data	img;
	m_list	*master;
	p_list	**plist;
}	v_list;


#endif