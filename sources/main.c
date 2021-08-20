#include "fractol.h"

int	main(int argc, char **argv)
{
	t_core		*core;
	t_fractal	*fractal;

	if (argc < 2)
		ft_exit_error(NULL, NOT_ENOUGH_ARGS);
	if (!ft_strncmp(argv[1], "--help", 4))
		ft_print_usage();
	fractal = fractal_search(argv[1]);
	if (fractal->name == NULL)
		ft_exit_error(NULL, WRONG_FRACTAL_NAME);
	core = new_core("Fract-ol");
	core->ctx->fractal = fractal;
	reset_viewport(core);
	render(core);
	init_loop(core);
	return (0);
}
