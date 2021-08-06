#include "fractol.h"

void	pixel_put(int x, int y, int color, t_buff *buff)
{
	char	*dst;
	int		addr_index;

	addr_index = (y * buff->line_length + x * buff->offset);
	*(unsigned int*)(buff->addr + addr_index) = color;
}
