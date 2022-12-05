#include "./mlx_linux/mlx.h"
#include <stdio.h>
#include <math.h>

typedef struct  s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	mmp_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = y * data->line_length + x*(data->bits_per_pixel/8);
	dst = data->addr + (y*data->line_length + x*(data->bits_per_pixel/8));
	*(unsigned int*)dst = color;
}

int ft_round(float i)
{
	if (i - (int)(i) > 0.5)
		return ((int)(i) + 1);
	else
		return ((int)(i));
}

void	draw_line(t_data *data, int x1, int y1, int x2, int y2, int color)
{
	float	m;
	float   b;
	int 	max;
	int 	min;
	int 	p;

	m = (y2-y1) / (x2 - x1);
	b = y1 - (m * x1);

	if (x1 == x2)
	{
		if (y2 - y1 > 0)
		{
			max = y2;
			min = y1;
		}
		else
		{
			max = y1;
			min = y2;
		}
		while (min <= max)
		{
			mmp_put(data, x1, min, color);
			min++;
		}
		
	}
	if (m > 1) //traverse y and find x
	{
		if (y2 - y1 > 0)
		{
			max = y2;
			min = y1;
		}
		else
		{
			max = y1;
			min = y2;
		}
		while (min <= max)
		{
			p = ft_round((min - b) / m);
			mmp_put(data, p, min, color);
			min++;
		}
	}
	if (m <= 1)
	{
		if (x2 - x1 > 0)
		{
			max = x2;
			min = x1;
		}
		else
		{
			max = x1;
			min = x2;
		}
		while (min <= max)
		{
			p = ft_round((m * min) + b);
			mmp_put(data, min, p, color);
			min++;
		}
	}
}

int main(void)
{
    void    *mlx;
    void    *mlx_win;
    t_data  img;
    int     color = 0x00FFFFFF;

    mlx = mlx_init();
    if (mlx == NULL)
        return (0);
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello");
    img.img = mlx_new_image(mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    draw_line(&img, 0, 0, 400, 300, color);
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}
