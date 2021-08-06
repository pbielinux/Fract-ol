#include "fractol.h"

t_color	*new_color(int ch_A, int ch_R, int ch_G, int ch_B)
{
	t_color *new;
	int			color_value;

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

	ctx->win_ptr = 0;
	ctx->width = width;
	ctx->height = height;
	ctx->rect = &draw_rect;

	return(ctx);
}

void	init_buff(t_ctx *ctx, t_buff **buff, int width, int height)
{
	(*buff) = malloc(sizeof(t_buff));
	if ((*buff) == NULL)
		exit_program(NULL, 5, "Failed to malloc buff");
	(*buff)->width = width;
	(*buff)->height = height;
		ft_putstr(CYAN"INIT BUFF 1920 x 1080 px"RST);
	(*buff)->img = NULL;
	(*buff)->addr = NULL;
	(*buff)->img = mlx_new_image(ctx->mlx_ptr, width, height);
	(*buff)->addr = mlx_get_data_addr((*buff)->img, &(*buff)->bits_per_pixel,
									&(*buff)->line_length,
									&(*buff)->endian);
	(*buff)->offset = (*buff)->bits_per_pixel / 8;
	if ((*buff)->addr == NULL)
		exit_program(NULL, 5, "Buff address not set");
	if ((*buff)->img == NULL)
		exit_program(NULL, 5, "Buff image not set");
}

t_core	*new_core(int width, int height, char *title)
{
	t_core	*new;

	new = (t_core *)malloc(sizeof(t_core));
	new->ctx = new_context(width, height);
	new->ctx->win_ptr = mlx_new_window(new->ctx->mlx_ptr, width, height, title);
	new->ctx->color = new_color(0xFF, 0xFF, 0xFF, 0xFF);
	init_buff(new->ctx, &new->ctx->buff, width, height);
	new->inited = true;
	return (new);
}

void	init_loop(t_core *core)
{
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

