#include "libft.h"

double	ft_map(double nb, t_range range)
{
	return (range.out_min + ((range.out_max - range.out_min)
			/ (range.in_max - range.in_min)) * (nb - range.in_min));
}
