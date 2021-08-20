#include "../../headers/fractol.h"

int	mouse_move(int x, int y, t_core *core)
{
	double	width;
	double	height;

	core->mouse.prev_x = core->mouse.x;
	core->mouse.prev_y = core->mouse.y;
	core->mouse.x = x - 382;
	core->mouse.y = y - 180;
	if ((x >= 380 && x <= 1660) && (y >= 180 && y <= 900))
	{
		if (core->mouse.left_down)
		{
			width = (core->ctx->view.x_max - core->ctx->view.x_min)
				* core->ctx->view.zoom;
			height = (core->ctx->view.y_max - core->ctx->view.y_min)
				* core->ctx->view.zoom;
			core->ctx->view.off_x += (core->mouse.prev_x - core->mouse.x)
				/ WIDTH * width;
			core->ctx->view.off_y += (core->mouse.prev_y - core->mouse.y)
				/ HEIGHT * height;
		}
		if (core->mouse.mid_down)
			core->ctx->view.mouse = screen_to_complex(x, y, &core->ctx->view);
		render(core);
	}
	return (0);
}

int	mouse_up(int button, int x, int y, t_core *core)
{
	(void)x;
	(void)y;
	if (button == 1)
		core->mouse.left_down = false;
	if (button == 3)
		core->mouse.mid_down = false;
	return (0);
}

void	click_palettes(t_core *core, int x, int y)
{
	if ((x >= 160 && x <= 360) && (y >= 410 && y <= 460))
		core->ctx->palette = get_palette(1);
	else if ((x >= 160 && x <= 360) && (y >= 470 && y <= 520))
		core->ctx->palette = get_palette(2);
	else if ((x >= 160 && x <= 360) && (y >= 535 && y <= 585))
		core->ctx->palette = get_palette(3);
	else if ((x >= 160 && x <= 360) && (y >= 600 && y <= 650))
		core->ctx->palette = get_palette(4);
	else if ((x >= 285 && x <= 320) && (y >= 275 && y <= 305))
		core->ctx->smooth = false;
	else if ((x >= 321 && x <= 370) && (y >= 275 && y <= 305))
		core->ctx->smooth = true;
}

void	mouse_left_click(int x, int y, t_core *core)
{
	if ((x >= 1737 && x <= 1850) && (y >= 62 && y <= 350))
	{
		if ((x >= 1737 && x <= 1850) && (y >= 62 && y <= 135))
			core->ctx->fractal = get_fractal(1);
		else if (y >= 173 && y <= 241)
			core->ctx->fractal = get_fractal(2);
		else if (y >= 280 && y <= 350)
			core->ctx->fractal = get_fractal(3);
		reset_viewport(core);
	}
	else if ((x >= 20 && x <= 310) && (y >= 0 && y <= 25))
		core->configs->show = true - core->configs->show;
	if (core->configs->show)
		click_palettes(core, x, y);
	core->mouse.left_down = true;
}

int	mouse_click(int button, int x, int y, t_core *core)
{
	if (button == 1)
		mouse_left_click(x, y, core);
	if (button == 4 && (x >= 380 && x <= 1660) && (y >= 180 && y <= 900))
		zoom(x - 382, y - 180, &core->ctx->view, 1.1f);
	if (button == 5 && (x >= 380 && x <= 1660) && (y >= 180 && y <= 900))
		zoom(x - 382, y - 180, &core->ctx->view, 1 / 1.1f);
	if (button == 3)
		core->mouse.mid_down = true;
	render(core);
	return (0);
}
