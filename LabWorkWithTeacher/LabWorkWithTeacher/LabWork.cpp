
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
int state = 1;
void display() {

	glClear(GL_COLOR_BUFFER_BIT);
	//glLoadIdentity();
	glColor3f(1, 0, 0);
	//trees stick using rectangle
	glPushMatrix();
	glColor3f(0.3, 0, 0);
	//glRotatef(angle, 0, 0, 1);
	glTranslatef(tx,0,0);
	//glutSolidCube(20);
	glRectf(-20, 40, 20, 20);
	glRectf(-60, 0, 80, 20);
	glBegin(GL_TRIANGLES);
	glVertex2i(-60,20);

	glVertex2i(-20, 20);
	glVertex2i(-20, 40);
		glEnd();
		glBegin(GL_TRIANGLES);
		glColor3f(1,0,0);
		glVertex2i(20, 40);
		glColor3f(0, 1, 0);
		glVertex2i(20, 20);
		glColor3f(0, 0, 1);
		glVertex2i(60, 20);
		glEnd();
		glPushMatrix();
		glColor3f(0, 0, 0);
		glTranslatef(-40, 0, 0);
		glutSolidCone(10, 5, 50,50);
		glPopMatrix();
		glPushMatrix();
		glColor3f(0,0,0);
		glTranslatef(40, 0, 0);
		glutSolidCone(10.5, 4, 20,20);
		glPopMatrix();

	glPopMatrix();

	
	//glutSwapBuffers();
	glFlush();
}
void timer() {
	//glutTimerFunc(1000 / 60, timer, 0);
	glutPostRedisplay();//calling reagain display function
/*	//if (tx < 320.0)
	//	tx = tx += 0.05;
	//else if(tx >0)
	{
		tx = 320;
		tx -= 0.05;

	}
	*/
	switch (state) {
	case 1:
		if (tx < 320)
			tx += 0.15;
		else
			state = -1;
		break;
	case -1:
		if (tx > -200)
			tx -= 0.15;
		else
			state = 1;
		break;
	}
		
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Cube");
	//glutTimerFunc(0, timer, 0);
	init();
	glutDisplayFunc(display);
	glutIdleFunc(timer);
	glutMainLoop();
	return 0;
}
