#include "fractol.h"

void	text_put(t_ctx *ctx, char *str, int x, int y, int color)
{
	mlx_string_put(ctx->mlx_ptr, ctx->win_ptr, x, y, color, str);
}

void	pixel_put(int x, int y, t_core *core)
{
	int	offset;

	offset = ((y * core->ctx->buff->line_length) + (x * core->ctx->buff->bits_per_pixel / 8));
		*(unsigned int *)(core->ctx->buff->addr + offset) = core->ctx->color->value;
}
