
#include <windows.h>
#include <GL/glut.h>



void init() {

	glClearColor(0.7, 0.7, 0.7, 1);
	glMatrixMode(GL_PROJECTION);
	//glEnable(GL_DEPTH_TEST);
	glOrtho(-200, 300, -200, 200, -200, 200);

}
//display function
float tx = 0.0;
float ty = 0.0;
void display() {

	glClear(GL_COLOR_BUFFER_BIT);
	//glLoadIdentity();
	glColor3f(1, 0, 0);
	//trees stick using rectangle
	glPushMatrix();
	glColor3f(0.3, 0, 0);
	glTranslatef(tx, ty, 0);
	glutSolidCube(30);

	glPopMatrix();


	//glutSwapBuffers();
	glFlush();
}
void timer( unsigned char key, int x, int y) {	
	switch (key) {
	case 'a':
	case 'A':
		ty += 0.5;
		break;
	case 'w':
	case 'W':
		tx += 0.5;
		break;
	case 's':
	case 'S':
		tx -= 0.5;
		break;
	case 'd':
	case 'D':
		ty -= 0.5;
		break;
	default:
		break;
	}
	glutPostRedisplay();//calling reagain display function
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(600, 600);
	glutCreateWindow("CubeUsing Keyboad Handler");
	//glutTimerFunc(0, timer, 0);
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(timer);
	//glutIdleFunc(timer);
	glutMainLoop();
	return 0;
}
