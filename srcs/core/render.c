#include "../../headers/fractol.h"

t_complex	screen_to_complex(int x, int y, t_view *v)
{
	t_complex	pixel;

	pixel.r = (((double)x / WIDTH) * (v->x_max - v->x_min))
		* v->zoom + v->x_min + v->off_x;
	pixel.i = (((double)y / HEIGHT) * (v->y_max - v->y_min))
		* v->zoom + v->y_min + v->off_y;
	return (pixel);
}

void	render(t_core *core)
{
	int				x;
	int				y;

	y = 0;
	while (y < core->ctx->height)
	{
		x = 0;
		while (x < core->ctx->width)
		{
			*(core->ctx->data + y * WIDTH + x)
				= core->ctx->fractal->pixel(x, y, &core->ctx->view);
			x++;
		}
		y++;
	}
	draw_fractal(core);
}

void	draw_fractal(t_core *core)
{
	int				x;
	int				y;
	int				color;

	y = 0;
	while (y < core->ctx->height)
	{
		x = 0;
		while (x < core->ctx->width)
		{
			color = get_color(*(core->ctx->data + y * WIDTH + x), core->ctx);
			pixel_put(core->ctx->buff, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(core->ctx->mlx_ptr, core->ctx->win_ptr,
		core->ctx->buff->img, 382, 180);
	if (!ft_strncmp(core->ctx->fractal->name, "Mandelbrot", 4))
		text_put(core->ctx, "Mandelbrot Set", 960, 155);
	else if (!ft_strncmp(core->ctx->fractal->name, "Julia", 4))
		text_put(core->ctx, "Julia Set", 990, 155);
	else if (!ft_strncmp(core->ctx->fractal->name, "Burningship", 4))
		text_put(core->ctx, "Burning Ship", 970, 155);
}
