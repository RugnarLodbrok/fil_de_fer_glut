#include "glut.h"
#include "fdf.h"
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

int main(int argc, char **argv)
{
	glut_put_pixel_example(argc, argv);
	return 0;
}
