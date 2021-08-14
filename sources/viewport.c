#include "fractol.h"

void		viewport_fit(t_view *viewport)
{
	double width;
	double height;

	width = (viewport->x_max - viewport->x_min);
	height = (viewport->y_max - viewport->y_min);
	if ((width / height) >= (float)WIDTH / HEIGHT)
	{
		viewport->y_min = -(width * HEIGHT / WIDTH / 2);
		viewport->y_max = (width * HEIGHT / WIDTH / 2);
	}
	else
	{
		viewport->x_min = -(height * HEIGHT / WIDTH / 2);
		viewport->x_max = (height * HEIGHT / WIDTH / 2);
	}
}

void		reset_viewport(t_core *core)
{
	core->ctx->viewport.off_x = 0;
	core->ctx->viewport.off_y = 0;
	core->ctx->fractal->viewport(&core->ctx->viewport);
	viewport_fit(&core->ctx->viewport);
	core->ctx->viewport.max = 32;
	core->ctx->viewport.zoom = 1.0f;
}





/* void	draw_rect(t_core *core, int x_start, int x_length, int y_start, int y_length)
{
	int x;
	int y;

	ft_bzero(core->ctx->buff->addr,
		WIDTH * HEIGHT * (core->ctx->buff->bits_per_pixel / 8));



	y = 0;
	while (y <= y_length)
	{
		x = 0;
		while (x <= x_length)
		{
			//pixel_put((x_start + x), (y_start + y), core);
			x++;
		}
		y++;
	}
} */
