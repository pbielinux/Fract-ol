#include "../../headers/fractol.h"

void	burningship_viewport(t_view *viewport)
{
	viewport->x_min = -2.0f;
	viewport->x_max = 2.0f;
	viewport->y_min = -1.0f;
	viewport->y_max = 1.0f;
	viewport->off_x = -0.6f;
	viewport->off_y = -0.6f;
}

t_pixel	burningship_pixel(int x, int y, t_view *viewport)
{
	t_complex	z;
	t_complex	c;
	t_complex	temp;
	t_pixel		pixel;
	double		i;

	z = screen_to_complex(x, y, viewport);
	c = z;
	i = 0;
	while (z.r * z.r + z.i * z.i < (1 << 8) && i < viewport->max)
	{
		temp.r = z.r * z.r - z.i * z.i + c.r;
		temp.i = 2 * fabs(z.r * z.i) + c.i;
		if (z.r == temp.r && z.i == temp.i)
		{
			i = viewport->max;
			break ;
		}
		z.r = temp.r;
		z.i = temp.i;
		i++;
	}
	pixel.c = z;
	pixel.iter = i;
	return (pixel);
}
