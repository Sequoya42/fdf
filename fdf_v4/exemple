/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exemple.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 12:13:16 by rbaum             #+#    #+#             */
/*   Updated: 2015/01/29 19:16:29 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


dx = (dx > 0) ? dx : -dx;
dy = (dy > 0) ? dy : -dy;
if (dy > dx)
{
	err = dy/2;
	while (i <= dy)
	{
		y0 += dy;
		err += dx;
		if (err >= dy)
		{
			err -= dy;
			x0 += dx;
		}
		i++;
		mlx_pixel_put(e->mlx, e->win, (x0 - y0) + INC,
					  (((y0 + x0)/2) + (INC/2)) ,  0XFF0000);
	}
}
else
{
	err = dx/2;
	while (i <= dx)
	{
		x0 += dx;
		err += dy;
		if (err >= dx)
		{
			err -= dx;
			y0 += dy;
		}
		i++;
        mlx_pixel_put(e->mlx, e->win, (x0 - y0) + INC,
                      (((y0 + x0)/2) + (INC/2)) ,  0XFF0000);
	}
}
/**********************************************/
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

/************************************************/
	void x_based_line(t_box coor, t_env *c)
{
    while (coor.xc != coor.x)
    {
        mlx_pixel_put(c->mlx, c->win, coor.xc, coor.yc, 0xFF0000);
        coor.yc = coor.coeff * (coor.xc - coor.x2) + coor.y2; 
        if (coor.x < coor.xc)
            coor.xc--;
        else
            coor.xc++;
    }
}

void y_based_line(t_box coor, t_env *c)
{
    while (coor.yc != coor.y)
    {
        mlx_pixel_put(c->mlx, c->win, coor.xc, coor.yc, 0xFF0000);
        coor.xc = ((coor.yc / coor.coeff) - coor.y2 / coor.coeff) + coor.x2; 
        if (coor.y < coor.yc)
            coor.yc--;
        else
            coor.yc++;
    }
}

void        vect(float x, float y, float x2, float y2, t_env *c)
{    
    t_box   coor;
    
    coor.x2 = x;
    coor.x = x2;
    coor.y2 = y;
    coor.y = y2;
    coor.xc = x;
    coor.yc = y;
    coor.coeff = (y - y2) / (x - x2);
    if ((x-x2)/(y-y2) > 1 || (x-x2)/(y-y2) < -1)
    {
        x_based_line(coor, c);
    }
    else
    {
        y_based_line(coor, c);                
    }
}

struct ::

typedef struct   s_coor_box
{
    float    x;
    float    x2;
    float    y;
    float    y2;
    float    xc;
    float    yc;
    float    coeff;
}                 t_box;

/*////////////////////////////////////////////////*
