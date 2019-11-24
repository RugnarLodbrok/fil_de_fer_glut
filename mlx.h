#ifndef MLX_H
# define MLX_H

# define bzero(b, len) (memset((b), '\0', (len)), (void) 0)
# define MLX_FRAMERATE 60
# define MLX_EVENT_KEY_PRESS 2
# define MLX_EVENT_KEY_RELEASE 3
# define MLX_EVENTS_NUMBER 4

# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_Q 12
# define KEY_E 14
# define KEY_ESC 53
# define KEY_I 34
# define KEY_P 35
# define KEY_PLUS 69
# define KEY_MINUS 78
# define KEY_HOME 115
# define KEY_END 119

typedef struct
{
	void *p;
	void (*f)(int keycode, void *p);
} t_mlx_hook;

typedef struct
{
	int w;
	int h;
	int bpp;
	unsigned int *data;
} t_mlx_image;

typedef struct
{
	int w;
	int h;
	unsigned int *framebuffer;
	t_mlx_hook *hooks;
} t_mlx_win;

typedef struct
{
	t_mlx_win *win;
	int (*loop_hook)(void *p);
	void *loop_hook_p;
} t_mlx;


void mlx_loop(t_mlx *mlx);
void mlx_init_glut_key_map();
void *mlx_new_window(t_mlx *mlx, int w, int h, const char *title);
void *mlx_init();
void mlx_pixel_put(t_mlx *mlx, t_mlx_win *win, int x, int y, unsigned int color);
void mlx_loop_hook(t_mlx *mlx, int (*loop_hook)(void *p), void *p);
void mlx_hook(t_mlx_win *win, int event, int event_mask,
			  void (*hook)(int keycode, void *p),
			  void *p);
void mlx_string_put(t_mlx *mlx, t_mlx_win *win, int x, int y, unsigned int color, const char *str);
t_mlx_image *mlx_new_image(t_mlx *mlx, int w, int h);
unsigned int *mlx_get_data_addr(t_mlx_image *image, int *bpp, int *row_len, int *en);
void mlx_put_image_to_window(t_mlx *mlx, t_mlx_win *win, t_mlx_image *im, int x, int y);

#endif
