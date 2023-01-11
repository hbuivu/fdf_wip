/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:45:19 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/01/09 17:09:58 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = y * data->line_length + x * (data->bpp / 8);
	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

//create two or more images to hold frames temporarily
//then write to a temporary image, so you don't have to write to currently presented image


float	ft_max(float i, float j)
{
	if (i < 0)
		i  *= -1;
	if (j < 0)
		j *= -1;
	if (i < j)
		return (j);
	return (i);
}

void	draw_line(t_data *data, z_list p1, z_list p2, int color)
{
	float	dX;
	float	dY;
	float	delta;

	dX = p2.newx - p1.newx;
	dY = p2.newy - p1.newy;
	delta = ft_max(dX, dY);
	if (dX == 0) 
		dY = 1;
	else if (dY == 0)
		dX = 1;
	else
	{
		dX = dX / delta;
		dY = dY / delta;
	}
	while (delta > 0)
	{
		if (p1.newx >= 0 && p1.newx < WIDTH && p1.newy >= 0 && p1.newy < HEIGHT)
			ft_pixel_put(data, roundf(p1.newx), roundf(p1.newy), color);
		p1.newx += dX;
		p1.newy += dY;
		delta--;
	}	
	return ;
}

void	draw_img(t_data *data, p_list **plist, m_list *master)
{
	int		i;
	int		color;
	p_list	*p;

	i = 0;
	p = *plist;
	while (p)
	{
		while (i < master->max_col)
		{
			if (p->arr[i].color == -1)
				p->arr[i].color = WHITE;
			if (p->y == 0)
			{
				if (i == master->max_col - 1)
					return ;
				draw_line(data, p->arr[i], p->arr[i + 1], p->arr[i].color);
			}
			else
			{
				draw_line(data, p->arr[i], p->next->arr[i], p->arr[i].color);
				if (i != master->max_col - 1)
					draw_line(data, p->arr[i], p->arr[i + 1], p->arr[i].color);
			}
			i++;
		}
		i = 0;
		p = p->next;
	}
}

