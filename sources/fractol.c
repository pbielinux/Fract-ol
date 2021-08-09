#include "fractol.h"

int	main()
{
	t_core	*core;

	core = new_core("Fract-ol");
	reset_viewport(core);
	draw_fract(core);

	init_loop(core);
	return (0);
}
