#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	void	*mlx;
	void	*win;
	char	*relative_path;
	void	*img;
	int		img_width;
	int		img_height;

	relative_path = "img.xpm";
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1920, 1080, "hellow world");

	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);

	mlx_put_image_to_window(mlx, win, img, 500,200);
	mlx_loop(mlx);
}

/* 
hooks stopping
destroy the wind and exite
*/
