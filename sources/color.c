#include "fractol.h"

t_color	color_interpolation(t_color c1, t_color c2, double p)
{
	t_color	c;

	if (c1.value == c2.value)
		return (c1);
	c.argb.b = (char)ft_lerpi((int)c1.argb.b, (int)c2.argb.b, p);
	c.argb.g = (char)ft_lerpi((int)c1.argb.g, (int)c2.argb.g, p);
	c.argb.r = (char)ft_lerpi((int)c1.argb.r, (int)c2.argb.r, p);
	c.argb.a = (char)0x00;
	return (c);
}

t_color	linear_color(double iter, int max_iter, t_palette *palette)
{
	t_color	color;
	double	index;
	double	adjust;
	int			count;

	index = iter / max_iter;
	count = palette->count - 1;
	adjust = fmod(index, 1.0f / count) * count;
	color = color_interpolation(
			(t_color)(palette->colors[(int)(index * count) + 1]),
			(t_color)(palette->colors[(int)(index * count)]),
			(int)(adjust + 1) - adjust);
	return (color);
}

int	get_color(t_pixel pixel, t_ctx *ctx)
{
	if (pixel.iter >= ctx->viewport.max)
		return (0x00000000);
	return (linear_color((double)pixel.iter, ctx->viewport.max,
			&ctx->palette).value);
}
