#include "fractol.h"

t_core	*new_core(char *title)
{
	t_core	*new;

	new = (t_core *)malloc(sizeof(t_core));
	new->ctx = new_context(WIDTH, HEIGHT);
/*	Create a new window.
** @param	void *mlx_ptr	the mlx instance pointer;
** @param	int  size_x		the width of the window;
** @param	int  size_y		the height of the window;
** @param	char *title		the title of the window;
** @return	void*			the window instance pointer.*/
	new->ctx->win_ptr = mlx_new_window(new->ctx->mlx_ptr, WIDTH, HEIGHT, title);
	init_buff(new->ctx, &new->ctx->buff, WIDTH, HEIGHT);
	new->inited = true;
	return (new);
}

t_ctx		*new_context(int width, int height)
{
	t_ctx			*ctx;

	ctx = (t_ctx *)malloc(sizeof(t_ctx));
	if (!ctx)
		exit_program(NULL, 5, "Failed to malloc context\n");

	ctx->mlx_ptr = mlx_init();
	if (ctx->mlx_ptr == NULL)
		exit_program(NULL, 5, "Cannot stablish a connection with Display Server\n");

	ctx->data = malloc(sizeof(t_pixel) * WIDTH * HEIGHT);
	if (ctx->data == NULL)
		exit_program(NULL, 5, "Failed to malloc data\n");

	ctx->fractal = get_fractal();

	ctx->win_ptr = 0;
	ctx->width = width;
	ctx->height = height;

	ctx->palette = (t_palette *)malloc(sizeof(t_palette));
	ctx->palette->count = 5;
	ctx->palette->colors[0] = 0x7F1637;
	ctx->palette->colors[1] = 0x047878;
	ctx->palette->colors[2] = 0xFFB733;
	ctx->palette->colors[3] = 0xF57336;
	ctx->palette->colors[4] = 0xC22121;

	return(ctx);
}

void	init_buff(t_ctx *ctx, t_buff **buff, int width, int height)
{
	(*buff) = (t_buff *)malloc(sizeof(t_buff));
	if ((*buff) == NULL)
		exit_program(NULL, 5, "Failed to malloc buff");
	(*buff)->width = width;
	(*buff)->height = height;
		ft_putstr(CYAN"INIT BUFF\n"RST);
	(*buff)->img = NULL;
	(*buff)->addr = NULL;
	(*buff)->img = mlx_new_image(ctx->mlx_ptr, width, height);
	(*buff)->addr = mlx_get_data_addr((*buff)->img, &(*buff)->bits_per_pixel,
									&(*buff)->line_length,
									&(*buff)->endian);
	(*buff)->max_addr = (*buff)->line_length * (*buff)->height;
	(*buff)->bits_per_pixel /= 8;
	if ((*buff)->addr == NULL)
		exit_program(NULL, 5, "Buff address not set");
	if ((*buff)->img == NULL)
		exit_program(NULL, 5, "Buff image not set");
}

int		loop_hook(t_core *core)
{
	fps_count(core);
	return (core->inited);
}

void	init_loop(t_core *core)
{
	ft_putstr("Loop Init OK\n");

	mlx_loop_hook(core->ctx->mlx_ptr, &loop_hook, core);
	mlx_hook(core->ctx->win_ptr, 2, (1L << 0), &key_press, core);
	mlx_hook(core->ctx->win_ptr, 17, (1L << 16), &close_program, core);

	mlx_loop(core->ctx->mlx_ptr);
}




/* 	ctx->window = mlx_new_window(mlx, WIDTH, HEIGHT, "Fractol");
	if (!ctx->window)
		exit (-1);

	ctx->image = image_init(mlx);
	ctx->color = color_init();
	set_defaults(ctx); */

