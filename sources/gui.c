#include "fractol.h"

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
	}
}
