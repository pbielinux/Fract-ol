#ifndef _FRACTOL_H_
# define _FRACTOL_H_

# define RST "\033[0m"

# define RED    "\033[0;31m"
# define GRN    "\033[0;32m"
# define YELO   "\033[0;33m"
# define BLUE   "\033[0;34m"
# define PINK   "\033[0;35m"
# define CYAN   "\033[0;36m"
# define GREY   "\033[0;90m"
# define PURP   "\033[0;94m"

# define BRED	"\033[1;31m"
# define BGRN	"\033[1;32m"
# define BYELO	"\033[1;33m"
# define BBLUE  "\033[1;34m"
# define BPINK  "\033[1;35m"
# define BCYAN  "\033[1;36m"
# define BGREY  "\033[1;90m"
# define BPURP  "\033[1;94m"

/***************************************/
/*              Includes               */
/***************************************/

# include <stdbool.h>
# include <stdarg.h>
# include <stdlib.h>
# include <strings.h>
# include <stdio.h>
# include <time.h>
# include <mlx.h>
# include <math.h>
# include "libft.h"
# include "macos_keys.h"

/***************************************/
/*        Viewport Dimensions          */
/***************************************/

# define WIDTH 1280
# define HEIGHT 720

/***************************************/
/*             Structures              */
/***************************************/

typedef	struct	s_cordinates
{
	int	x;
	int y;
}								t_point;

typedef	struct	s_complex
{
	double	r;
	double	i;
}								t_complex;

typedef	struct	s_pixel
{
	t_complex	c;
	int				iter;
}								t_pixel;

/* Color Data */
typedef	struct	s_argb
{
	int	a;
	int	r;
	int	g;
	int	b;
}								t_argb;

typedef	union	s_color
{
	int			value;
	t_argb	argb;
}								t_color;

typedef	struct	s_palette
{
	int	count;
	int	colors[8];
}								t_palette;

/* Image Data */
typedef	struct	s_buffer
{
	int		initied;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	int		offset;
	int		max_addr;
}								t_buff;

typedef	struct	s_viewport
{
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	double	zoom;
	double	off_x;
	double	off_y;
	long		max;
}								t_view;

typedef	struct	s_fractal
{
	t_pixel	(*pixel)(int x, int y, t_view *viewport);
	void		(*viewport)(t_view *viewport);
}								t_fractal;

/* Context */
typedef	struct	s_context
{
	void			*mlx_ptr;
	void 			*win_ptr;
	t_buff		*buff;
	t_pixel		*data;
	t_fractal	*fractal;
	t_palette	*palette;
	t_view		viewport;
	int				width;
	int				height;
	int				line_length;
}								t_ctx;


/* Core */
typedef struct	s_core
{
	int			inited;
	t_ctx		*ctx;
}								t_core;


/***************************************/
/*              Functions              */
/***************************************/

/* Core Init */
t_core		*new_core(char *title);
t_ctx			*new_context(int width, int height);
void			init_buff(t_ctx *ctx, t_buff **buff, int width, int height);
void			init_loop(t_core *core);
int				loop_hook(t_core *core);
/* Color */
int				get_color(t_pixel pixel, t_ctx *ctx);
t_color		linear_color(double iter, int max_iter, t_palette *palette);
t_color		color_interpolation(t_color c1, t_color c2, double p);
/* View Port */
void			mandelbrot_viewport(t_view *viewport);
void			reset_viewport(t_core *core);
void			viewport_fit(t_view *viewport);
/* Utilities */
void			fps_count(t_core *core);
int				close_program(void *param);
void			exit_program(t_core *core, int error_code, char *msg);
void			draw_rect(t_core *core, int x_start, int x_length, int y_start, int y_length);
/* Pixel */
void			pixel_put(t_buff *buff, int x, int y, int color);
void			text_put(t_ctx *ctx, char *str, int x, int y, int color);
/* Keyboard Ctrl */
void			zoom(int x, int y, t_view *viewport, double zoom);
int				key_press(int key, t_core *core);
/* DrawFract */
t_pixel		mandelbrot_pixel(int x, int y, t_view *viewport);
void			draw(t_core *core);
void			render(t_core *core);
t_complex	screen_to_complex(int x, int y, t_view *viewport);
void			mandelbrot_viewport(t_view *viewport);

#endif // !_FRACTOL_H_
