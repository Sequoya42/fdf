/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exemple.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 12:13:16 by rbaum             #+#    #+#             */
/*   Updated: 2015/01/27 18:40:33 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void line(int x0, int y0, int x1, int y1) {
 
	int dx = abs(x1-x0);
	int sx = x0<x1 ? 1 : -1;
	int dy = abs(y1-y0);
	int sy = y0<y1 ? 1 : -1; 
	int err = (dx>dy ? dx : -dy)/2;
	int e2;
	while (x0==x1 && y0==y1)
	{
		setPixel(x0,y0);
		e2 = err;
		if (e2 >-dx) 
		{ 
			err -= dy;
			x0 += sx;
		}
		if (e2 < dy)
		{ 
			err += dx; 
			y0 += sy;
		}
	}
}


/**********************************************/
void ligne(int xi,int yi,int xf,int yf) 
{
	int dx,dy,i,xinc,yinc,cumul,x,y ;

	x = xi;
	y = yi;
	dx = abs(xf - xi);
	dy = abs(yf - yi);
	xinc = (dx < 0) ? -1 : 1;
	yinc = (dy < 0) ? -1 : 1;
	allume_pixel(x, y);
	if (dx > dy) 
	{
		cumul = dx / 2;
		i = 0;
		while ( ++i <= dx)
		{
			x += xinc;
			cumul += dy;
			if ( cumul >= dx) 
			{
				cumul -= dx;
				allume_pixel(x, y); 
			}
		}
	}
	else 
	{
		cumul = dy / 2;
		i = 1;
		while (i <= dy)
		{
			y += yinc;
			cumul += dx;
			if (cumul >= dy) 
			{
				cumul -= dy;
				x += xinc; 
			}
			allume_pixel(x, y);
			i++;
		}
	}
}

/************************************************/
y = a x + b avec a =   et b = yi - a xi


void ligne(int xi,int yi,int xf,int yf) 
{
	int x,y;
	double a,b;

	a = (double) (yf-yi)/(xf-xi) ;
	b = yi - a * xi;
	x = xi;
	while (x <= xf)
	{
		y = a * x + b;
		allume_pixel(x,y);


	}
}
