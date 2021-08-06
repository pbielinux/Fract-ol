#ifndef _FRACTOL_H_
# define _FRACTOL_H_

/***************************************/
/*              Includes               */
/***************************************/

# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <stdbool.h>
# include "libft.h"
# include "macos_keys.h"

/***************************************/
/*        Viewport Dimensions          */
/***************************************/

# define WIDTH 1920
# define HEIGHT 1080

/***************************************/
/*             Structures              */
/***************************************/

typedef	struct	s_cordinates
{
	int	x;
	int y;
}								t_point;


/* Color Data */
typedef	struct	s_argb
{
	int	a;
	int	r;
	int	g;
	int	b;
}								t_argb;

typedef	struct	s_color
{
	int			value;
	t_argb	channel;
}								t_color;

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
}								t_buff;

/* Context */
typedef	struct	s_context
{
	int			width;
	int			height;
	int			line_length;
	void		*mlx_ptr;
	void 		*win_ptr;
	t_color	*color;
	t_buff	*buff;
	t_buff	*cur_buff;
	void		(*rect)(t_point, struct s_ctx *);
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
t_core	*new_core(int width, int height, char *title);
t_ctx		*new_context(int width, int height);
t_color	*new_color(int ch_A, int ch_R, int ch_G, int ch_B);
void		init_buff(t_ctx *ctx, t_buff **buff, int width, int height);
void		init_loop(t_core *core);
/* Utilities */
int			close_program(void *param);
void		draw_rect(t_core *core, int x_start, int x_length, int y_start, int y_length);
/* Pixel */
void		pixel_put(int x, int y, int color, t_buff *buff);
/* Keyboard Ctrl */
int			key_press(int key, t_core *core);

#endif // !_FRACTOL_H_
