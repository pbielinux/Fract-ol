#ifndef _FRACTOL_H_
# define _FRACTOL_H_

/***************************************/
/*              Includes               */
/***************************************/

# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include "libft.h"

/***************************************/
/*        Viewport Dimensions          */
/***************************************/

# define WIDTH 1920
# define HEIGHT 1080


/***************************************/
/*             Structures              */
/***************************************/

/* MinilibX Data */
typedef	struct	s_mlx
{
	long	*ptr;
	long	*window_ptr;
}								t_mlx;

/* Image Data */
typedef	struct	s_image
{
	long long	*img;
	long long	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}								t_image;

/* Color Data */
typedef	struct	s_color
{
	uint8_t	value;
	uint8_t	alpha;
	uint8_t	red;
	uint8_t	green;
	uint8_t	blue;
}								t_color;

/***************************************/
/*              Functions              */
/***************************************/

t_mlx		*mlx_data_init();
t_image	*image_data_init(t_mlx *mlx);
t_color	*color_data_init();
uint8_t	get_opposite_color(t_color color);
uint8_t		color_compiler(t_color *color, int ch_A, int ch_R, int ch_G, int ch_B);

#endif // !_FRACTOL_H_
