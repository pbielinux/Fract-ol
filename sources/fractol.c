#include "fractol.h"

int	main()
{
	t_core	*core;

	core = new_core(WIDTH, HEIGHT, "Fract-ol");

	init_loop(core);
	return (0);
}
