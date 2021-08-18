#include "fractol.h"

void	move(int key, t_core *core)
{
	double	width;
	double	height;

	width = (core->ctx->view.x_max - core->ctx->view.x_min)
		* core->ctx->view.zoom;
	height = (core->ctx->view.y_max - core->ctx->view.y_min)
		* core->ctx->view.zoom;
	if (key == KB_UP)
		core->ctx->view.off_y -= height * 0.05f;
	if (key == KB_DOWN)
		core->ctx->view.off_y += height * 0.05f;
	if (key == KB_LEFT)
		core->ctx->view.off_x -= width * 0.05f;
	if (key == KB_RIGHT)
		core->ctx->view.off_x += width * 0.05f;
}

void	color_controls(int key, t_core *core)
{
	if (key == KB_1)
		core->ctx->palette = get_palette(1);
	else if (key == KB_2)
		core->ctx->palette = get_palette(2);
	else if (key == KB_3)
		core->ctx->palette = get_palette(3);
	else if (key == KB_4)
		core->ctx->palette = get_palette(4);
	else if (key == KB_STAR)
		core->ctx->smooth = true - core->ctx->smooth;
}

int	key_press(int key, t_core *core)
{
	if (key == KB_ESC)
		ft_exit(core);
	move(key, core);
	color_controls(key, core);
	if (key == KB_PLUS)
		zoom(WIDTH / 2, HEIGHT / 2, &core->ctx->view, 1 / 1.1f);
	if (key == KB_MINUS)
		zoom(WIDTH / 2, HEIGHT / 2, &core->ctx->view, 1.1f);
	if (key == KB_0)
	{
		core->ctx->fractal->viewport(&core->ctx->view);
		reset_viewport(core);
	}
	if (key == KB_W)
		core->ctx->view.max++;
	if (key == KB_S)
		core->ctx->view.max--;
	if (key == KB_ENTER)
		core->configs->show = true - core->configs->show;
	render(core);
	return (0);
}
