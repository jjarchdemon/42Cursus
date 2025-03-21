/* ************************************************************************** */
#include "fdf.h"

t_point	make_projection(int x, int y, t_dd *dd)
{
	t_point	point;
	//extract elevation
	point.z = dd->map->array[y][x][0];
	//determine color
	if (dd->map->array[y][x][1] >= 0)
		point.color = dd->map->array[y][x][1];
	else
		point.color = //TODO get a default color
	//apply zoom
	point.x = x * dd->camera->zoom;
	point.y = y * dd->camera->zoom;
	point.z *= dd->camera->zoom / dd->camera->z_height;
	//center the map
	point.x -= (dd->map->width * dd->camera->zoom) / 2;
	point.z -= (dd->map->height * dd->camera->zoom) / 2;
}
