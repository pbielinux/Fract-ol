#include "fractol.h"

void	ft_free_core(t_core	*core)
{
	if (core)
	{
		mlx_destroy_image(core->ctx->mlx_ptr, core->ctx->buff->img);
		mlx_destroy_window(core->ctx->mlx_ptr, core->ctx->win_ptr);
		free(core->ctx->data);
	}
}

void	*ft_malloc_or_exit(int	size)
{
	void	*malloc_result;

	malloc_result = malloc(size);
	if (!malloc_result)
		ft_exit_error(NULL, MEMORY_FAIL);
	return (malloc_result);
}
