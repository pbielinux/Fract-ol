#include "fractol.h"

int	mouse_move(int x, int y, t_core *core)
{
	if (core->mouse.is_down && (x >= 380 && x <= 1660) && (y >= 180 && y <= 900))
	{
		core->ctx->viewport.mouse = screen_to_complex(x, y, &core->ctx->viewport);
		render(core);
	}
}

int	mouse_up(int button, int x, int y, t_core *core)
{
	(void)x;
	(void)y;
	core->mouse.is_down = 0;
	return (0);
}

int	mouse_click(int button, int x, int y, t_core *core)
{
	if (button == 1)
	{
		if ((x >= 1737 && x <= 1850) && (y >= 62 && y <= 135))
		{
			core->ctx->fractal = get_fractal(1);
			reset_viewport(core);
		}
		else if ((x >= 1737 && x <= 1850) && (y >= 173 && y <= 241))
		{
			core->ctx->fractal = get_fractal(2);
			reset_viewport(core);
		}
		else if ((x >= 20 && x <= 310) && (y >= 0 && y <= 25))
			core->configs->show = true;

		else if ((x >= 70 && x <= 90) && (y >= 80 && y <= 100))
			core->configs->show = false;
		printf("X: %d  Y: %d\n", x, y);
	}
	core->mouse.is_down = 1;
	render(core);
	return (0);
}
