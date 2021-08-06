#include "fractol.h"

void	exit_program(t_core *core, int error_code, char *msg)
{
	if (error_code != 0)
		ft_putstr(RED);
	else
		ft_putstr(GRN);

	ft_putstr("\nProgram Exit - Error: ");
	ft_putnbr(error_code);
	ft_putstr(" - ");
	ft_putstr(msg);
	ft_putstr("\n"RST);

	ft_putstr(GRN"Exit Done\n"RST);
	exit(0);
}

int	close_program(void *param)
{
	(void)param;
	exit(0);
}

void	draw_rect(t_core *core, int x_start, int x_length, int y_start, int y_length)
{
	int x;
	int y;

/* 	ft_bzero(core->ctx->buff->addr,
		WIDTH * HEIGHT * (core->ctx->buff->bits_per_pixel / 8)); */

	y = 0;
	while (y <= y_length)
	{
		x = 0;
		while (x <= x_length)
		{
			pixel_put((x_start + x), (y_start + y), core);
			x++;
		}
		y++;
	}
}
