
#include <windows.h>
#include <GL/glut.h>



void init() {

	glClearColor(0, 0, 1, 1);
	glMatrixMode(GL_PROJECTION);
	glOrtho(-50, 100, -50, 100, -50, 100);

}
void display() {

	glClear(GL_COLOR_BUFFER_BIT);
	
	glLineWidth(1000);
	
	//glutSolidSphere(10, 10, 70);
	//glutSolidTeapot(5);
	/*glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2i(10, 70);
	glVertex2i(10, 0);
	glColor3f(0, 1, 0);
	glVertex2i(10, 70);
	glVertex2i(30, 70);
	glColor3f(1, 1, 0);
	glVertex2i(10, 60);
	glVertex2i(30, 60);
	glColor3f(1, 0, 0);
	glVertex2i(10, 50);
	glVertex2i(30, 50);

	glEnd();*/

	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2i(10, 70);
	glVertex2i(10, -20);
	glVertex2i(0, -20);
	glVertex2i(20, -20);
	
	glEnd();

	
	//green color
	glColor3f(0, 1, 0);
	glBegin(GL_QUADS);
	glVertex2i(10, 70);
	glVertex2i(60, 70);
	glVertex2i(60, 50);
	glVertex2i(10, 50);
	

	glEnd();
	//yellow color
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex2i(10, 50);
	glVertex2i(60, 50);
	glVertex2i(60, 30);
	glVertex2i(10, 30);


	glEnd();
	//red color
	glColor3f(1, 0, 0);
	glBegin(GL_QUADS);
	glVertex2i(10, 30);
	glVertex2i(60, 30);
	glVertex2i(60, 10);
	glVertex2i(10, 10);


	glEnd();
	


	glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(600, 600);
	glutCreateWindow("FRIST GRAPHICS HOME");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
