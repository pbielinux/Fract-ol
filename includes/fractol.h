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

typedef	struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	char		*color;
	int		endian;
}								t_data;

typedef	struct s_color
{
	char		*a;
	char		*r;
	char		*g;
	char		*b;
}							t_color;


#endif // !_FRACTOL_H_
