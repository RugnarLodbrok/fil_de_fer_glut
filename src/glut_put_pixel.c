#include <Windows.h>  // for MS Windows
#include <glut.h>  // GLUT, include glu.h and gl.h

/* Handler for window-repaint event. Call back when the window first appears and
   whenever the window needs to be re-painted. */
static void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	gluOrtho2D( 0.0, 500.0, 500.0,0.0 );

	glBegin(GL_POINTS);
	glColor3f(1,1,1);
	glVertex2i(100,100);
	glEnd();
	glFlush();  // Render now
}


/* Main function: GLUT runs as a console application starting at main()  */
void glut_put_pixel_example(int ac, char **av)
{
	glutInit(&ac, av);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowPosition(80, 80);
	glutInitWindowSize(500,500);

	glutCreateWindow("A Simple OpenGL Program");
	glutDisplayFunc(display);
	glutMainLoop();
}
