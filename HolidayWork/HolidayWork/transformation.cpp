
#include <windows.h>
#include <GL/glut.h>



void init() {

	glClearColor(0, 1, 1, 1);
	glMatrixMode(GL_PROJECTION);
	glOrtho(-50, 100, -50, 100, -50, 100);

}
//display function
void display() {

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	//translate to the Y direction
	//glTranslated(0, 5 ,0, 0);
	glutSolidCube(20);
	
	//glPushMatrix(); used to avoid translation and rotation to anthor object below the 
	//glPopMatrix();
	glPushMatrix();
	glTranslated(0, 20, 0);
	glColor3f(0, 1, 0);
	glRotatef(-90, 1, 0, 0);//rotation to the y axis by -90 degree
	glutSolidCone(10,10,20,20);
	glScalef(0.5,0.5,0.5);//scaling the object to increase the size
	glPopMatrix();
	//
	glPushMatrix();
	glColor3f(0, 0, 1);
	glTranslated(0, 0, 20);
	glutSolidCone(10, 10, 20, 20);//soild cone
	glPopMatrix();
	glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Transformation");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
