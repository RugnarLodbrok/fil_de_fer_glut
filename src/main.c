#include "glut.h"
#include "fdf.h"
#include "mlx.h"
/*
void glut_put_pixel_example(int ac, char **av)
{
	glutInit(&ac, av);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowPosition(80, 80);
	glutInitWindowSize(500,500);

	glutCreateWindow("A Simple OpenGL Program");

	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	gluOrtho2D( 0.0, 500.0, 500.0,0.0 );

	glBegin(GL_POINTS);
	glColor3f(1,1,1);
	glVertex2i(100,100);
	glEnd();
	glFlush();  // Render now
}*/

static void loop_hook(void *p)
{
	ft_printf("loop!\n");
}

int main(int argc, char **argv)
{
	void *mlx;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "HELLO MLX");
	mlx_pixel_put(win, 100, 100, 0xFFFFFF);
	mlx_pixel_put(win, 101, 101, 0xFF0000);
	mlx_pixel_put(win, 102, 102, 0x00FF00);
	mlx_pixel_put(win, 103, 103, 0x0000FF);
	mlx_loop_hook(mlx, loop_hook, 0);
	mlx_loop(mlx);
//	glut_put_pixel_example(argc, argv);
	return 0;
}
