#include "fractol.h"

t_ctx	*new_context(int width, int height)
{
	t_ctx	*ctx;

	ctx = ft_malloc_or_exit(sizeof(t_ctx));
	ctx->mlx_ptr = mlx_init();
	if (ctx->mlx_ptr == NULL)
		ft_exit_error(NULL, MLX_INIT_FAIL);
	ctx->data = ft_malloc_or_exit(sizeof(t_pixel) * WIDTH * HEIGHT);
	ctx->buff = new_buffer(ctx, WIDTH, HEIGHT, true);
	ctx->fractal = get_fractal(1);
	ctx->win_ptr = 0;
	ctx->width = width;
	ctx->height = height;
	ctx->palette = get_palette(2);
	return (ctx);
}
