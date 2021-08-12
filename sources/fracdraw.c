#include "fractol.h"

void	mandelbrot_viewport(t_view *viewport)
{
	/* Init to mandelbrot set */
	viewport->x_min = -2.0f;
	viewport->x_max = 1.0f;
	viewport->y_min = -1.0f;
	viewport->y_max = 1.0f;
	viewport->off_x = -0.5f;
}

t_complex	screen_to_complex(int x, int y, t_view *viewport)
{
	t_complex	pixel;

	pixel.r = (((double)x / WIDTH) * (viewport->x_max - viewport->x_min)) * viewport->zoom
		+ viewport->x_min + viewport->off_x;
	pixel.i = (((double)y / HEIGHT) * (viewport->y_max - viewport->y_min)) * viewport->zoom
		+ viewport->y_min + viewport->off_y;
	return (pixel);
}

t_pixel	mandelbrot_pixel(int x, int y, t_view *viewport)
{
	t_complex	z;
	t_complex	c;
	t_complex	temp;
	double		i;

	z = screen_to_complex(x, y, viewport);
	c = z;
	i = 0;
	while (z.r * z.r + z.i * z.i < (1 << 8) && i < viewport->max)
	{
		temp.r = z.r * z.r - z.i * z.i + c.r;
		temp.i = z.r * z.i * 2 + c.i;
		if (z.r == temp.r && z.i == temp.i)
		{
			i = viewport->max;
			break ;
		}
		z.r = temp.r;
		z.i = temp.i;
		i++;
	}
	return ((t_pixel){.c = z, .iter = i});
}
/*
void	draw_fract(t_core *core)
{
	t_complex	z;
	t_complex	c;
	t_complex	temp;
	double		i;
	double		n;


	for (int y = 0; y < core->ctx->height; y++)
	{
		for (int x = 0; x < core->ctx->width; x++)
		{
			z = screen_to_complex(x, y, &core->ctx->viewport);
			c = z;
			i = 0;
			while (z.r * z.r + z.i * z.i < (1 << 8) && i < core->ctx->viewport.max)
			{
				temp.r = z.r * z.r - z.i * z.i + c.r;
				temp.i = z.r * z.i * 2 + c.i;

				z.r = temp.r;
				z.i = temp.i;
				i++;
			}

			if (i == core->ctx->viewport.max)
				reset_color(core->ctx->color);
			else
			{
				//i = ft_map(i, 0, core->viewport.max, 0, 255);
				change_color(core->ctx->color, 0, 0, 0, 0);
			}

			pixel_put(x, y, core);
		}
	}
} */



void	render(t_core *core)
{
	int				x;
	int				y;

	x = 0;
	y = 0;
	while (y < core->ctx->height)
	{
		while (x < core->ctx->width)
		{
			*(core->ctx->data + x + y * WIDTH) = core->ctx->fractal->pixel(x, y, &core->ctx->viewport);
			x++;
		}
		y++;
	}
	draw(core);
}

void	draw(t_core *core)
{
	int				x;
	int				y;
	int				color;

	x = 0;
	y = 0;
	while (y < core->ctx->height)
	{
		while (x < core->ctx->width)
		{
			color = get_color(*(core->ctx->data + x + y * WIDTH), core->ctx);
			pixel_put(core->ctx->buff, x, y, color);
			x++;
		}
			printf("X: %d Y: %d = %X   ", x, y, color);
		y++;
	}
	mlx_put_image_to_window(core->ctx->mlx_ptr, core->ctx->win_ptr, core->ctx->buff->img, 0, 0);
}
