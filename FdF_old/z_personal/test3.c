#include "mlx_linux/mlx.h"

int keypress(int keycode, void*param)
{
	if (keycode == 65307)
	{
		mlx_clear_window(param, param);
		mlx_destroy_window(param, param);
	}
	return(0);
}

int main ()
{
	void *mlx = mlx_init();
	void *window = mlx_new_window(mlx, 800, 800, "My window");
	mlx_key_hook(window, keypress, mlx);
	mlx_loop(mlx);
	return(0);
}
