#ifndef TYPES_H
#	define TYPES_H

/***************************************/
/*              Includes               */
/***************************************/
# include <stdbool.h>
# include <stdint.h>

/***************************************/
/*                Types                */
/***************************************/

typedef enum e_exit_code
{
	MEMORY_FAIL,
	BUFF_NOT_SET,
	BUFF_ADDR_NOT_SET,
	MLX_INIT_FAIL
}			t_exit_code;

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
typedef	struct	s_rgba
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;
}								t_rgba;

typedef	union	u_color
{
	int			value;
	t_rgba	argb;
}							t_color;

typedef	struct	s_palette
{
	int			count;
	int			colors[8];
}								t_palette;

/* Image Data */
typedef	struct	s_buffer
{
	bool		initied;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
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

typedef t_pixel	(*t_fn_pixel)(int x, int y, t_view *viewport);
typedef void		(*t_fn_view)(t_view *viewport);

typedef	struct	s_fractal
{
	char				*name;
	t_fn_view		viewport;
	t_fn_pixel	pixel;
}								t_fractal;

/* Context */
typedef	struct	s_context
{
	void			*mlx_ptr;
	void 			*win_ptr;
	t_buff		*buff;
	t_pixel		*data;
	t_fractal	*fractal;
	t_palette	palette;
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

#endif /* TYPES_H */
