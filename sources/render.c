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
	draw(core);
}

void	draw(t_core *core)
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
}
