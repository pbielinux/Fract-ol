#include "fractol.h"

void	zoom(int x, int y, t_view *viewport, double zoom)
{
	double	width;
	double	height;
	double	new_width;
	double	new_height;

	width = (viewport->x_max - viewport->x_min) * (viewport->zoom);
	height = (viewport->y_max - viewport->y_min) * (viewport->zoom);
	new_width = (viewport->x_max - viewport->x_min) * (viewport->zoom * zoom);
	new_height = (viewport->y_max - viewport->y_min) * (viewport->zoom * zoom);
	viewport->zoom *= zoom;
	viewport->off_x -= ((double)x / WIDTH) * (new_width - width);
	viewport->off_y -= ((double)y / HEIGHT) * (new_height - height);
}

void	move(int key, t_core *core)
{
	double	width;
	double	height;

	width = (core->ctx->viewport.x_max - core->ctx->viewport.x_min)
		* core->ctx->viewport.zoom;
	height = (core->ctx->viewport.y_max - core->ctx->viewport.y_min)
		* core->ctx->viewport.zoom;
	if (key == KB_UP)
	{
		ft_putstr("Key UP\n");
		core->ctx->viewport.off_y -= height * 0.05f;
	}
	if (key == KB_DOWN)
	{
		ft_putstr("Key DOWN\n");
		core->ctx->viewport.off_y += height * 0.05f;
	}
	if (key == KB_LEFT)
	{
		ft_putstr("Key LEFT\n");
		core->ctx->viewport.off_x -= width * 0.05f;
	}
	if (key == KB_RIGHT)
	{
		ft_putstr("Key RIGHT\n");
		core->ctx->viewport.off_x += width * 0.05f;
	}
}

int	key_press(int key, t_core *core)
{
	if (key == KB_ESC)
	{
		ft_putstr("Key ESC\n");
		ft_free_core(core);
		exit(0);
	}
	move(key, core);
	if (key == KB_PLUS)
		zoom(WIDTH / 2, HEIGHT / 2, &core->ctx->viewport, 1 / 1.1f);
	if (key == KB_MINUS)
		zoom(WIDTH / 2, HEIGHT / 2, &core->ctx->viewport, 1.1f);
	if (key == KB_0)
	{
		core->ctx->fractal->viewport(&core->ctx->viewport);
		reset_viewport(core);
	}
	if (key == KB_W)
		core->ctx->viewport.max++;
	if (key == KB_S)
		core->ctx->viewport.max--;
	if (key == KB_1)
		core->ctx->palette = get_palette(1);
	if (key == KB_2)
		core->ctx->palette = get_palette(2);

	if (key == KB_9)
	{
		if (core->configs->show)
			core->configs->show = false;
		else
			core->configs->show = true;
	}

	if (key == KB_A)
	{
		core->ctx->fractal = get_fractal(1);
		reset_viewport(core);
	}
	if (key == KB_D)
	{
		core->ctx->fractal = get_fractal(2);
		reset_viewport(core);
	}
	render(core);
	return (0);
}
