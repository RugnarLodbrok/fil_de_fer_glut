#include <glut.h>
#include "mlx.h"
#include "mlx_consts.h"

extern t_mlx *M;
extern int glut2mlx_keys[256];
extern int glut2mlx_keys_special[256];
extern int glut2mlx_mouse_buttons[8];

static void timer_f(int value)
{
	M->loop_hook(M->loop_hook_p);
	glutPostRedisplay();
	glutTimerFunc(17, timer_f, 0);
}

void mlx_loop_hook(t_mlx *mlx, int (*loop_hook)(void *p), void *p)
{
	mlx->loop_hook = loop_hook;
	mlx->loop_hook_p = p;
	glutTimerFunc(17, timer_f, 0);
}

static void cb_key_press(unsigned char key, int x, int y)
{
	t_mlx_hook *h;
	int keycode;

	h = &M->win->hooks[MLX_EVENT_KEY_PRESS];
	keycode = glut2mlx_keys[key];
	h->f(keycode, h->p);
}

static void cb_key_special_press(int key, int x, int y)
{
	t_mlx_hook *h;
	int keycode;

	h = &M->win->hooks[MLX_EVENT_KEY_PRESS];
	keycode = glut2mlx_keys_special[key];
	h->f(keycode, h->p);
}

static void cb_key_release(unsigned char key, int x, int y)
{
	t_mlx_hook *h;
	int keycode;

	h = &M->win->hooks[MLX_EVENT_KEY_RELEASE];
	keycode = glut2mlx_keys[key];
	h->f(keycode, h->p);
}

static void cb_key_special_release(int key, int x, int y)
{
	t_mlx_hook *h;
	int keycode;

	h = &M->win->hooks[MLX_EVENT_KEY_RELEASE];
	keycode = glut2mlx_keys_special[key];
	h->f(keycode, h->p);
}

void cb_mouse_event(int button, int state, int x, int y)
{
	t_mlx_hook *h;

	button = glut2mlx_mouse_buttons[button];
	if (state == GLUT_DOWN)
		h = &M->win->hooks[MLX_EVENT_MOUSE_PRESS];
	else if (state == GLUT_UP)
		h = &M->win->hooks[MLX_EVENT_MOUSE_RELEASE];
	else
		return;
	h->f(button, x, y, h->p);
}

void cb_mouse_move(int x, int y)
{
	t_mlx_hook *h;

	h = &M->win->hooks[MLX_EVENT_MOUSE_MOVE];
	h->f(x, y, h->p);
}

void mlx_hook(t_mlx_win *win, int event, int event_mask,
			  int (*hook)(), void *p)
{
	t_mlx_hook *h;

	h = &win->hooks[event];
	h->f = hook;
	h->p = p;
	//todo: protection from calling twice?
	if (event == MLX_EVENT_KEY_PRESS)
	{
		glutKeyboardFunc(cb_key_press);
		glutSpecialFunc(cb_key_special_press);
	}
	if (event == MLX_EVENT_KEY_RELEASE)
	{
		glutKeyboardUpFunc(cb_key_release);
		glutSpecialUpFunc(cb_key_special_release);
	}
	if (event == MLX_EVENT_MOUSE_PRESS)
		if (!win->hooks[MLX_EVENT_MOUSE_RELEASE].f)
			glutMouseFunc(cb_mouse_event);
	if (event == MLX_EVENT_MOUSE_RELEASE)
		if (!win->hooks[MLX_EVENT_MOUSE_PRESS].f)
			glutMouseFunc(cb_mouse_event);
	if (event == MLX_EVENT_MOUSE_MOVE)
	{
		glutMotionFunc(cb_mouse_move);
		glutPassiveMotionFunc(cb_mouse_move);
	}
}
