#include "fractol.h"

void	text_put(char *str, int x, int y, t_ctx *ctx)
{
	mlx_string_put(ctx->mlx_ptr, ctx->win_ptr, x, y, ctx->color, str);
}

void	pixel_put(int x, int y, t_core *core)
{
	char	*offset;

	offset = core->ctx->buff->addr + ((y * core->ctx->buff->line_length) + (x * core->ctx->buff->bits_per_pixel / 8));
		*(unsigned int *)offset = core->ctx->color->value;
}
