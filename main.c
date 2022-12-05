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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
    int     offset;

    offset = y * data->line_length + x * (data->bits_per_pixel / 8);
    //printf("offset: %i\n", offset);
    //printf("bits_per_pixel: %i\n", data->bits_per_pixel);
    //printf("line_length: %i\n", data->line_length);
    //printf("%p\n", data->addr);
    //this is the "new address" of the pixel. 
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    //printf("%p\n", dst);
    //this is color located at that address
	*(unsigned int*)dst = color;
}

void    draw_line(t_data *data, int x1, int y1, int x2, int y2, int color)
{
    //y = mx + b
    int slope;
    int b;
    int i;
    int max;
    int j;

    slope = (y1 - y2) / (x1 - x2);
    b = y1 - (slope * x1);
    //need to check if x1 > x2, for now assume x1 < x2
    //also this doesn't draw a vertical line
    if (m <= 1)
    {
         if (x1 > x2)
            i = x2;
        else 
            i = x1;
        while (i <= x2)
        {
            j = (slope * i) + b;
            my_mlx_pixel_put(data, i, j, color);
            i++;
        }
    }
    else if (m > 1)
    
       
}

void    draw_circle(t_data *data, int r, int x, int y, int color)
{
    static const double PI = 3.1415926535;
    double i, angle, x1, y1;
    for(i = 0; i < 360; i += 0.1)
    {
        angle = i;
        x1 = r * cos(angle * PI / 180);
        y1 = r * sin(angle * PI / 180);
        my_mlx_pixel_put(data, x1 + x, y1 + y, 0x00FF0000);
    }
}

//void    draw_rectangle()

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
    // my_mlx_pixel_put(&img, 0, 0, 0x00FF0000);
    // my_mlx_pixel_put(&img, 1, 0, 0x00FF0000);
    // my_mlx_pixel_put(&img, 5, 0, 0x00FF0000);
    // my_mlx_pixel_put(&img, 10, 0, 0xFFFFFF);
    draw_line(&img, 0, 0, 5, 100, color);
    //draw_circle(&img, 100, 100, 100, color);
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}

// int main(void)
// {
//     void    *mlx;
//     void    *mlx_win;
//     int color = 16777215;

//     mlx = mlx_init();
//     mlx_win = mlx_new_window(mlx, 500, 700, "Hello world!");
//     //mlx_pixel_put ( void *mlx_ptr, void *win_ptr, int x, int y, int color );
//     mlx_loop(mlx);
// }