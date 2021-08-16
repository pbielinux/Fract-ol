#include "fractol.h"

void	viewport_fit(t_view *viewport)
{
	double	width;
	double	height;

	width = (viewport->x_max - viewport->x_min);
	height = (viewport->y_max - viewport->y_min);
	if ((width / height) >= (float)WIDTH / HEIGHT)
	{
		viewport->y_min = - (width * HEIGHT / WIDTH / 2);
		viewport->y_max = (width * HEIGHT / WIDTH / 2);
	}
	else
	{
		viewport->x_min = - (height * HEIGHT / WIDTH / 2);
		viewport->x_max = (height * HEIGHT / WIDTH / 2);
	}
}

void	reset_viewport(t_core *core)
{
	core->ctx->viewport.off_x = 0;
	core->ctx->viewport.off_y = 0;
	core->ctx->fractal->viewport(&core->ctx->viewport);
	viewport_fit(&core->ctx->viewport);
	core->ctx->viewport.max = 32;
	core->ctx->viewport.zoom = 1.0f;
}
