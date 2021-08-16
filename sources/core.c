#include "fractol.h"

t_core	*new_core(char *title)
{
	t_core	*new;

	new = ft_malloc_or_exit(sizeof(t_core));
	new->ctx = new_context(WIDTH, HEIGHT);
	new->ctx->win_ptr = mlx_new_window(new->ctx->mlx_ptr, WIDTH, HEIGHT, title);
	new->gui = 0;
	new->inited = true;
	return (new);
}
