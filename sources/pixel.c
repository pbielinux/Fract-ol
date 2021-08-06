#include "fractol.h"

void	pixel_put(int x, int y, t_core *core)
{
	char	*offset;

	offset = core->ctx->buff->addr + ((y * core->ctx->buff->line_length) + (x * core->ctx->buff->bits_per_pixel / 8));
	*(unsigned int *)offset = core->ctx->color->value;
}
