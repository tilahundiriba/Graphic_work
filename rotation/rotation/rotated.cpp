
#include <windows.h>
#include <GL/glut.h>



void init() {

	glClearColor(0.7, 0.7, 0.7, 1);
	glMatrixMode(GL_PROJECTION);
	//glEnable(GL_DEPTH_TEST);
	glOrtho(-130, 200, -100, 100, -100, 100);

}
//display function
float angle = 0.0;
void display() {

	glClear(GL_COLOR_BUFFER_BIT );
	//glLoadIdentity();
	glColor3f(1, 0, 0);
	//trees stick using rectangle
	glPushMatrix();
	glColor3f(0.3, 0, 0);

	//glTranslatef(0.0, 10.0, 0.0);
	glRotatef(angle,0,0,1);
	glutSolidCone(28,50,10,10);

	glPopMatrix();

	
	glutSwapBuffers();
	//glFlush();
}
//void reshape(int w, int h) {
	//glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//gluOrtho2D(-20, 20, 20, -20);
	//glMatrixMode(GL_MODELVIEW);
//}
void timer(int w) {
	glutTimerFunc(1000 / 60, timer, 0);
	glutPostRedisplay();//calling reagain display function
	angle += 0.8;
	if (angle > 360.0)
		angle = angle - 360.0;
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE );
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Hilcoptor");
	glutTimerFunc(0,timer ,0);
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
