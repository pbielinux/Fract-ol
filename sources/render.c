#include "fractol.h"

t_complex	screen_to_complex(int x, int y, t_view *viewport)
{
	t_complex	pixel;

	pixel.r = (((double)x / WIDTH) * (viewport->x_max - viewport->x_min))
		* viewport->zoom + viewport->x_min + viewport->off_x;
	pixel.i = (((double)y / HEIGHT) * (viewport->y_max - viewport->y_min))
		* viewport->zoom + viewport->y_min + viewport->off_y;
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
				= core->ctx->fractal->pixel(x, y, &core->ctx->viewport);
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

	draw_window(core, 380, 151);
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
	if (!ft_strncmp(core->ctx->fractal->name, "Mandelbrot Set", 8))
		text_put(core->ctx, "Mandelbrot Set", 960, 155, 0x00000000);
	else if (!ft_strncmp(core->ctx->fractal->name, "Julia Set", 8))
		text_put(core->ctx, "Julia Set", 990, 155, 0x00000000);
}
