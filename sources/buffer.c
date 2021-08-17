#include "fractol.h"

t_buff	*new_buffer(t_ctx *ctx, int width, int height, bool show)
{
	t_buff	*new;

	new = ft_malloc_or_exit(sizeof(t_buff));
	new->initied = true;
	new->show = show;
	new->width = width;
	new->height = height;
	new->img = NULL;
	new->addr = NULL;
	new->img = mlx_new_image(ctx->mlx_ptr, width, height);
	new->addr = mlx_get_data_addr(new->img, &new->bits_per_pixel,
			&new->line_length, &new->endian);
	new->bits_per_pixel /= 8;
	if (new->addr == NULL)
		ft_exit_error(NULL, BUFF_ADDR_NOT_SET);
	if (new->img == NULL)
		ft_exit_error(NULL, BUFF_NOT_SET);
	return (new);
}
