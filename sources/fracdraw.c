#include "fractol.h"


t_complex	screen_to_complex(int x, int y, t_view *viewport)
{
	t_complex	pixel;

	pixel.r = (((double)x / WIDTH) * (viewport->x_max - viewport->x_min)) * viewport->zoom
		+ viewport->x_min + viewport->off_x;
	pixel.i = (((double)y / HEIGHT) * (viewport->y_max - viewport->y_min)) * viewport->zoom
		+ viewport->y_min + viewport->off_y;
	return (pixel);
}

double	ft_map(double nb, double	in_min, double in_max, double out_min, double out_max)
{
	return (out_min + ((out_max - out_min) / (in_max - in_min)) * (nb - in_min));
}

void	draw_fract(t_core *core)
{
	t_complex	z;
	t_complex	c;
	t_complex	temp;
	int				bright;
	int				i;


	for (int y = 0; y < core->ctx->height; y++)
	{
		for (int x = 0; x < core->ctx->width; x++)
		{
			z = screen_to_complex(x, y, &core->viewport);
			c = screen_to_complex(x, y, &core->viewport);
			i = 0;
			while (z.r * z.r + z.i * z.i < (1 << 8) && i < core->viewport.max)
			{
				temp.r = z.r * z.r - z.i * z.i + c.r;
				temp.i = z.r * z.i * 2 + c.i;

				if (z.r == temp.r && z.i == temp.i)
				{
					i = core->viewport.max;
					break;
				}
				z.r = temp.r;
				z.i = temp.i;
				i++;
			}

			if (i == core->viewport.max)
				core->ctx->color = new_color(0, 0, 0, 0);
			else
				core->ctx->color = new_color(i, 0, i, i * 20);

			pixel_put(x, y, core);
		}
	}
}

/* void	mandelbrot(t_core *core, int x, int y)
{
	t_complex	z;
	t_complex	c;
	t_complex	temp;
	int				i;
	int				color;

	color = core->ctx->color->value;

	z = screen_to_complex(x, y, &core->viewport);
	c = z;
	i = 0;
	while (z.r * z.r + z.i * z.i < (1 << 8) && i++ < core->viewport.max)
	{
		temp.r = z.r * z.r - z.i * z.i + c.r;
		temp.i = z.r * z.i * 2 + c.i;
		z = temp;
	}
	if (i == core->viewport.max)
		color = 0;
	else
		color *= i;
	pixel_put(x, y, core);
}

void	draw_fract_2(t_core *core)
{
	int				x;
	int				y;
	t_complex	z;
	t_complex	c;
	t_complex	temp;
	int				i;
	int				color;

	color = core->ctx->color->value;
	x = 0;
	y = 0;
	while (y++ < core->ctx->height)
	{
		while (x++ < core->ctx->width)
		{
				z = screen_to_complex(x, y, &core->viewport);
				c = z;
				i = 0;
				while (z.r * z.r + z.i * z.i < (1 << 8) && i++ < core->viewport.max)
				{
					temp.r = z.r * z.r - z.i * z.i + c.r;
					temp.i = z.r * z.i * 2 + c.i;
					z = temp;
				}
				if (i == core->viewport.max)
					color = 0;
				else
					color *= i;
				pixel_put(x, y, core, color);
		}
	}

} */
