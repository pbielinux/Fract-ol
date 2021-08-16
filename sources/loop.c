#include "fractol.h"

int	loop_hook(t_core *core)
{
	draw(core);
	fps_count(core);
	draw_gui(core);
	mlx_put_image_to_window(core->ctx->mlx_ptr, core->ctx->win_ptr,
		core->ctx->gui->img, 0, 0);
	mlx_put_image_to_window(core->ctx->mlx_ptr, core->ctx->win_ptr,
		core->ctx->buff->img, 278, 174);
	text_put(core->ctx, "MANDELBROT SET", 883, 15, 0xFFFFFFFF);
	return (core->inited);
}

void	init_loop(t_core *core)
{
	mlx_loop_hook(core->ctx->mlx_ptr, &loop_hook, core);
	mlx_hook(core->ctx->win_ptr, 2, (1L << 0), &key_press, core);
	mlx_hook(core->ctx->win_ptr, 17, (1L << 16), &close_program, core);
	mlx_loop(core->ctx->mlx_ptr);
}
