#include "fractol.h"

void	zoom(int x, int y, t_view *view, double zoom)
{
	double	width;
	double	height;
	double	new_width;
	double	new_height;

	width = (view->x_max - view->x_min) * (view->zoom);
	height = (view->y_max - view->y_min) * (view->zoom);
	new_width = (view->x_max - view->x_min) * (view->zoom * zoom);
	new_height = (view->y_max - view->y_min) * (view->zoom * zoom);
	view->zoom *= zoom;
	view->off_x -= ((double)x / WIDTH) * (new_width - width);
	view->off_y -= ((double)y / HEIGHT) * (new_height - height);
}

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
	core->ctx->view.off_x = 0;
	core->ctx->view.off_y = 0;
	core->ctx->fractal->viewport(&core->ctx->view);
	viewport_fit(&core->ctx->view);
	core->ctx->view.max = 32;
	core->ctx->view.zoom = 1.0f;
	core->ctx->view.mouse.r = -0.835f;
	core->ctx->view.mouse.i = -0.232f;
}
