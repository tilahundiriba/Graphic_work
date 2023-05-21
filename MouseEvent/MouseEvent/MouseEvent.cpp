#include <GL/glew.h>
#include <windows.h>
#include <GL/glut.h>




void init() {

	glClearColor(0.7, 0.7, 0.7, 1);//set the background color for the window
	glMatrixMode(GL_PROJECTION);//set projection type
	glOrtho(-100, 100, -100, 100, -100, 100);//set the range of the displaying window 

}
//display function
float tx = 0.0;
float angle = 0.0;
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glPushMatrix();
	glTranslatef(tx, 0, 0);
	//glRotatef(angle, 0, 0, 1);
	glutSolidCube(20);
	glPopMatrix();
		glFlush();
}

void mouseEvent(int button, int state, int x, int y) {

	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		tx -= 0.5;
		angle -= 10;
		break;
	case GLUT_RIGHT_BUTTON:
		tx += 0.5;
		angle += 10;
		break;
	default:
		break;
	}
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);//initialize glut library
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);//initialize display mode
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(600, 600);
	glutCreateWindow("MouseEvent");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(mouseEvent);
	glutMainLoop();
	return 0;
}
