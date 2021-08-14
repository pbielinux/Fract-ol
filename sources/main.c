#include "fractol.h"

int	main()
{
	t_core		*core;

	core = new_core("Fract-ol");
	reset_viewport(core);
	render(core);
	init_loop(core);

	return (0);
}
