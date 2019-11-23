#ifndef MLX_H
# define MLX_H
#include "libft.h"

# define bzero(b,len) (memset((b), '\0', (len)), (void) 0)
# define MLX_FRAMERATE 60

typedef struct
{
	int w;
	int h;
	uint *framebuffer;
} t_mlx_win;

typedef struct
{
	t_mlx_win *win;
	void (*loop_hook)(void *p);
	void *loop_hook_p;
} t_mlx;

//typedef struct
//{
//	void *p();
//} t_mlx_hook;

void mlx_loop(t_mlx *mlx);
void *mlx_new_window(t_mlx *mlx, int w, int h, const char *title);
void *mlx_init();
void mlx_pixel_put(t_mlx_win *win, int x, int y, uint color);
void mlx_loop_hook(t_mlx *mlx, void (*loop_hook)(void *p), void *p);

#endif
