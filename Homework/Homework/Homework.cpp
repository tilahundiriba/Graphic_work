
#include <windows.h>
#include <GL/glut.h>



void init() {

	glClearColor(0.7, 0.7, 0.7, 1);//set the background color for the window
	glMatrixMode(GL_PROJECTION);//set projection type
	glOrtho(-130, 200, -200, 200, -200, 200);//set the range of the displaying window 

}
//display function
float angle = 0.0;
void display() {

	glClear(GL_COLOR_BUFFER_BIT);//clear the screen befor the drawing an image
	glColor3f(1, 0, 0);//setting color for the drawing objects
	//trees stick using rectangle
	//glTranslated(0, 100, 0);
	glPushMatrix();
	glPushMatrix();
	glColor3f(0.3, 0, 0);
	glRecti(-30, 15, -40, 0);
	glRecti(-95, 15, -85, 0);
	glRecti(30, 15, 40, 0);
	glRecti(170, 15, 180, 0);
	glRecti(100, 15, 110, 0);
	glPopMatrix();
	//trees leaves using solidcone
	glPushMatrix();
	glColor3f(0, 0.4, 0);
	glTranslated(105, 15, 0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(20, 30, 20, 20);
	//
	glPopMatrix();
	glPushMatrix();
	glColor3f(0, 0.4, 0);
	glTranslated(175, 15, 0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(20, 30, 20, 20);
	glPopMatrix();
	//
	glPushMatrix();
	glColor3f(0, 0.4, 0);
	glTranslated(105, 25, 0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(20, 30, 20, 20);
	glPopMatrix();
	//
	glPushMatrix();
	glColor3f(0, 0.4, 0);
	glTranslated(175, 25, 0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(20, 30, 20, 20);
	glPopMatrix();
	//
	glPushMatrix();
	glColor3f(0, 0.4, 0);
	glTranslated(-90, 15, 0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(20, 30, 20, 20);
	glPopMatrix();
	//
	glPushMatrix();
	glColor3f(0, 0.4, 0);
	glTranslated(-90, 25, 0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(20, 30, 20, 20);
	glPopMatrix();
	//
	glPushMatrix();
	glColor3f(0, 0.4, 0);
	glTranslated(35, 15, 0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(20, 30, 20, 20);
	glPopMatrix();
	//
	glPushMatrix();
	glColor3f(0, 0.4, 0);
	glTranslated(35, 25, 0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(20, 30, 20, 20);
	glPopMatrix();
	//
	glPushMatrix();
	glColor3f(0, 0.4, 0);
	glTranslated(-35, 15, 0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(20, 30, 20, 20);
	glPopMatrix();
	//
	glPushMatrix();
	glColor3f(0, 0.4, 0);
	glTranslated(-35, 25, 0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(20, 30, 20, 20);
	glPopMatrix();


	//starting rectangle for the objec
	glPushMatrix();
	//glTranslated(0, 150, 0);
	glPushMatrix();
	glColor3f(0.5, 0, 0);
	glRecti(-30, 50, 50, 10);
	
	glPopMatrix();
	//the first sphere for front side
	glPushMatrix();
	glColor3f(0.5, 0, 0);
	glTranslated(-30, 40, 0);
	glutSolidSphere(10, 20, 20);
	glPopMatrix();
	//the second sphere for front side
	glPushMatrix();
	glColor3f(0.5, 0, 0);
	glTranslated(-40, 30, 0);
	glutSolidSphere(15, 30, 30);
	
	glPopMatrix();
	//the thrid sphere for front side
	glPushMatrix();
	glColor3f(0.5, 0, 0);
	glTranslated(-50, 20, 0);
	glutSolidSphere(15, 30, 30);

	glPopMatrix();
	//the bottom rectangle
	glRecti(-50, 20, 70, 5);

	//the rear spheres
	glPopMatrix();
	//the first sphere for rear side
	glPushMatrix();
	glColor3f(0.5,0,0);
	glTranslated(50, 40, 0);
	glutSolidSphere(10, 20, 20);
	glPopMatrix();
	//the second sphere for rear side
	glPushMatrix();
	glColor3f(0.5, 0, 0);
	glTranslated(55, 30, 0);
	glutSolidSphere(15, 30, 30);

	glPopMatrix();
	//the thrid sphere for rear side
	glPushMatrix();
	glColor3f(0.5, 0, 0);
	glTranslated(65, 20, 0);
	glutSolidSphere(15, 30, 30);

	glPopMatrix();

	//the fouth sphere for rear side
	glPushMatrix();
	glColor3f(0.5, 0, 0);
	glTranslated(75, 15, 0);
	glutSolidSphere(10, 20, 20);

	glPopMatrix();
	glPushMatrix();
	glColor3f(0.5, 0, 0);
	glTranslated(-60, 15, 0);
	glutSolidSphere(10, 20, 20);

	glPopMatrix();
	glColor3f(0, 0.5, 0);
	glRectf(-150, 0, 200, -200);//the green one rectangle 
	glColor3f(0.5, 0, 0);
	glRecti(0, 70, 10, 50);//for vertical holder
	glRecti(-45, 73, 65, 70);//for the top cross
	glRecti(70, 15, 150, 5);//for the tail 
	glRecti(140, 35, 150, 5);// vertical holder for the tail
	glPushMatrix();
	//glTranslatef(140.0,35.0,0.0);
	//glRotatef(angle,0, 10, 0);
	//glTranslatef(115.0, 35.0, 0.0);
	//glutSolidSphere(20, 10, 10);
	glRecti(115, 38, 175, 35);// cross for the tail
	
	glPopMatrix();
	//lines for a legs 
	glLineWidth(15);
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	//the vertical lines of legs for the front side
	glVertex2i(-40, 5);
	glVertex2i(-60, -20);
	glVertex2i(40, 5);
	glVertex2i(60, -20);
	// lines for the rear side legs
	glVertex2i(-30, 5);
	glVertex2i(-20, -10);
	glVertex2i(50, 5);
	glVertex2i(65, -10);
	
	glEnd();
	glRectf(-58, -15, 58, -20);//rectangle for horizontal leg
	glRectf(-22, -5, 62.5, -10);//rectangle for the rear side horizontal leg

	glRectf(-70, -30, 100, -90);//the stage for stop
	glColor3f(1, 1, 1);
	glRectf(-30, -40, 30, -50);//the horizontal lines for stop indecation
	glRectf(-30, -70, 30, -80);
	//the vertical line for stopping stage
	glRectf(0, -40, 10, -80);
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_QUADS);//windows 
	glVertex2i(-35,45);
	glVertex2i(40, 45);
	glVertex2i(50, 30);
	glVertex2i(-50, 30);
	glEnd();
	glLineWidth(2);
	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_LINES);//windows 
	glVertex2i(-30, 45);
	glVertex2i(-30, 30);
	glVertex2i(-10, 45);
	glVertex2i(-10, 30);
	glVertex2i(10, 45);
	glVertex2i(10, 30);
	glVertex2i(30, 45);
	glVertex2i(30, 30);
	glEnd();
	glBegin(GL_QUADS);//windows 
	glVertex2i(-30, 40);
	glVertex2i(44, 40);
	glVertex2i(50, 30);
	glVertex2i(-30, 30);
	glEnd();
	glPopMatrix();
	glPopMatrix();
	glutSwapBuffers();//used to display the drawing on the screen
//	glFlush();
}
void timer() {
	//glutTimerFunc(1000 / 60, timer, 0);
	
	angle += 0.8;
	//if (angle > 360.0)
		//angle = angle - 360.0;
	glutPostRedisplay();//calling reagain display function
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);//initialize glut library
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);//initialize display mode
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Hilcoptor");

	init();	
	//glutTimerFunc(0, timer, 0);
	glutDisplayFunc(display);
	glutIdleFunc(timer);
	glutMainLoop();
	return 0;
}
