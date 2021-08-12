#include "fractol.h"

void		viewport_fit(t_view *viewport)
{
	double width;
	double height;

	width = (viewport->x_max - viewport->x_min);
	height = (viewport->y_max - viewport->y_min);
	if ((width / height) >= (float)WIDTH / HEIGHT)
	{
		viewport->y_min = -(width * HEIGHT / WIDTH / 2);
		viewport->y_max = (width * HEIGHT / WIDTH / 2);
	}
	else
	{
		viewport->x_min = -(height * HEIGHT / WIDTH / 2);
		viewport->x_max = (height * HEIGHT / WIDTH / 2);
	}
}

void		reset_viewport(t_core *core)
{
	core->ctx->viewport.off_x = 0;
	core->ctx->viewport.off_y = 0;
	viewport_fit(&core->ctx->viewport);
	core->ctx->viewport.max = 32;
	core->ctx->viewport.zoom = 1.0f;
}

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

/* void	draw_rect(t_core *core, int x_start, int x_length, int y_start, int y_length)
{
	int x;
	int y;

	ft_bzero(core->ctx->buff->addr,
		WIDTH * HEIGHT * (core->ctx->buff->bits_per_pixel / 8));



	y = 0;
	while (y <= y_length)
	{
		x = 0;
		while (x <= x_length)
		{
			//pixel_put((x_start + x), (y_start + y), core);
			x++;
		}
		y++;
	}
} */
