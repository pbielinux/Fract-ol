#include "fractol.h"

int		loop_hook(t_core *core)
{
	fps_count(core);
	return (core->inited);
}

void	init_loop(t_core *core)
{
	ft_putstr("Loop Init OK\n");

	mlx_loop_hook(core->ctx->mlx_ptr, &loop_hook, core);
	mlx_hook(core->ctx->win_ptr, 2, (1L << 0), &key_press, core);
	mlx_hook(core->ctx->win_ptr, 17, (1L << 16), &close_program, core);

	mlx_loop(core->ctx->mlx_ptr);
}
