#include "fractol.h"

void	init_viewport(t_view *viewport)
{
	/* Init to mandelbrot set */
	viewport->x_min = -2.0f;
	viewport->x_max = 2.0f;
	viewport->y_min = -1.0f;
	viewport->y_max = 1.0f;
	viewport->off_x = -1.0f;
	viewport->off_x = -0.5f;
	viewport->zoom = 1.5f;
	viewport->max = 50;
}

t_color	*new_color(int ch_A, int ch_R, int ch_G, int ch_B)
{
	t_color *new;
	int			color_value = 0;

	new = (t_color *)malloc(sizeof(t_color));
	color_value = (ch_A << 24 | ch_R << 16 | ch_G << 8 | ch_B);
	new->channel.a = ch_A;
	new->channel.r = ch_R;
	new->channel.g = ch_G;
	new->channel.b = ch_B;

	new->value = color_value;
	return (new);
}

t_ctx		*new_context(int width, int height)
{
	t_ctx	*ctx;

	ctx = (t_ctx *)malloc(sizeof(t_ctx));
	if (!ctx)
		exit (-1);

	ctx->mlx_ptr = mlx_init();
	if (ctx->mlx_ptr == NULL)
	{
		fprintf(stderr, "Cannot stablish a connection with Display Server\n");
		exit(1);
	}
	ctx->win_ptr = 0;
	ctx->width = width;
	ctx->height = height;
	//ctx->rect = &draw_rect;

	return(ctx);
}

void	init_buff(t_ctx *ctx, t_buff **buff, int width, int height)
{
	(*buff) = malloc(sizeof(t_buff));
	if ((*buff) == NULL)
		exit_program(NULL, 5, "Failed to malloc buff");
	ft_bzero((*buff), sizeof(t_buff));
	(*buff)->width = width;
	(*buff)->height = height;
		ft_putstr(CYAN"INIT BUFF 1920 x 1080 px\n"RST);
	(*buff)->img = NULL;
	(*buff)->addr = NULL;
	(*buff)->img = mlx_new_image(ctx->mlx_ptr, width, height);
	(*buff)->addr = mlx_get_data_addr((*buff)->img, &(*buff)->bits_per_pixel,
									&(*buff)->line_length,
									&(*buff)->endian);
	(*buff)->max_addr = (*buff)->line_length * (*buff)->height;
	(*buff)->offset = (*buff)->bits_per_pixel / 8;
	if ((*buff)->addr == NULL)
		exit_program(NULL, 5, "Buff address not set");
	if ((*buff)->img == NULL)
		exit_program(NULL, 5, "Buff image not set");
}

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
	new->ctx->color = new_color(0x00, 0x00, 0xFF, 0x00);
	init_buff(new->ctx, &new->ctx->buff, WIDTH, HEIGHT);
	init_viewport(&new->viewport);
	new->inited = true;
	return (new);
}

int		loop_hook(t_core *core)
{
	char	color_value[200];
	char	color_channels[200];

	sprintf(color_value,"Color Value: 0x%X", core->ctx->color->value);
	sprintf(color_channels,"Ch_A: 0x%X,	Ch_R: 0x%X,	Ch_G: 0x%X,	Ch_B: 0x%X",
				core->ctx->color->channel.a,
				core->ctx->color->channel.r,
				core->ctx->color->channel.g,
				core->ctx->color->channel.b);


	mlx_put_image_to_window(core->ctx->mlx_ptr, core->ctx->win_ptr, core->ctx->buff->img, 0, 0);

	fps_count(core);
	text_put(core->ctx, color_value, 20, 10, 0xFFFFFFFF);
	text_put(core->ctx, color_channels, 20, 40, 0xFFFFFFFF);

	return (core->inited);
}

void	init_loop(t_core *core)
{
	ft_putstr("Loop Init OK\n");

	mlx_hook(core->ctx->win_ptr, 2, (1L << 0), &key_press, core);
	mlx_hook(core->ctx->win_ptr, 17, (1L << 16), &close_program, core);
	mlx_loop_hook(core->ctx->mlx_ptr, &loop_hook, core);

	mlx_loop(core->ctx->mlx_ptr);
}




/* 	ctx->window = mlx_new_window(mlx, WIDTH, HEIGHT, "Fractol");
	if (!ctx->window)
		exit (-1);

	ctx->image = image_init(mlx);
	ctx->color = color_init();
	set_defaults(ctx); */

