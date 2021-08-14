#include "fractol.h"

t_core	*new_core(char *title)
{
	t_core	*new;

	new = ft_malloc_or_exit(sizeof(t_core));
	new->ctx = new_context(WIDTH, HEIGHT);
/*	Create a new window.
** @param	void *mlx_ptr	the mlx instance pointer;
** @param	int  size_x		the width of the window;
** @param	int  size_y		the height of the window;
** @param	char *title		the title of the window;
** @return	void*			the window instance pointer.*/
	new->ctx->win_ptr = mlx_new_window(new->ctx->mlx_ptr, WIDTH, HEIGHT, title);
	new->inited = true;
	return (new);
}

