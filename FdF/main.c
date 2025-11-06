#include <mlx.h>
#include <stdio.h>

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	
	#ifdef __APPLE__
		printf("this is a mac\n");
	#endif

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 800, "Hello world!");
	(void)mlx_win;
	mlx_loop(mlx);
}
