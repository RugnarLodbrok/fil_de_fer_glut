#include <glut.h>
#include "mlx.h"
#include "string.h"
#include "stdlib.h"
#include "libft.h"

t_mlx *M;

static void display_f()
{
	int i;
	int j;
	uint color;
	t_mlx_win *win;

	ft_printf("display start... ");
	win = M->win;
	glBegin(GL_POINTS);
	for (i = 0; i < win->w; ++i)
	{
		for (j = 0; j < win->h; ++j)
		{
			if (!(color = M->win->framebuffer[win->w * j + i]))
				continue;
			glColor4ubv((GLubyte *)&color);
			glVertex2i(i, j);
		}
	}
	glEnd();
	glFlush();  // Render now
	ft_printf("done\n");
}

void *mlx_init()
{
	t_mlx *mlx;

	mlx = ft_memalloc(sizeof(t_mlx));
	M = mlx;
	return mlx;
}

void mlx_pixel_put(t_mlx_win *win, int x, int y, uint color)
{
	win->framebuffer[win->w * y + x] = color;
}

void *mlx_new_window(t_mlx *mlx, int w, int h, const char *title)
{
	int ac;
	char **av;
	t_mlx_win *win;

	win = ft_memalloc(sizeof(t_mlx));
	win->w = w;
	win->h = h;
	win->framebuffer = ft_memalloc(sizeof(int) * w * h);
	mlx->win = win;
	ac = 0;
	av = 0;
	glutInit(&ac, av);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowPosition(80, 80);
	glutInitWindowSize(w, h);
	glutCreateWindow(title);

	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, w, h, 0.0);
	glutDisplayFunc(display_f);
	return (win);
}

static void timer_f(int value) {
	M->loop_hook(M->loop_hook_p);
	glutTimerFunc(17, timer_f, 0);
}

void mlx_loop_hook(t_mlx *mlx, void (*loop_hook)(void *p), void *p)
{
	if (mlx->loop_hook)
		ft_error_exit("loop hook called twice");
	mlx->loop_hook = loop_hook;
	mlx->loop_hook_p = p;
	glutTimerFunc(17, timer_f, 0);
}

void mlx_loop(t_mlx *mlx)
{
	glutMainLoop();
}
