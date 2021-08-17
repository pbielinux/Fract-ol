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
# include "types.h"
# include "core_utils.h"

/***************************************/
/*        Viewport Dimensions          */
/***************************************/

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define WIDTH 1280
# define HEIGHT 720

/***************************************/
/*              Functions              */
/***************************************/

/* Core Init */
t_ctx			*new_context(int width, int height);
t_core		*new_core(char *title);
t_buff		*new_buffer(t_ctx *ctx, int width, int height, bool show);
t_buff		*new_window(t_ctx *ctx, int width, int height, bool show);
t_buff		*new_gui(t_ctx *ctx, int width, int height);
void			init_loop(t_core *core);
int				loop_hook(t_core *core);
t_fractal	*get_fractal(int index);
t_fractal	*fractal_search(char  *str);
/* Color */
t_palette	get_palette(int index);
int				get_color(t_pixel pixel, t_ctx *ctx);
t_color		linear_color(double iter, int max_iter, t_palette *palette);
t_color		color_interpolation(t_color c1, t_color c2, double p);
/* View Port */
void			mandelbrot_viewport(t_view *viewport);
void			reset_viewport(t_core *core);
void			viewport_fit(t_view *viewport);
/* Utilities */
void			draw_gui(t_core *core);
void			draw_configs(t_core *core, int x, int y);
void			draw_window(t_core *core, int x, int y);
void			fps_count(t_core *core);
void			draw_rect(t_buff *buff, int x_start, int x_len, int y_start, int y_len);
void			clear_image(t_buff *image, int	width, int height);
int				close_program(void *param);
void			exit_program(t_core *core, int error_code, char *msg);
/* Pixel */
void			pixel_put(t_buff *buff, int x, int y, int color);
void			text_put(t_ctx *ctx, char *str, int x, int y, int color);
/* Keyboard Ctrl */
void			zoom(int x, int y, t_view *viewport, double zoom);
int				key_press(int key, t_core *core);
int				mouse_click(int button, int x, int y, t_core *core);
int				mouse_up(int button, int x, int y, t_core *core);
int				mouse_move(int x, int y, t_core *core);
/* DrawFract */
void			draw_fractal(t_core *core);
void			render(t_core *core);
t_complex	screen_to_complex(int x, int y, t_view *viewport);
t_pixel		mandelbrot_pixel(int x, int y, t_view *viewport);
void			mandelbrot_viewport(t_view *viewport);
t_pixel		julia_pixel(int x, int y, t_view *viewport);
void			julia_viewport(t_view *viewport);
t_pixel		burningship_pixel(int x, int y, t_view *viewport);
void			burningship_viewport(t_view *viewport);

#endif // !_FRACTOL_H_
