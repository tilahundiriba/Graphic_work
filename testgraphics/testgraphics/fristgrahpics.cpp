#include <GL/glut.h>
#include <windows.h>

void init() {

	glClearColor(1, 0, 0, 1);
	glMatrixMode(GL_PROJECTION);
	glOrtho(-10, 10, -10, 10, -10, 10);

}
void display() {

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 1);
	//glutSolidSphere(5, 20, 20);
	glutSolidTeapot(5);
	glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(600, 600);
	glutCreateWindow("FRIST GRAPHICS");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
