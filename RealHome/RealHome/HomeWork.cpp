
#include <windows.h>
#include <GL/glut.h>



void init() {

	glClearColor(0, 1, 1, 1);
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
/*
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
	*/
	//wall behind the bed 
	glColor3f(0, 1, 1);
	glBegin(GL_QUADS);
	glVertex2i(-40, 100);
	glVertex2i(90, 100);
	glVertex2i(90, 10);
	glVertex2i(-40, 10);


	glEnd();
	//floor bellow the bed
	glColor3f(0.5, 0.8, 0.5);
	glBegin(GL_QUADS);
	glVertex2i(-40, 10);
	glVertex2i(100, 10);
	glVertex2i(60, -50);
	glVertex2i(-80, -50);


	glEnd();
	glColor3f(0.1, 0.5, 0.3);
	glBegin(GL_QUADS);
	glVertex2i(-10, 80);
	glVertex2i(70, 80);
	glVertex2i(50, 50);
	glVertex2i(-30, 50);


	glEnd();
	//double bed for the top one
	glBegin(GL_QUADS);
	glVertex2i(-10, 85);
	glVertex2i(70, 85);
	glVertex2i(50, 55);
	glVertex2i(-30, 55);


	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);


	

	//the shortest lines
	glVertex2i(-10, 85);
	glVertex2i(-10, 90);
	//the 2shortest lines
	glVertex2i(-10, 50);
	glVertex2i(-10, 0);
	//bottom horizontal lines
	glVertex2i(-10, 90);
	glVertex2i(-30, 60);
	glVertex2i(70, 90);
	glVertex2i(50, 60);

	glEnd();
	//the bottom bed
	glColor3f(0.3, 0.3, 0.5);
	glBegin(GL_QUADS);
	glVertex2i(-10, 30);
	glVertex2i(70, 30);
	glVertex2i(50, 0);
	glVertex2i(-30, 0);


	glEnd();
	//the double bed for the bottom one
	glColor3f(0.3, 0.3, 0.5);
	glBegin(GL_QUADS);
	glVertex2i(-10, 35);
	glVertex2i(70, 35);
	glVertex2i(50, 5);
	glVertex2i(-30, 5);


	glEnd();
	//bottom left cover
	glColor3f(0.3, 0.3, 0.5);
	glBegin(GL_QUADS);
	glVertex2i(-30, 5);
	glVertex2i(-10, 5);
	glVertex2i(-10, 0);
	glVertex2i(-30, 0);


	glEnd();
	//top right cover
	glColor3f(0.1, 0.5, 0.3);
	glBegin(GL_QUADS);
	glVertex2i(70, 85);
	glVertex2i(65, 80);
	glVertex2i(65, 80);
	glVertex2i(70, 80);

	
	glEnd();
	//the top left cover
	glColor3f(0.1, 0.5, 0.3);
	glBegin(GL_QUADS);
	glVertex2i(-30, 50);
	glVertex2i(0, 50);
	glVertex2i(0, 55);
	glVertex2i(-30, 55);


	glEnd();
	//the bottom right cover
	glColor3f(0.3, 0.3, 0.5);
	glBegin(GL_QUADS);
	glVertex2i(70, 35);
	glVertex2i(65, 35);
	glVertex2i(65, 30);
	glVertex2i(70, 30);


	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2i(50, 60);
	glVertex2i(50, -30);
	glVertex2i(70, 90);
	glVertex2i(70, 0);
	glVertex2i(-30, 60);
	glVertex2i(-30, -30);
	glVertex2i(50, 0);
	glVertex2i(70, 30);

	glVertex2i(50, 50);
	glVertex2i(70, 80);
	glEnd();
	//the bottom horizontal lines
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2i(-30, 10);//starting horizontal lines of bottom left
	glVertex2i(-10, 40);//ending horizontal lines of bottom left
	glVertex2i(50, 10);//starting horizontal line of bottom right 
	glVertex2i(70, 40);//ending of horizontal line of bottom right
	
	//front horizontal bottom lines
	glVertex2i(-30, 0);
	glVertex2i(50, 0);
	//front horizontal top lines
	glVertex2i(-30, 50);
	glVertex2i(50, 50);
	
	glEnd();
	//lader lines
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2i(-20, 50);
	glVertex2i(-20, -20);//the left vertical lines of the lader end
	glVertex2i(0, 50);
	glVertex2i(0, -20);//the right vertical lines of the lader end
	glVertex2i(-20, -10);// the horizontal lines of the lader
	glVertex2i(0, -10);
	glVertex2i(-20, 10);
	glVertex2i(0, 10);
	glVertex2i(-20, 30);
	glVertex2i(0, 30);
	glEnd();
	glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(600, 600);
	glutCreateWindow("My dorm Bed!!");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
