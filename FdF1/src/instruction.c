/* ************************************************************************** */

#include "../include/fdf.h"

//TODO change fn name to draw_pixel ?? , also order of params
void	draw_pixel(fdf *data, int x, int y, int color)
{
	char	*dst;
	int	pixel_offset;

	pixel_offset = y * data->size_line + x * (data->b_per_pixel / 8); //TODO bpp
	if (x >= 0 && x < WIDTH && y >= 0 && y <= HEIGHT)
	{
		dst = data->address_data + pixel_offset;
		*(unsigned int *)dst = color;
	}
}
