#include <GL/glut.h>
#include <windows.h>


void init() {

	glClearColor(1, 1, 1, 1);
	glMatrixMode(GL_PROJECTION);
	glOrtho(-50, 100, -50, 100, -50, 100);

}
void display() {

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 1);
	glLineWidth(4);
	
	
	//glutSolidSphere(5, 20, 20);
	//glutSolidTeapot(5);
	//glRectf(-10.75f, 10.75f, 10.75f, -10.75f);
	//glutSwapBuffers();
	/*
	
	 glBegin(GL_LINE_LOOP);
	glVertex2f(10.5f, 10.5f);
	glVertex2f(-10.5f, 10.5f);
	glVertex2f(-10.5f, -10.5f);
	glVertex2f(10.5f, -10.5f);
	glEnd();


	glBegin(GL_QUADS);
	glVertex2f(-20.25f, 20.25f); // vertex 1
	glVertex2f(-20.5f, -20.25f); // vertex 2
	glVertex2f(10.5f, -10.25f); // vertex 3
	glVertex2f(10.25f, 10.25f); // vertex 4
	glEnd();
	glutSwapBuffers();
	*/
	glBegin(GL_LINES);
	
	//desktop lines for vertical
	glVertex2i(-20, 70);
	glVertex2i(50, 70);
	glVertex2i(-20, 20);
	glVertex2i(50, 20);
	//desktop lines for horizontal
	glVertex2i(-20, 70);
	glVertex2i(-20, 20);
	glVertex2i(50, 70);
	glVertex2i(50, 20);
	//arm lines
	glVertex2i(10, 20);
	glVertex2i(10, 10);
	glVertex2i(20, 20);
	glVertex2i(20, 10);

	glVertex2i(10, 10);
	glVertex2i(20, 10);

	glVertex2i(0, 15);
	glVertex2i(0, 0);
	//horizontal close
	glVertex2i(30, 15);
	glVertex2i(30, 0);
	//vertical line one
	glVertex2i(0, 0);
	glVertex2i(30, 0);
	//vertical line two
	glVertex2i(20, 15);
	glVertex2i(30, 15);

	glVertex2i(0, 15);
	glVertex2i(10, 15);


	//keyboard lines
//keyboard vertical lines
	glVertex2i(-20, -5);
	glVertex2i(-20, -20);

	glVertex2i(50, -5);
	glVertex2i(50, -20);
	//keyboard horizontal lines
	glVertex2i(-20, -5);
	glVertex2i(50, -5);

	glVertex2i(-20, -20);
	glVertex2i(50, -20);
	//keyboard inside lines
	//horizontal lines
	glVertex2i(-20, -10);
	glVertex2i(50, -10);

	glVertex2i(-20, -15);
	glVertex2i(50, -15);
	//keyboard vertical lines
	glVertex2i(-15, -5);
	glVertex2i(-15, -20);
	glVertex2i(-10, -5);
	glVertex2i(-10, -20);
	glVertex2i(-5, -5);
	glVertex2i(-5, -20);
	glVertex2i(0, -5);
	glVertex2i(0, -20);
	glVertex2i(5, -5);
	glVertex2i(5, -20);
	glVertex2i(10, -5);
	glVertex2i(10, -20);
	glVertex2i(15, -5);
	glVertex2i(15, -20);
	glVertex2i(20, -5);
	glVertex2i(20, -20);
	glVertex2i(25, -5);
	glVertex2i(25, -20);
	glVertex2i(30, -5);
	glVertex2i(30, -20);
	glVertex2i(35, -5);
	glVertex2i(35, -20);
	glVertex2i(40, -5);
	glVertex2i(40, -20);
	glVertex2i(45, -5);
	glVertex2i(45, -20);
	//desktop inside lines
	//desktop inside vertical lines
	glVertex2i(-15, 65);
	glVertex2i(45, 65);
	glVertex2i(-15, 25);
	glVertex2i(45, 25);
	//desktop lines for horizontal
	glVertex2i(-15, 65);
	glVertex2i(-15, 25);
	glVertex2i(45, 65);
	glVertex2i(45, 25);


	//central processing unit liness
	glVertex2i(60, 70);
	glVertex2i(90, 70);
	glVertex2i(60, 0);
	glVertex2i(90, 0);
	//CPU lines for horizontal
	glVertex2i(60, 70);
	glVertex2i(60, 0);
	glVertex2i(90, 70);
	glVertex2i(90, 0);

	glVertex2i(60, 60);
	glVertex2i(90, 60);
	glVertex2i(60, 40);
	glVertex2i(90, 40);
	glVertex2i(60, 50);
	glVertex2i(90, 50);
	glEnd();
	/*
glBegin(GL_TRIANGLE_STRIP); // draw in triangle strips
glVertex2f(10.0f, 10.75f); // top of the roof
glVertex2f(-10.5f, 10.25f); // left corner of the roof
glVertex2f(20.5f, 20.25f); // right corner of the roof
glVertex2f(-10.5f, -10.5f); // bottom left corner of the house
glVertex2f(10.5f, -10.5f); //bottom right corner of the house
glEnd();
glutSwapBuffers();
	*/
	
	glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(600, 600);
	glutCreateWindow(" GRAPHICS DESKTOP");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
