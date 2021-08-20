#include "fractol.h"

void	draw_select(t_core *core, int x, int y)
{
	text_put(core->ctx, "|", x, y + 20);
	text_put(core->ctx, "|", x + 210, y + 20);
	text_put(core->ctx, "|", x, y + 40);
	text_put(core->ctx, "|", x + 210, y + 40);
}

void	draw_gui(t_core *core)
{
	mlx_put_image_to_window(core->ctx->mlx_ptr, core->ctx->win_ptr,
		core->gui->img, 0, 0);
	mlx_put_image_to_window(core->ctx->mlx_ptr, core->ctx->win_ptr,
		core->window->img, 380, 151);
	if (core->configs->show)
	{
		mlx_put_image_to_window(core->ctx->mlx_ptr, core->ctx->win_ptr,
			core->configs->img, 138, 152);
		text_put(core->ctx, ft_itoa(core->ctx->view.max), 220, 338);
		if (core->ctx->smooth)
			text_put(core->ctx, "#", 342, 273);
		else
			text_put(core->ctx, "#", 297, 273);
		if (core->ctx->palette.colors[0] == 0x1f0047)
			draw_select(core, 150, 400);
		else if (core->ctx->palette.colors[0] == 0x000000)
			draw_select(core, 150, 460);
		else if (core->ctx->palette.colors[0] == 0x000001)
			draw_select(core, 150, 520);
		else if (core->ctx->palette.colors[0] == 0x000002)
			draw_select(core, 150, 580);
	}
}
