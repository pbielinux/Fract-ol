#include "fractol.h"

int	main(int argc, char **argv)
{
	t_core		*core;

	if (argc < 2)
		ft_exit_error(NULL, NOT_ENOUGH_ARGS);
	core = new_core("Fract-ol");
	core->ctx->fractal = fractal_search(argv[1]);
	reset_viewport(core);
	render(core);
	init_loop(core);
	return (0);
}
