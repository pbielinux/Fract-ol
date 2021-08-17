#include "fractol.h"

void	draw_gui(t_core *core)
{
	mlx_put_image_to_window(core->ctx->mlx_ptr, core->ctx->win_ptr,
		core->gui->img, 0, 0);
}

void	draw_window(t_core *core, int x, int y)
{
	mlx_put_image_to_window(core->ctx->mlx_ptr, core->ctx->win_ptr,
		core->window->img, x, y);
}

void	draw_configs(t_core *core, int x, int y)
{
	mlx_put_image_to_window(core->ctx->mlx_ptr, core->ctx->win_ptr,
		core->configs->img, x, y);
	text_put(core->ctx, ft_itoa(core->ctx->viewport.max), x + 85,
		y + 186, 0x00000000);
}
