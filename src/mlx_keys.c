#include "string.h"
#include "mlx.h"
#include "mlx_consts.h"
#include "glut.h"

int glut2mlx_keys[256];
int glut2mlx_keys_special[256];
int glut2mlx_mouse_buttons[8];

void mlx_init_glut_key_map()
{
	memset(glut2mlx_keys, 0, 256);
	glut2mlx_keys[27] = KEY_ESC;
	glut2mlx_keys['w'] = KEY_W;
	glut2mlx_keys['a'] = KEY_A;
	glut2mlx_keys['s'] = KEY_S;
	glut2mlx_keys['d'] = KEY_D;
	glut2mlx_keys['q'] = KEY_Q;
	glut2mlx_keys['e'] = KEY_E;
	glut2mlx_keys['z'] = KEY_Z;
	glut2mlx_keys['x'] = KEY_X;
	glut2mlx_keys['c'] = KEY_C;
	glut2mlx_keys['v'] = KEY_V;
	glut2mlx_keys['b'] = KEY_B;
	glut2mlx_keys['n'] = KEY_N;
	glut2mlx_keys['m'] = KEY_M;
	memset(glut2mlx_keys_special, 0, 256);
	glut2mlx_keys_special[GLUT_KEY_UP] = KEY_UP;
	glut2mlx_keys_special[GLUT_KEY_DOWN] = KEY_DOWN;
	glut2mlx_keys_special[GLUT_KEY_LEFT] = KEY_LEFT;
	glut2mlx_keys_special[GLUT_KEY_RIGHT] = KEY_RIGHT;
	glut2mlx_mouse_buttons[GLUT_LEFT_BUTTON] = MOUSE_B_LEFT;
	glut2mlx_mouse_buttons[GLUT_RIGHT_BUTTON] = MOUSE_B_RIGHT;
	glut2mlx_mouse_buttons[GLUT_MIDDLE_BUTTON] = MOUSE_B_MIDDLE;
}
