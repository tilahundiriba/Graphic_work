
#include <windows.h>
#include <GL/glut.h>



void init() {

	glClearColor(0, 1, 1, 1);
	glMatrixMode(GL_PROJECTION);
	glOrtho(-50, 100, -50, 100, -50, 100);

}
void display() {

	glClear(GL_COLOR_BUFFER_BIT);
	/*
	glEnable(GL_LINE_STIPPLE);//enabling gl stipple
	glLineStipple(15, 0x1111);//factor and pattern the value of factor is integar
	//the value of pattern is hezdecimal
	glLineWidth(1000);

	
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2i(-20, 50);
	glVertex2i(50, 50);//the broken line 

	glEnd();

	glRasterPos2i(0, 60);//position for the first characters
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'C');//adding character to the project
	glRasterPos2i(5, 60);//position for the second characters
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'S');
	//the second solid lines
	glDisable(GL_LINE_STIPPLE);//disabling the gl line stipple
	glBegin(GL_LINES);
	glVertex2i(-20, 30);
	glVertex2i(50, 30);

	glEnd();
	*/
	//triangle
	
	glLineWidth(10);
	glBegin(GL_TRIANGLES);//color full triangle
	glColor3f(1, 0, 0);
	glVertex2i(-20, 0);
	glColor3f(0, 0, 1);
	glVertex2i(20, 50);//the red line 
	glColor3f(0, 1, 0);
	glVertex2i(20, 0);

	glEnd();
	
	glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Broken AND Solid Lines!!");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
