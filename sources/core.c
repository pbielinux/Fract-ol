#include "fractol.h"

t_core	*new_core(char *title)
{
	t_core	*new;

	new = ft_malloc_or_exit(sizeof(t_core));
	new->ctx = new_context(WIDTH, HEIGHT);
	new->gui = new_buffer(new->ctx, WIN_WIDTH, WIN_HEIGHT, true);
	new->configs = new_buffer(new->ctx, 0, 0, false);
	new->window = new_window(new->ctx, 0, 0, true);
	new->ctx->win_ptr = mlx_new_window(new->ctx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, title);
	new->inited = true;
	return (new);
}
