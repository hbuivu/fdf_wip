#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "./libft/libft.h" 
# include "./mlx_linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <X11/keysym.h>

# define WHITE	0xFFFFFFF

typedef struct p_point
{
	int x;
	int y;
	int	z;
	int	color;
}	p_point;

typedef struct z_list
{
	o_point *array;
	struct z_list *next;
}	z_list;

typedef struct p_list
{
	float	x;
	float	y;
	int		color;
}	p_list;

typedef struct m_list
{
	int		max_col;
	int		max_row;
	float	angle;
	int		scale;
	int		xshift;
	int		yshift;
	int		zscale;
	plist	*p_array;
}	m_list;

typedef struct  s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	s_data;

#endif


