
#include <windows.h>
#include <GL/glut.h>



void init() {

	glClearColor(1, 0, 0, 1);
	glMatrixMode(GL_PROJECTION);
	glOrtho(-50, 100, -50, 100, -50, 100);

}
void display() {

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 1);
	glLineWidth(5);
	//glutSolidSphere(5, 20, 20);
	//glutSolidTeapot(5);
	glBegin(GL_LINES);
	glVertex2i(-20, 50);
	glVertex2i(50, 50);
	
	glVertex2i(50, 50);
	glVertex2i(40, 30);

	glVertex2i(50, 50);
	glVertex2i(60, 40);

	glVertex2i(60, 40);
	glVertex2i(40, 30);

	glVertex2i(-20, 50);
	glVertex2i(-35, 30);

	
	glVertex2i(-35, 30);
	glVertex2i(40, 30);

	glVertex2i(-30, 30);
	glVertex2i(-30, 0);

	glVertex2i(35, 30);
	glVertex2i(35, 0);

	glVertex2i(-30, 0);
	glVertex2i(35, 0);

	glVertex2i(55, 37);
	glVertex2i(55, 10);

	glVertex2i(55, 10);
	glVertex2i(35, 0);
	//door lines
	glVertex2i(-20, 0);
	glVertex2i(-20, 20);

	glVertex2i(-10, 0);
	glVertex2i(-10, 20);

	glVertex2i(-20, 20);
	glVertex2i(-10, 20);
	//windows line 
	glVertex2i(10, 20);
	glVertex2i(10, 10);

	glVertex2i(20, 20);
	glVertex2i(20, 10);

	glVertex2i(10, 10);
	glVertex2i(20, 10);

	glVertex2i(10, 20);
	glVertex2i(20, 20);
	//widows inside lines
	glVertex2i(10, 15);
	glVertex2i(20, 15);
	glVertex2i(15, 20);
	glVertex2i(15, 10);

	//door inside lines
	glVertex2i(-17, 0);
	glVertex2i(-17, 20);
	glVertex2i(-14, 0);
	glVertex2i(-14, 20);
	glVertex2i(-20, 18);
	glVertex2i(-10, 18);
	glVertex2i(-20, 12);
	glVertex2i(-10, 12);
	glVertex2i(-20, 6);
	glVertex2i(-10, 6);
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
