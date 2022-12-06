#include "./mlx/mlx.h"
#include <stdio.h>
#include <math.h>
#include "draw_line.c"

//draw line between points
//connect to the right and down
	//at the last point, do not connect to the right
//if last row
	//do not connect down

void draw_tile(t_data *img, int x, int y, int twidth, int theight, int color)
{
	int tw;
	int th;
	int half_tw;
	int half_th;

	half_tw = (twidth/2) + ((x - y) * (twidth/2));
	half_th = (theight/2) + ((x + y) * (theight/2));
	tw = twidth + ((x - y) * (twidth/2));
	th = theight + ((x + y) * (theight/2));
	

	draw_line(img, half_tw, 0, tw, half_th, color);
	draw_line(img, tw, half_th, half_tw, th, color);
	draw_line(img, half_tw, th, 0, half_th, color);
	draw_line(img, 0, half_th, half_tw, 0, color);
}

int main(void)
{
    void    *mlx;
    void    *mlx_win;
    t_data  img;
    int     color = 0x00FFFFFF;
	int		tw = 100;
	int		th = 50;

    mlx = mlx_init();
    if (mlx == NULL)
        return (0);
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello");
    img.img = mlx_new_image(mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// draw_tile(&img, 0, 0, tw, th, color);
	draw_tile(&img, 1, 0, tw, th, color);
	// draw_tile(&img, 0, 1, tw, th, color);
	// draw_tile(&img, 1, 1, tw, th, color);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 200, 200);
    mlx_loop(mlx);
}