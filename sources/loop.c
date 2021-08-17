#include "fractol.h"

int	loop_hook(t_core *core)
{
	mlx_clear_window(core->ctx->mlx_ptr, core->ctx->win_ptr);
	draw_gui(core);
	draw(core);
	if (core->configs->show)
		draw_configs(core);
	if (ft_strncmp(core->ctx->fractal->name, "Mandelbrot Set", 5))
		text_put(core->ctx, "Mandelbrot Set", 883, 155, 0x00000000);
	else if (ft_strncmp(core->ctx->fractal->name, "Julia Set", 5))
		text_put(core->ctx, "Julia Set", 910, 155, 0x00000000);
	return (core->inited);
}

void	init_loop(t_core *core)
{
	mlx_loop_hook(core->ctx->mlx_ptr, &loop_hook, core);
	mlx_hook(core->ctx->win_ptr, 2, (1L << 0), &key_press, core);
	mlx_hook(core->ctx->win_ptr, 17, (1L << 16), &close_program, core);
	mlx_loop(core->ctx->mlx_ptr);
}
