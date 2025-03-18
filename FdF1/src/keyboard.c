/* ************************************************************************** */

#include "../include/fdf.h"

//TODO change handle_keypress->handle_esc ??
int	handle_keypress(int key, fdf *data)
{
	if (key == ESCAPE)
	{
		ft_printf("Escape key pressed");	//TODO delete?
		ft_close(data);				//TODO change name
		exit(0);
	}
	return (0);
}
