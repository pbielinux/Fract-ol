#include "fractol.h"

static	void	init_images(t_core *core)
{
	char	*gui_path;
	char	*window_path;
	char	*configs_path;

	gui_path = "./sources/GUI.xpm";
	window_path = "./sources/window.xpm";
	configs_path = "./sources/Control-Panel.xpm";
	core->gui->img = mlx_xpm_file_to_image(core->ctx->mlx_ptr, gui_path,
		&core->gui->width, &core->gui->height);
	core->window->img = mlx_xpm_file_to_image(core->ctx->mlx_ptr, window_path,
		&core->gui->width, &core->gui->height);
	core->configs->img = mlx_xpm_file_to_image(core->ctx->mlx_ptr, configs_path,
		&core->configs->width, &core->configs->height);
}

t_core	*new_core(char *title)
{
	t_core	*new;

	new = ft_malloc_or_exit(sizeof(t_core));
	new->ctx = new_context(WIDTH, HEIGHT);
	new->gui = new_buffer(new->ctx, WIN_WIDTH, WIN_HEIGHT, true);
	new->configs = new_buffer(new->ctx, 0, 0, false);
	new->window = new_buffer(new->ctx, 0, 0, true);
	init_images(new);
	new->ctx->win_ptr = mlx_new_window(new->ctx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, title);
	new->inited = true;
	return (new);
}
