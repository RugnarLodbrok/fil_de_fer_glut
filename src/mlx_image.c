#include "mlx.h"

t_mlx_image *mlx_new_image(t_mlx *mlx, int w, int h)
{
	t_mlx_image *im;

	im = ft_memalloc(sizeof(t_mlx_image));
	im->w = w;
	im->h = h;
	im->bpp = sizeof(uint);
	im->data = malloc(im->bpp * w * h);
	return im;
}

uint *mlx_get_data_addr(t_mlx_image *image, int *bpp, int *row_len, int *en)
{
	*bpp = image->bpp;
	*row_len = image->w;
	*en = endian();
	return image->data;
}

void mlx_put_image_to_window(t_mlx *mlx, t_mlx_win *win, t_mlx_image *im, int x,
							 int y)
{
	int y1;
	int x1;
	int i;
	int j;
	int w;

	y1 = y + im->h;
	if (y1 > win->h)
		y1 = win->h;
	x1 = x + im->w;
	if (x1 > win->w)
		x1 = win->w;
	if (x1 <= x)
		return;
	w = x1 - x;
	for (i = y, j = 0; i < y1; i++, j++)
		ft_memcpy(
				&win->framebuffer[i * win->w + x],
				&im->data[im->w * j],
				w);
}
