#include "fractol.h"

t_palette	*get_palette(int index)
{
	t_palette	*palette;

	palette = (t_palette *)malloc(sizeof(t_palette) * 5);
	palette[0] = (t_palette){5, {0x3a0071,0x047878,0xFFB733,0xF57336,0xC22121}};
	palette[1] = (t_palette){5, {0x4929db,0x047878,0xFFB733,0x20e27f,0xe020e2}};

	return(&palette[index - 1]);
}
