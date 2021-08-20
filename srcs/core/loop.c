#include "../../headers/fractol.h"

int	loop_hook(t_core *core)
{
	draw_gui(core);
	draw_fractal(core);
	return (core->inited);
}

void	init_loop(t_core *core)
{
	mlx_loop_hook(core->ctx->mlx_ptr, &loop_hook, core);
	mlx_hook(core->ctx->win_ptr, 2, (1L << 0), &key_press, core);
	mlx_hook(core->ctx->win_ptr, 4, (1L << 2), &mouse_click, core);
	mlx_hook(core->ctx->win_ptr, 5, (1L << 3), &mouse_up, core);
	mlx_hook(core->ctx->win_ptr, 6, (1L << 13), &mouse_move, core);
	mlx_hook(core->ctx->win_ptr, 17, (1L << 16), &close_program, core);
	mlx_loop(core->ctx->mlx_ptr);
}
