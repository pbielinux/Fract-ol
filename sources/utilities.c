#include "fractol.h"

void		fps_count(t_core *core)
{
	static time_t	str_time = 0;
	static int		count = 0;
	static char		*str = NULL;

	if (str_time == 0)
		str_time = time(0);
	if (time(0) - str_time >= 1)
	{
		str_time = time(0);
		free(str);
		str = ft_itoa(count);
		count = 0;
	}
	else
		count++;
	if (str != NULL)
	{
		text_put(core->ctx, "FPS:", 20, 90, 0xFFFFFFFF);
		text_put(core->ctx, str, 60, 90, 0xFFFFFFFF);
	}
}

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

/*  	ft_bzero(core->ctx->buff->addr,
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
	mlx_put_image_to_window(core->ctx->mlx_ptr, core->ctx->win_ptr, core->ctx->buff->img, 0, 0);
}
