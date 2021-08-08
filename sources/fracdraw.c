#include "fractol.h"

double	ft_map(double nb, double	in_min, double in_max, double out_min, double out_max)
{
	return (out_min + ((out_max - out_min) / (in_max - in_min)) * (nb - in_min));
}

void	draw_fract(t_core *core, int maxIterations)
{
	int 		bright;
	int			i;
	double	a, ca;
	double	b, cb;
	double	realComponent;
	double	complexComponent;


	for (int x = 0; x < core->ctx->width; x++)
	{
		for (int y = 0; y < core->ctx->height; y++)
		{
			a = ft_map(x, 0, (double)core->ctx->width, -2.5, 2.5);
			b = ft_map(y, 0, (double)core->ctx->height, -2.5, 2.5);

			ca = a;
			cb = b;

			i = 0;
			while ( i < maxIterations)
			{
				realComponent = a * a - b * b;
				complexComponent = 2 * a * b;

				a = realComponent + ca;
				b = complexComponent + cb;

				if (abs(realComponent + complexComponent) > 16)
					break;
				i++;
			}

			bright = (int)ft_map(i, 0, maxIterations, 0, 255);

			if (i == maxIterations)
				bright = 0;
			core->ctx->color = new_color(0, 255, bright, 0);
			pixel_put(x, y, core);
		}
	}
}
