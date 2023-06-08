#include<windows.h>
#include<gl/glut.h>
#include<math.h>
#include<iostream>
using namespace std;


float tx1m = 1120.0;
float ty1m= 430.0;
float tx2m = 1150.0;
float ty2m = 430.0;

float suntx = -600.0;
float sunty = 600.0;

void init() {
	glClearColor(1, 1, 1, 0);
	glMatrixMode(GL_PROJECTION);
glOrtho(-280, 560, -200, 600, -300, 300);
	//glOrtho(-60, 40, -60, 120, -50, 50);
//gluPerspective(60, 1, 0.01, 1000);
	//gluLookAt(1, 0, 1000, 0, 0, 0, 0, 10, 0);
/*
GLfloat mat_ambient[] = { 0.4, 0.4, 0.4, 1.0 };
GLfloat mat_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
GLfloat mat_specular[] = { 1.0, 0.0, 0.0, 1.0 };
GLfloat mat_shininess[] = { 100.0 };

glShadeModel(GL_SMOOTH);

glEnable(GL_LIGHTING);

glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
glLightfv(GL_LIGHT0, GL_POSITION, light_position);

glEnable(GL_DEPTH_TEST);
*/
}/*
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-1.5, 1.5, -1.5 * (GLfloat)h / (GLfloat)w,
			1.5 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
	else
		glOrtho(-1.5 * (GLfloat)w / (GLfloat)h,
			1.5 * (GLfloat)w / (GLfloat)h, -1.5, 1.5, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void keyboard(unsigned char key, int x, int y)
{
	if (key == '1')
	{
		// Toggle the state of light 0
		
			glEnable(GL_LIGHT0);
			//glDisable(GL_LIGHT0);
		glutPostRedisplay(); // Mark the window for redisplay


	}


}*/
void timer(int w) {
	glutTimerFunc(1000 / 60, timer, 0);
	
	if ((suntx <= 1200) && (sunty <= 1000)) {
		suntx += 0.2;
		sunty += 0.2;

	}
	else if ((sunty >= 1000)) {

		suntx += 0.2;
		sunty -= 0.2;

	}
	else {

		suntx =-600 ;
		sunty = 600;

	}
	
	glutPostRedisplay();//calling reagain display function
	
}

void timer2(int w) {
	glutTimerFunc(1000 / 60, timer2, 0);
	if ((tx1m && tx2m >= 980) && (ty1m && tx2m >= -100)) {
		tx1m -= 0.3;
		ty1m -= 0.4;
		tx2m -= 0.3;
		ty2m -= 0.4;

	}

	else if ((tx1m && tx2m >= 350) && (ty1m && tx2m >= -100)) {

		tx1m -= 0.4;
		ty1m -= 0.35;

		tx2m -= 0.4;
		ty2m -= 0.35;


	}
	else if ((ty1m && ty2m <= 50)) {
		ty1m += 0.4;
		tx1m -= 0.22;
		ty2m += 0.4;
		tx2m -= 0.22;


	}
	else {

		tx1m = 1120;
		ty1m = 430;
		tx2m = 1150;
		ty2m = 430;

	}

	
	//

	glutPostRedisplay();//calling reagain display function
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//the base house
	//the left most cylinder
	glPushMatrix();
	
	glScalef(0.5,0.5,0);
	// Enable fog

	glBegin(GL_QUADS);
	//the sky color
	glColor3f(1, 1, 1);
	glVertex2i(-600,400);
	glColor3f(0.1, 0.5, 1);
	glVertex2i(-600, 1300);
	glColor3f(0.1, 0.5, 1);
	glVertex2i(1400, 1300);
	glColor3f(1, 1, 1);
	glVertex2i(1400, 400);

	glColor3f(0, 0.5, 0);
	glVertex2i(-600, 400);
	glVertex2i(-600, -600);
	glVertex2i(1400, -600);
	glVertex2i(1400, 400);
	glEnd();
	
	//sun
	glPushMatrix();
	glTranslatef(suntx, sunty, 0);
	glColor3f(1, 1, 0);
	glutSolidSphere(20, 40, 40);
	glPopMatrix();
	//cluods
	glPushMatrix();
	glTranslatef(-500, 1000, 0);
	glColor3f(1, 1, 1);
	glutSolidSphere(60, 40, 40);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-500, 950, 0);
	glColor3f(1, 1, 1);
	glutSolidSphere(60, 40, 40);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-450, 980, 0);
	glColor3f(1, 1, 1);
	glutSolidSphere(60, 40, 40);
	glPopMatrix();
	//
	glPushMatrix();
	glTranslatef(100, 1050, 0);
	glColor3f(1, 1, 1);
	glutSolidSphere(60, 40, 40);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(100, 1100, 0);
	glColor3f(1, 1, 1);
	glutSolidSphere(60, 40, 40);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(150, 1100, 0);
	glColor3f(1, 1, 1);
	glutSolidSphere(60, 40, 40);
	glPopMatrix();
	
	//
	glPushMatrix();
	glTranslatef(700, 750, 0);
	glColor3f(1, 1, 1);
	glutSolidSphere(60, 40, 40);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(700, 700, 0);
	glColor3f(1, 1, 1);
	glutSolidSphere(60, 40, 40);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(750, 700, 0);
	glColor3f(1, 1, 1);
	glutSolidSphere(60, 40, 40);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(750, 780, 0);
	glColor3f(1, 1, 1);
	glutSolidSphere(60, 40, 40);
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(0.4, 0.2, 0.1);
	glTranslatef(-420, 800, 0);
	glRotatef(60, 1, 0, 0);
	glBegin(GL_POLYGON);
	GLUquadricObj* obj = gluNewQuadric();
	gluCylinder(obj, 30.0, 40, 810, 100, 100);
	glEnd();
	glPopMatrix();

	//trees1

	glPushMatrix();
	glColor3f(0.280, 0.134, 0.0140);
	glTranslatef(320, 420, 0);
	glRotatef(60, 1, 0, 0);
	glBegin(GL_POLYGON);
	GLUquadricObj* objtr1 = gluNewQuadric();
	gluCylinder(objtr1, 10.0, 10, 70, 200, 100);
	glEnd();
	glPopMatrix();
	// cone on it
	glPushMatrix();
	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(320, 420, 0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(40, 100, 40, 40);
	glPopMatrix();
	// cone on top 
	glPushMatrix();
	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(320, 450, 0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(40, 100, 40, 40);
	glPopMatrix();
	//trees2

	glPushMatrix();
	glColor3f(0.280, 0.134, 0.0140);
	glTranslatef(490, 420, 0);
	glRotatef(60, 1, 0, 0);
	glBegin(GL_POLYGON);
	GLUquadricObj* objtr2 = gluNewQuadric();
	gluCylinder(objtr2, 10.0, 10, 70, 200, 100);
	glEnd();
	glPopMatrix();
	// cone on it
	glPushMatrix();
	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(490, 420, 0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(40, 100, 40, 40);
	glPopMatrix();
	// cone on top 
	glPushMatrix();
	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(490, 450, 0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(40, 100, 40, 40);
	glPopMatrix();
	//trees3

	glPushMatrix();
	glColor3f(0.280, 0.134, 0.0140);
	glTranslatef(720, 420, 0);
	glRotatef(60, 1, 0, 0);
	glBegin(GL_POLYGON);
	GLUquadricObj* objtr3 = gluNewQuadric();
	gluCylinder(objtr3, 10.0, 10, 70, 200, 100);
	glEnd();
	glPopMatrix();
	// cone on it
	glPushMatrix();
	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(720, 420, 0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(40, 100, 40, 40);
	glPopMatrix();
	// cone on top 
	glPushMatrix();
	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(720, 450, 0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(40, 100, 40, 40);
	glPopMatrix();
	//trees4

	glPushMatrix();
	glColor3f(0.280, 0.134, 0.0140);
	glTranslatef(920, 420, 0);
	glRotatef(60, 1, 0, 0);
	glBegin(GL_POLYGON);
	GLUquadricObj* objtr4 = gluNewQuadric();
	gluCylinder(objtr4, 10.0, 10, 70, 200, 100);
	glEnd();
	glPopMatrix();
	// cone on it
	glPushMatrix();
	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(920, 420, 0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(40, 100, 40, 40);
	glPopMatrix();
	// cone on top 
	glPushMatrix();
	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(920, 450, 0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(40, 100, 40, 40);
	glPopMatrix();
	//trees5 the left one

	glPushMatrix();
	glColor3f(0.280, 0.134, 0.0140);
	glTranslatef(-510, 420, 0);
	glRotatef(60, 1, 0, 0);
	glBegin(GL_POLYGON);
	GLUquadricObj* objtr5 = gluNewQuadric();
	gluCylinder(objtr5, 10.0, 10, 70, 200, 100);
	glEnd();
	glPopMatrix();
	// cone on it
	glPushMatrix();
	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(-510, 420, 0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(50, 150, 40, 40);
	glPopMatrix();
	// cone on top 
	glPushMatrix();
	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(-510, 450, 0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(50, 150, 40, 40);
	glPopMatrix();
	// cone on top 
	glPushMatrix();
	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(-510, 480, 0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(50, 150, 40, 40);
	glPopMatrix();
	//the top rectangle from the front side and left side
	glBegin(GL_QUADS);
	//the background sarface purple color
	glColor3f(0.370, 0.187, 0.0370);
	glVertex2i(-390, 450);
	glVertex2i(-390, 730);
	glVertex2i(-50, 710);
	glVertex2i(-50, 450);
	//quad for the rear side zigzag one from left most
	glColor3f(0.3, 0.2, 0.2);
	glVertex2i(-390, 730);
	glVertex2i(-390, 780);
	glVertex2i(-370, 780);
	glVertex2i(-370, 730);
	//it's curve
	glVertex2i(-390, 780);
	glVertex2i(-383, 795);
	glVertex2i(-377, 795);
	glVertex2i(-370, 780);
	//quad for the rear side zigzag two from left most
	glColor3f(0.3, 0.2, 0.2);
	glVertex2i(-355, 728);
	glVertex2i(-355, 780);
	glVertex2i(-335, 780);
	glVertex2i(-335, 725);
	//it's curve
	glVertex2i(-355, 780);
	glVertex2i(-348, 795);
	glVertex2i(-342, 795);
	glVertex2i(-335, 780);
	//quad for the rear side zigzag thrid from left most
	glColor3f(0.3, 0.2, 0.2);
	glVertex2i(-225, 728);
	glVertex2i(-225, 780);
	glVertex2i(-205, 780);
	glVertex2i(-205, 725);
	//it's curve
	glVertex2i(-225, 780);
	glVertex2i(-218, 795);
	glVertex2i(-212, 795);
	glVertex2i(-205, 780);
	//quad for the rear side zigzag fourth from left most
	glColor3f(0.3, 0.2, 0.2);
	glVertex2i(-185, 718);
	glVertex2i(-185, 770);
	glVertex2i(-166, 770);
	glVertex2i(-166, 718);
	//it's curve
	glVertex2i(-185, 770);
	glVertex2i(-178, 785);
	glVertex2i(-172, 785);
	glVertex2i(-166, 770);
	//quad for the rear side zigzag fifth from left most
	glColor3f(0.3, 0.2, 0.2);
	glVertex2i(-146, 714);
	glVertex2i(-146, 765);
	glVertex2i(-126, 765);
	glVertex2i(-126, 714);
	//it's curve
	glVertex2i(-146, 765);
	glVertex2i(-139, 782);
	glVertex2i(-133, 782);
	glVertex2i(-126, 765);
	//quad for the rear side zigzag sixth from left most
	glColor3f(0.3, 0.2, 0.2);
	glVertex2i(-100, 712);
	glVertex2i(-100, 760);
	glVertex2i(-80, 760);
	glVertex2i(-80, 712);
	//it's curve
	glVertex2i(-100, 760);
	glVertex2i(-93, 780);
	glVertex2i(-87, 780);
	glVertex2i(-80, 760);
	//quad for the mama right side zigzag first from most 
	glColor3f(0.3, 0.2, 0.2);
	glVertex2i(40, 650);
	glVertex2i(40, 720);
	glVertex2i(55, 710);
	glVertex2i(55, 650);
	//it's curve
	glVertex2i(40, 720);
	glVertex2i(44, 740);
	glVertex2i(51, 740);
	glVertex2i(55, 710);
	//quad for the mama right side zigzag second from most 
	glColor3f(0.3, 0.2, 0.2);
	glVertex2i(60, 650);
	glVertex2i(60, 700);
	glVertex2i(75, 690);
	glVertex2i(75, 630);
	//it's curve
	glVertex2i(60, 700);
	glVertex2i(64, 720);
	glVertex2i(71, 720);
	glVertex2i(75, 690);
	//front side of top mama wall
	glColor3f(0.4, 0.2, 0.1);
	glVertex2i(-10, 600);
	glVertex2i(-10, 850);
	glVertex2i(35, 850);
	glVertex2i(35, 600);

	//the right side view for the top 
	glColor3f(0.3, 0.2, 0.2);
	glVertex2i(35, 600);
	glVertex2i(35, 680);
	glVertex2i(85, 620);
	glVertex2i(85, 600);
	//the top rectangle the left one
	glColor3f(0.3, 0.2, 0.2);
	glVertex2i(-50, 600);
	glVertex2i(-50, 860);
	glVertex2i(-10, 850);
	glVertex2i(-10, 600);
	//the top cover of it
	glColor3f(0.2, 0.2, 0.2);
	glVertex2i(-50, 860);
	glVertex2i(-10, 865);
	glVertex2i(35, 850);
	glVertex2i(-10, 850);
	//it's top sharps
	glColor3f(0.4, 0.2, 0.1);
	glVertex2i(-50, 860);
	glVertex2i(-50, 885);
	glVertex2i(-45, 885);
	glVertex2i(-45, 858);

	glVertex2i(-40, 857);
	glVertex2i(-40, 880);
	glVertex2i(-35, 880);
	glVertex2i(-35, 855);

	glVertex2i(-30, 855);
	glVertex2i(-30, 880);
	glVertex2i(-25, 880);
	glVertex2i(-25, 853);

	glVertex2i(-20, 852);
	glVertex2i(-20, 880);
	glVertex2i(-15, 880);
	glVertex2i(-15, 850);
	//the left sharps
	glVertex2i(-10, 850);
	glVertex2i(-10, 882);
	glVertex2i(-5, 880);
	glVertex2i(-5, 850);

	glVertex2i(0, 850);
	glVertex2i(0, 882);
	glVertex2i(5, 880);
	glVertex2i(5, 850);

	glVertex2i(10, 850);
	glVertex2i(10, 882);
	glVertex2i(15, 880);
	glVertex2i(15, 850);

	glVertex2i(20, 850);
	glVertex2i(20, 882);
	glVertex2i(25, 880);
	glVertex2i(25, 850);

	glVertex2i(30, 850);
	glVertex2i(30, 882);
	glVertex2i(35, 880);
	glVertex2i(35, 850);
	//the field///////////////
	glColor3f(0.3, 0.318, 0.318);
	glVertex2i(170, -30);//start
	glVertex2i(170, 150);//top
	glVertex2i(500, 120);//2top
	glVertex2i(500, -80);//end
	//the field door first///////////////
	glColor3f(0.440, 0.387, 0.387);
	glVertex2i(500, -90);//start
	glVertex2i(490, 380);//top
	glVertex2i(560, 350);//2top
	glVertex2i(570, -140);//end
	//the front side look of the door
	glColor3f(0.510, 0.439, 0.439);
	glVertex2i(570, -140);//start
	glVertex2i(560, 350);//top
	glVertex2i(580, 360);//2top
	glVertex2i(590, -120);//end
	//it's top view
	glColor3f(0.610, 0.537, 0.537);
	glVertex2i(505, 390);//start
	glVertex2i(580, 360);//top
	glVertex2i(560, 350);//2top
	glVertex2i(490, 380);//end


	glEnd();
	glLineWidth(4);
	glBegin(GL_LINES);
	glColor3f(0.1, 0.1, 0.1);
	//the top mama front and left side strip
	//the widest line for the top mama strip 
	glVertex2i(50, 600);
	glVertex2i(-10, 750);

	glVertex2i(-10, 750);
	glVertex2i(-50, 830);
	glEnd();
	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3f(0.1, 0.1, 0.1);
	glVertex2i(50, 630);
	glVertex2i(-10, 780);

	glVertex2i(-10, 780);
	glVertex2i(-50, 860);
	//there vertical line
	glVertex2i(-50, 860);
	glVertex2i(-50, 830);

	glVertex2i(-45, 850);
	glVertex2i(-45, 820);

	glVertex2i(-35, 830);
	glVertex2i(-35, 800);

	glVertex2i(-25, 810);
	glVertex2i(-25, 780);

	glVertex2i(-15, 790);
	glVertex2i(-15, 760);

	glVertex2i(-5, 770);
	glVertex2i(-5, 740);

	glVertex2i(5, 740);
	glVertex2i(5, 710);

	glVertex2i(15, 720);
	glVertex2i(15, 690);


	glVertex2i(25, 695);
	glVertex2i(25, 660);

	glVertex2i(35, 670);
	glVertex2i(35, 640);
	glEnd();
	//the right most cylinder
	glColor3f(0.4, 0.2, 0.1);
	glPushMatrix();
	glTranslatef(130, 750, 0);
	glRotatef(60, 1, 0, 0);

	glBegin(GL_POLYGON);
	GLUquadricObj* obj2 = gluNewQuadric();
	gluCylinder(obj2, 45.0, 55, 850, 100, 100);
	glEnd();
	glPopMatrix();


	glBegin(GL_QUADS);
	glColor3f(0.4, 0.3, 0.2);
	glVertex2i(-300, 0);
	glVertex2i(-300, 600);
	glVertex2i(100, 600);
	glVertex2i(100, 0);
	//the left side view of wall
	glColor3f(0.4, 0.3, 0.2);
	glVertex2i(-300, 0);
	glVertex2i(-300, 600);
	glVertex2i(-400, 700);
	glVertex2i(-400, 120);

	//the left most for left side wall doors
	glColor3f(0.1, 0.1, 0.1);
	glVertex2i(-395, 210);
	glVertex2i(-395, 310);
	glVertex2i(-385, 300);
	glVertex2i(-385, 190);

	//the right most for left side wall doors
	glColor3f(0.1, 0.1, 0.1);
	glVertex2i(-370, 250);
	glVertex2i(-370, 370);
	glVertex2i(-355, 360);
	glVertex2i(-355, 230);

	//the strip for the left side doors
	glColor3f(0.170, 0.116, 0.116);
	glVertex2i(-430, 170);
	glVertex2i(-375, 250);
	glVertex2i(-350, 220);
	glVertex2i(-330, 70);

	//the top the left side ground house
	glColor3f(0.510, 0.469, 0.469);
	glVertex2i(-630, 100);//start
	glVertex2i(-410, 190);//top
	glVertex2i(-340, 110);//2top
	glVertex2i(-600, 0);//end
	//the front side ground house
	glColor3f(0.300, 0.182, 0.0270);
	glVertex2i(-590, -230);//start
	glVertex2i(-590, 5);//top
	glVertex2i(-330, 130);//2top
	glVertex2i(-330, -10);//end
	
//the most left middle window
	glColor3f(0.1, 0.1, 0.1);
	glVertex2i(-200, 110);
	glVertex2i(-200, 180);
	glVertex2i(-180, 180);
	glVertex2i(-180, 110);

	//the most left middle window close
	glColor3f(0.190, 0.122, 0.133);
	glVertex2i(-200, 110);
	glVertex2i(-200, 180);
	glVertex2i(-180, 180);
	glVertex2i(-180, 110);
	//the top  first window
	glColor3f(0.1, 0.1, 0.1);
	glVertex2i(-202, 200);
	glVertex2i(-202, 300);
	glVertex2i(-178, 300);
	glVertex2i(-178, 200);
	//
	glColor3f(0.190, 0.122, 0.133);
	glVertex2i(-192, 200);
	glVertex2i(-192, 300);
	glVertex2i(-178, 300);
	glVertex2i(-178, 200);
	
	//the top  first window curve
	glColor3f(0.1, 0.1, 0.1);
	glVertex2i(-202, 300);
	glVertex2i(-196, 310);
	glVertex2i(-184, 310);
	glVertex2i(-178, 300);

	//the top  second window
	glColor3f(0.1, 0.1, 0.1);
	glVertex2i(-90, 200);
	glVertex2i(-90, 300);
	glVertex2i(-66, 300);
	glVertex2i(-66, 200);
	//
	glColor3f(0.190, 0.122, 0.133);
	glVertex2i(-80, 200);
	glVertex2i(-80, 300);
	glVertex2i(-66, 300);
	glVertex2i(-66, 200);

	//the top  second window curve
	glColor3f(0.1, 0.1, 0.1);
	glVertex2i(-90, 300);
	glVertex2i(-82, 310);
	glVertex2i(-72, 310);
	glVertex2i(-66, 300);
	//the top  thrid window
	glColor3f(0.1, 0.1, 0.1);
	glVertex2i(40, 200);
	glVertex2i(40, 300);
	glVertex2i(64, 300);
	glVertex2i(64, 200);
	//
	glColor3f(0.190, 0.122, 0.133);
	glVertex2i(50, 200);
	glVertex2i(50, 300);
	glVertex2i(64, 300);
	glVertex2i(64, 200);


	//the top  thrid window curve
	glColor3f(0.1, 0.1, 0.1);
	glVertex2i(40, 300);
	glVertex2i(48, 310);
	glVertex2i(56, 310);
	glVertex2i(64, 300);
	//wall for the top of the smallest strip in the bottom
	glColor3f(0.4, 0.2, 0.1);
	glVertex2i(-50, 0);
	glVertex2i(-50, 120);
	glVertex2i(-30, 150);
	glVertex2i(-30, -50);
	// bottom door on the wall for the top of the smallest strip
	glColor3f(0.1, 0.1, 0.1);
	glVertex2i(-48, 0);
	glVertex2i(-48, 60);
	glVertex2i(-44, 50);
	glVertex2i(-44, -10);
	// bottom door on the wall second
	glColor3f(0.1, 0.1, 0.1);
	glVertex2i(-40, -15);
	glVertex2i(-40, 50);
	glVertex2i(-36, 40);
	glVertex2i(-36, -30);
	// top door on the wall
	glColor3f(0.1, 0.1, 0.1);
	glVertex2i(-45, 65);
	glVertex2i(-45, 115);
	glVertex2i(-40, 115);
	glVertex2i(-40, 55);
	//left bottum door
	glColor3f(0.1, 0.1, 0.1);
	glVertex2i(-90, 0);
	glVertex2i(-90, 100);
	glVertex2i(-55, 100);
	glVertex2i(-55, 0);
	//left bottum door it's close
	glColor3f(0.240, 0.240, 0.125);
	glVertex2i(-85, 5);
	glVertex2i(-85, 100);
	glVertex2i(-60, 100);
	glVertex2i(-60, 5);

	glColor3f(0.1, 0.1, 0.1);
	glVertex2i(-90, 100);
	glVertex2i(-80, 115);
	glVertex2i(-65, 115);
	glVertex2i(-55, 100);
	//the red entrance
	glColor3f(0.4,0.2,0.1);
	glVertex2i(-30, -50);
	glVertex2i(-30, 150);
	glVertex2i(0, 150);
	glVertex2i(0, -50);

	//triangle for top front
	//
	glColor3f(0.2, 0.2, 0.2);
	glVertex2i(0, 160);
	glVertex2i(20, 150);
	glVertex2i(50, 150);
	glVertex2i(40, 160);
	//the green and yellow color
	glColor3f(0.2, 0.2,0.2);
	glVertex2i(40, 160);
	glVertex2i(40, 240);
	glVertex2i(50, 250);
	glVertex2i(50, 150);
	
	//front red rectangle for get in
	
	glColor3f(0.4, 0.4, 0.3);
	glVertex2i(50, -70);
	glVertex2i(50, 250);
	glVertex2i(150, 250);
	glVertex2i(150, -70);

	//open door for get in black
	glColor3f(0.1, 0.1, 0.2);
	glVertex2i(70, -70);
	glVertex2i(70, 180);
	glVertex2i(130, 180);
	glVertex2i(130, -70);

	//open door for get in black open view
	glColor3f(0.300, 0.255, 0.263);
	glVertex2i(115, -70);
	glVertex2i(115, 190);
	glVertex2i(130, 180);
	glVertex2i(130, -70);

	/////////the second half of door
	glColor3f(0.4, 0.2, 0.1);
	glVertex2i(100, -70);
	glVertex2i(100, 190);
	glVertex2i(115, 180);
	glVertex2i(115, -70);

	
	/////////the thrid half of door
	glColor3f(0.4, 0.3, 0.2);
	glVertex2i(70, -70);
	glVertex2i(70, 180);
	glVertex2i(100, 180);
	glVertex2i(100, -70);
	/////////the second half half of door
	glColor3f(0.202, 0.206, 0.210);
	glVertex2i(90, -70);
	glVertex2i(90, 170);
	glVertex2i(115, 150);
	glVertex2i(115, -70);
	//main door in black curve
	glColor3f(0.1, 0.1, 0.2);
	glVertex2i(70, 180);
	glVertex2i(90, 200);
	glVertex2i(110, 200);
	glVertex2i(130, 180);
	//
//the right most first supporter
	glColor3f(0.4, 0.2, 0.1);
	glVertex2i(140, -70);
	glVertex2i(140, 110);
	glVertex2i(160, 120);
	glVertex2i(160, -90);

	glColor3f(0.430, 0.380, 0.340);
	glVertex2i(160, 80);
	glVertex2i(160, 120);
	glVertex2i(180, 120);
	glVertex2i(180, 80);
	//it's curve
	glVertex2i(160, 120);
	glVertex2i(165, 130);
	glVertex2i(175, 130);
	glVertex2i(180, 120);
	//it's top view
	glColor3f(0.4, 0.3, 0.2);
	glVertex2i(160, 120);
	glVertex2i(165, 130);
	glVertex2i(145, 120);
	glVertex2i(140, 110);
	//the right most second supporter
	glColor3f(0.4, 0.2, 0.1);
	glVertex2i(160, -90);
	glVertex2i(160, 80);
	glVertex2i(195, 90);
	glVertex2i(200, -140);
	//the front side for the most second supporter
	glColor3f(0.430, 0.380, 0.340);
	glVertex2i(200, -140);
	glVertex2i(195, 90);
	glVertex2i(230, 90);
	glVertex2i(240, -120);
	//it's curve
	glColor3f(0.430, 0.380, 0.340);
	glVertex2i(195, 90);
	glVertex2i(205, 107);
	glVertex2i(220, 107);
	glVertex2i(230, 90);

	//it's top view
	glColor3f(0.4, 0.3, 0.2);
	glVertex2i(195, 90);
	glVertex2i(205, 107);
	glVertex2i(168, 95);
	glVertex2i(160, 80);
	//strip/dereja main door 
	glColor3f(0.300, 0.255, 0.263);
	glVertex2i(80,30);
	glVertex2i(140, 30);
	glVertex2i(140, 15);
	glVertex2i(80, 15);
	//
	glColor3f(0.480, 0.432, 0.440);
	glVertex2i(80, 15);
	glVertex2i(140, 15);
	glVertex2i(150, 5);
	glVertex2i(90, 5);
	//
	glColor3f(0.300, 0.255, 0.263);
	glVertex2i(90, 5);
	glVertex2i(150, 5);
	glVertex2i(150, -10);
	glVertex2i(90, -10);
	//
	glColor3f(0.480, 0.432, 0.440);
	glVertex2i(90, -10);
	glVertex2i(150, -10);
	glVertex2i(160, -20);
	glVertex2i(100,-20);
	//
	glColor3f(0.300, 0.255, 0.263);
	glVertex2i(100,-20);
	glVertex2i(160, -20);
	glVertex2i(160, -35);
	glVertex2i(100, -35);
	//
	glColor3f(0.480, 0.432, 0.440);
	glVertex2i(100, -35);
	glVertex2i(160, -35);
	glVertex2i(170, -45);
	glVertex2i(110, -45);
	//
	glColor3f(0.300, 0.255, 0.263);
	glVertex2i(110, -45);
	glVertex2i(170, -45);
	glVertex2i(170, -65);
	glVertex2i(110, -65);
	//
	glColor3f(0.480, 0.432, 0.440);
	glVertex2i(110, -65);
	glVertex2i(170, -65);
	glVertex2i(180, -75);
	glVertex2i(120, -75);

	//
	glColor3f(0.300, 0.255, 0.263);
	glVertex2i(120, -75);
	glVertex2i(180, -75);
	glVertex2i(180, -95);
	glVertex2i(120, -95);
	//
	glColor3f(0.480, 0.432, 0.440);
	glVertex2i(120, -95);
	glVertex2i(180, -95);
	glVertex2i(190, -105);
	glVertex2i(130, -105);
	//
	glColor3f(0.300, 0.255, 0.263);
	glVertex2i(130, -105);
	glVertex2i(190, -105);
	glVertex2i(190, -120);
	glVertex2i(130, -120);
	//
	glColor3f(0.480, 0.432, 0.440);
	glVertex2i(130, -120);
	glVertex2i(190, -120);
	glVertex2i(200, -130);
	glVertex2i(120, -130);
	//
	glColor3f(0.300, 0.255, 0.263);
	glVertex2i(120, -130);
	glVertex2i(200, -130);
	glVertex2i(200, -145);
	glVertex2i(120, -155);
	//pick
	
	//the front side road
	glColor3f(0.710, 0.503, 0.334);
	glVertex2i(130, -150);
	glVertex2i(200, -145);
	glVertex2i(390, -300);
	glVertex2i(250, -410);
	//the horizontal  road
	glColor3f(0.710, 0.503, 0.334);
	glVertex2i(190, -450);
	glVertex2i(910, 120);
	glVertex2i(1000, 80);
	glVertex2i(230, -650);
	//the horizontal extend road
	glColor3f(0.710, 0.503, 0.334);
	glVertex2i(910, 120);
	glVertex2i(1120, 400);
	glVertex2i(1180, 400);
	glVertex2i(1000, 80);



	//pick
	
	//////////////////////////////////////////////////////

	//door
	glColor3f(0.1, 0.1, 0.1);
	glVertex2i(-20, 50);
	glVertex2i(-20, 110);
	glVertex2i(0, 110);
	glVertex2i(0, 50);
	//curv for door
	glColor3f(0.1, 0.1, 0.1);
	glVertex2i(-20, 110);
	glVertex2i(-15, 115);
	glVertex2i(-4, 115);
	glVertex2i(0, 110);
	//curv for front side 
	//pick

	//the top left litle home
	glColor3f(0.300, 0.279, 0.279);
	glVertex2i(-300, 600);
	glVertex2i(-300, 720);
	glVertex2i(-200, 720);
	glVertex2i(-200, 600);
	//the top left litle home left side
	glColor3f(0.300, 0.279, 0.279);
	glVertex2i(-300, 600);
	glVertex2i(-300, 720);
	glVertex2i(-330, 740);
	glVertex2i(-330, 630);
	//it's curve
	glColor3f(0.4, 0.3, 0.2);
	glVertex2i(-300, 720);
	glVertex2i(-310, 760);
	glVertex2i(-320, 765);
	glVertex2i(-330, 740);
	//the top left litle home front side curve
	glColor3f(0.4, 0.3, 0.2);
	glVertex2i(-300, 720);
	glVertex2i(-310, 760);
	glVertex2i(-220, 760);
	glVertex2i(-200, 720);
	//the door on the top mama for left side
	glColor3f(0.1, 0.1, 0.1);
	glVertex2i(-42, 705);
	glVertex2i(-42, 775);
	glVertex2i(-35, 775);
	glVertex2i(-35, 705);
	//the door on the top mama for front side
	glColor3f(0.1, 0.1, 0.1);
	glVertex2i(18, 680);
	glVertex2i(18, 755);
	glVertex2i(25, 755);
	glVertex2i(25, 680);
	//the top mama strip for left side 
	glColor3f(0.300, 0.279, 0.279);
	glVertex2i(-100, 600);
	glVertex2i(-50, 700);
	glVertex2i(-30, 700);
	glVertex2i(-30, 600);
	//quad for front zigzags the first one
	glColor3f(0.4, 0.3, 0.2);
	glVertex2i(-205, 600);
	glVertex2i(-205, 670);
	glVertex2i(-185, 670);
	glVertex2i(-185, 600);

	//quad for front zigzags the first curve
	glColor3f(0.4, 0.3, 0.2);
	glVertex2i(-205, 670);
	glVertex2i(-198, 685);
	glVertex2i(-191, 685);
	glVertex2i(-185, 670);
	//quad for front zigzags the second one
	glColor3f(0.4, 0.3, 0.2);
	glVertex2i(-165, 600);
	glVertex2i(-165, 670);
	glVertex2i(-145, 670);
	glVertex2i(-145, 600);
	//quad for front zigzags the second curve
	glVertex2i(-165, 670);
	glVertex2i(-160, 685);
	glVertex2i(-150, 685);
	glVertex2i(-145, 670);
	//quad for front zigzags the thrid
	glColor3f(0.4, 0.3, 0.2);
	glVertex2i(-125, 600);
	glVertex2i(-125, 670);
	glVertex2i(-105, 670);
	glVertex2i(-105, 600);
	//quad for front zigzags the thrid of curve
	glColor3f(0.4, 0.3, 0.2);
	glVertex2i(-125, 670);
	glVertex2i(-120, 685);
	glVertex2i(-110, 685);
	glVertex2i(-105, 670);
	//quad for front zigzags the fourth
	glColor3f(0.4, 0.3, 0.2);
	glVertex2i(-85, 600);
	glVertex2i(-85, 670);
	glVertex2i(-65, 670);
	glVertex2i(-65, 600);
	//quad for front zigzags the thrid of curve
	glColor3f(0.4, 0.3, 0.2);
	glVertex2i(-85, 670);
	glVertex2i(-80, 685);
	glVertex2i(-70, 685);
	glVertex2i(-65, 670);
	//quad for front zigzags the fifth

	glColor3f(0.4, 0.3, 0.2);
	glVertex2i(-45, 600);
	glVertex2i(-45, 670);
	glVertex2i(-25, 670);
	glVertex2i(-25, 600);
	//quad for front zigzags the fifth of curve
	glColor3f(0.4, 0.3, 0.2);
	glVertex2i(-45, 670);
	glVertex2i(-40, 685);
	glVertex2i(-30, 685);
	glVertex2i(-25, 670);
	//quad for front zigzags the six
	glColor3f(0.4, 0.3, 0.2);
	glVertex2i(-5, 600);
	glVertex2i(-5, 670);
	glVertex2i(15, 670);
	glVertex2i(15, 600);
	//quad for front zigzags the six of curve
	glColor3f(0.4, 0.3, 0.2);
	glVertex2i(-5, 670);
	glVertex2i(0, 685);
	glVertex2i(10, 685);
	glVertex2i(15, 670);
	//quad for front zigzags the seven

	glColor3f(0.4, 0.3, 0.2);
	glVertex2i(35, 600);
	glVertex2i(35, 670);
	glVertex2i(55, 670);
	glVertex2i(55, 600);
	//quad for front zigzags the sevenof curve
	glColor3f(0.4, 0.3, 0.2);
	glVertex2i(35, 670);
	glVertex2i(40, 685);
	glVertex2i(50, 685);
	glVertex2i(55, 670);
	//quad for front zigzags the first one for the left side
	glColor3f(0.4, 0.3, 0.2);
	glVertex2i(-395, 695);
	glVertex2i(-395, 750);
	glVertex2i(-385, 740);
	glVertex2i(-385, 682);
	//it's curve
	glColor3f(0.4, 0.3, 0.2);
	glVertex2i(-395, 748);
	glVertex2i(-392, 765);
	glVertex2i(-388, 765);
	glVertex2i(-385, 740);
	//quad for front zigzags the second one for the left side
	glColor3f(0.4, 0.3, 0.2);
	glVertex2i(-380, 680);
	glVertex2i(-380, 730);
	glVertex2i(-370, 720);
	glVertex2i(-370, 665);
	//it's curve
	glColor3f(0.4, 0.3, 0.2);
	glVertex2i(-380, 730);
	glVertex2i(-377, 745);
	glVertex2i(-373, 745);
	glVertex2i(-370, 720);
	//quad for front zigzags the thrid one for the left side
	glColor3f(0.4, 0.3, 0.2);
	glVertex2i(-365, 665);
	glVertex2i(-365, 715);
	glVertex2i(-355, 705);
	glVertex2i(-355, 655);
	//it's curve
	glColor3f(0.4, 0.3, 0.2);
	glVertex2i(-365, 715);
	glVertex2i(-362, 730);
	glVertex2i(-358, 727);
	glVertex2i(-355, 705);
	//quad for front zigzags fourth one for the left side
	glColor3f(0.4, 0.3, 0.2);
	glVertex2i(-350, 650);
	glVertex2i(-350, 702);
	glVertex2i(-340, 692);
	glVertex2i(-340, 640);
	//it's curve
	glColor3f(0.4, 0.3, 0.2);
	glVertex2i(-350, 700);
	glVertex2i(-347, 717);
	glVertex2i(-343, 715);
	glVertex2i(-340, 690);
	//the window on an cylinder for the right most 
	glColor3f(0.1, 0.1, 0.1);
	glVertex2i(110, 550);
	glVertex2i(110, 650);
	glVertex2i(120, 650);
	glVertex2i(120, 550);
	glEnd();
	
	//the curve for the most front side cylinder
	glPushMatrix();
	glColor3f(0.4, 0.2, 0.1);
	glTranslatef(102, 740, 0);//for translating
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		float angle = i * 3.14 / 180;
		float x = 40 * cos(angle) + 28;
		float y = 90 * sin(angle) + 24.4;
		glVertex2f(x, y);
	}
	glEnd();
	glPopMatrix();

	//the curve for the most left side cylinder
	glPushMatrix();
	glColor3f(0.4, 0.2, 0.1);
	glTranslatef(-448, 773, 0);//for translating
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		float angle = i * 3.14 / 180;
		float x = 25 * cos(angle) + 28;
		float y = 90 * sin(angle) + 24.4;
		glVertex2f(x, y);
	}
	glEnd();
	glPopMatrix();

	//the curve for the most left side cylinder  check it???
	
	glPushMatrix();
	glColor3f(0.4, 0.2, 0.1);
	glTranslatef(-297, 775, 0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		float angle = i * 3.14 / 180;
		float x = 40 * cos(angle) + 28;
		float y = 90 * sin(angle) + 24.4;
		glVertex2f(x, y);
	}
	glEnd();
	glPopMatrix();
	
	//the right most front cylinder
	glPushMatrix();
	glColor3f(0.4, 0.2, 0.1);
	glTranslatef(-270, 780, 0);
	glRotatef(60, 1, 0, 0);
	glBegin(GL_POLYGON);
	GLUquadricObj* obj1 = gluNewQuadric();
	gluCylinder(obj1, 45.0, 55, 970, 100, 100);
	glEnd();
	glPopMatrix();

	glBegin(GL_QUADS);

	
	//the door on the top most left side cylinder
	glColor3f(0.1, 0.1, 0.1);
	glVertex2i(-440, 680);
	glVertex2i(-440, 755);
	glVertex2i(-430, 755);
	glVertex2i(-430, 680);
	///////the litle window on the left most cylinder
	glVertex2i(-440, 780);
	glVertex2i(-440, 790);
	glVertex2i(-435, 790);
	glVertex2i(-435, 780);
	///
	glVertex2i(-400, 780);
	glVertex2i(-400, 790);
	glVertex2i(-395, 790);
	glVertex2i(-395, 780);


	//the window on an cylinder for the middlemost 
	glColor3f(0.1, 0.1, 0.1);
	glVertex2i(-315, 550);
	glVertex2i(-314, 650);
	glVertex2i(-305, 650);
	glVertex2i(-305, 550);
	//the window on an cylinder for the middle second 
	glColor3f(0.1, 0.1, 0.1);
	glVertex2i(-230, 550);
	glVertex2i(-230, 650);
	glVertex2i(-240, 650);
	glVertex2i(-240, 550);
	///the litle window on the cylinder for the front side 
	glVertex2i(-240, 750);
	glVertex2i(-240, 770);
	glVertex2i(-235, 770);
	glVertex2i(-235, 750);
	//
	glVertex2i(-300, 750);
	glVertex2i(-300, 770);
	glVertex2i(-295, 770);
	glVertex2i(-295, 750);

	////the litle window for the right most cylinder
	glVertex2i(100, 720);
	glVertex2i(100, 740);
	glVertex2i(107, 740);
	glVertex2i(107, 720);
	/////
	glVertex2i(157, 720);
	glVertex2i(157, 740);
	glVertex2i(164, 740);
	glVertex2i(164, 720);


	glEnd();
	glLineWidth(2);
	glBegin(GL_LINES);
	
	glColor3f(0.1, 0.1, 0.1);

	//the horizontal line for the of the window the top one
	glVertex2i(-222, 500);
	glVertex2i(100, 500);
	//the horizontal line  left top view one
	glVertex2i(-400, 620);
	glVertex2i(-318, 534);


	//the horizontal line for the bottom of the window the bottom one
	glVertex2i(-217, 200);
	glVertex2i(40, 200);
	//

	//
	glVertex2i(-210, 200);
	glVertex2i(-210, 230);

	glVertex2i(-190, 200);
	glVertex2i(-190, 230);
	
	glVertex2i(-170, 200);
	glVertex2i(-170, 230);
	//horizontal line for the lefft most window
	glVertex2i(-210, 230);
	glVertex2i(-170, 230);
	//
	glVertex2i(-95, 200);
	glVertex2i(-95, 230);

	glVertex2i(-78, 200);
	glVertex2i(-78, 230);
	
	glVertex2i(-60, 200);
	glVertex2i(-60, 230);
	//horizontal line for the middle window
	glVertex2i(-95, 230);
	glVertex2i(-60, 230);
	glEnd();
	//////
	  // draw the man's head
	glPushMatrix();
	glTranslatef(tx1m, ty1m,0);
	glScalef(1.2, 1.5, 0);
	glColor3f(0.620, 0.319, 0.0372);
	glPushMatrix();
	glTranslatef(0, 30.7, 0);
	glutSolidSphere(5.8, 50, 50);

	glEnd();
	glPopMatrix();
	glPushMatrix();
	glBegin(GL_QUADS);
	//the man neck
	glColor3f(0.620, 0.351, 0.0992);
	glVertex2f(-2, 25);
	glVertex2f(2, 25);
	glVertex2f(2, 20);
	glVertex2f(-2, 20);
	//the man top body
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(-10.3, 20);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(10.3, 20);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(10.5, -20);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-10.5, -20);
	//the left leg
	glColor3f(0.420, 0.322, 0.210);
	glVertex2f(-10.5, -20);
	glVertex2f(0, -20);
	glVertex2f(-2, -55);
	glVertex2f(-8.0, -55);
	//the right leg
	glColor3f(0.420, 0.322, 0.210);
	glVertex2f(0, -20);
	glVertex2f(10, -20);
	glVertex2f(8.0, -55);
	glVertex2f(2, -55);
	//the left hand
	glColor3f(0.820, 0.786, 0.754);
	glVertex2f(-15, 20);
	glVertex2f(-10, 20);
	glVertex2f(-13, -20);
	glVertex2f(-18, -20);
	//the right hand
	glColor3f(0.820, 0.786, 0.754);
	glVertex2f(10, 20);
	glVertex2f(15, 20);
	glVertex2f(18, -20);
	glVertex2f(13, -20);
	glEnd();
	glPopMatrix();

	glPopMatrix();
	
	// draw the man's head
	glPushMatrix();
	glTranslatef(tx2m, ty2m, 0);
	glScalef(1.2, 1.5, 0);
	glColor3f(0.620, 0.319, 0.0372);
	glPushMatrix();
	glTranslatef(0, 30.7, 0);
	glutSolidSphere(5.8, 20, 20);
	glPopMatrix();
	
	glPushMatrix();
	glBegin(GL_QUADS);
	//the second man neck
	glColor3f(0.620, 0.351, 0.0992);
	glVertex2f(-2, 25);
	glVertex2f(2, 25);
	glVertex2f(2, 20);
	glVertex2f(-2, 20);
	//the second man top body
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(-10.3, 20);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(10.3, 20);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(10.5, -20);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-10.5, -20);
	//the left leg
	glColor3f(0.305, 0.400, 0.128);
	glVertex2f(-10.5, -20);
	glVertex2f(0, -20);
	glVertex2f(-2, -55);
	glVertex2f(-8.0, -55);
	//the right leg
	glColor3f(0.305, 0.400, 0.128);
	glVertex2f(0, -20);
	glVertex2f(10, -20);
	glVertex2f(8.0, -55);
	glVertex2f(2, -55);
	//the left hand
	glColor3f(0.820, 0.786, 0.754);
	glVertex2f(-15, 20);
	glVertex2f(-10, 20);
	glVertex2f(-13, -20);
	glVertex2f(-18, -20);
	//the right hand
	glColor3f(0.820, 0.786, 0.754);
	glVertex2f(10, 20);
	glVertex2f(15, 20);
	glVertex2f(18, -20);
	glVertex2f(13, -20);
	glEnd();
	glPopMatrix();
	glPopMatrix();
	
	//////
	glBegin(GL_QUADS);

	//the longest supporter left of the smallest strip
glColor3f(0.4, 0.2, 0.1);
glVertex2i(0, -50);
glVertex2i(0, 160);
glVertex2i(20, 150);
glVertex2i(20, -70);
//it's top front cover
glColor3f(0.430, 0.380, 0.340);
glVertex2i(20, -70);
glVertex2i(20, 150);
glVertex2i(50, 150);
glVertex2i(50, -70);
//strip /derege
glColor3f(0.300, 0.255, 0.263);
glVertex2i(-30, 50);
glVertex2i(0, 50);
glVertex2i(0, 35);
glVertex2i(-30, 35);

glColor3f(0.480, 0.432, 0.440);
glVertex2i(-30, 35);
glVertex2i(0, 35);
glVertex2i(5, 25);
glVertex2i(-25, 25);

glColor3f(0.300, 0.255, 0.263);
glVertex2i(-25, 25);
glVertex2i(5, 25);
glVertex2i(5, 10);
glVertex2i(-25, 10);

glColor3f(0.480, 0.432, 0.440);
glVertex2i(-25, 10);
glVertex2i(5, 10);
glVertex2i(10, 0);
glVertex2i(-20, 0);

glColor3f(0.300, 0.255, 0.263);
glVertex2i(-20, 0);
glVertex2i(10, 0);
glVertex2i(10, -15);
glVertex2i(-20, -15);

glColor3f(0.480, 0.432, 0.440);
glVertex2i(-20, -15);
glVertex2i(10, -15);
glVertex2i(15, -25);
glVertex2i(-15, -25);

glColor3f(0.300, 0.255, 0.263);
glVertex2i(-15, -25);
glVertex2i(15, -25);
glVertex2i(15, -40);
glVertex2i(-15, -40);

glColor3f(0.480, 0.432, 0.440);
glVertex2i(-15, -40);
glVertex2i(15, -40);
glVertex2i(20, -50);
glVertex2i(-10, -50);

glColor3f(0.300, 0.255, 0.263);
glVertex2i(-10, -50);
glVertex2i(20, -50);
glVertex2i(20, -65);
glVertex2i(-10, -65);
glColor3f(0.4, 0.2, 0.1);
glVertex2i(-30, -50);
glVertex2i(-30, 50);
glVertex2i(-15, -50);
glVertex2i(-15, -85);

glColor3f(0.430, 0.380, 0.340);
glVertex2i(-30, 50);
glVertex2i(-20, 50);
glVertex2i(-5, -50);
glVertex2i(-15, -50);

glColor3f(0.430, 0.380, 0.340);
glVertex2i(-15, -50);
glVertex2i(-5, -50);
glVertex2i(-5, -85);
glVertex2i(-15, -85);
	//the left most first supporter
	
	glColor3f(0.4, 0.2, 0.1);
	glVertex2i(20, -70);
	glVertex2i(20, 70);
	glVertex2i(80, 50);
	glVertex2i(80, -170);
	//the left most second supporter
	glVertex2i(20, 50);
	glVertex2i(20, 100);
	glVertex2i(50, 120);
	glVertex2i(50, 40);
	
	//the left front side supporter
	glColor3f(0.430, 0.380, 0.340);
	glVertex2i(50, 40);
	glVertex2i(50, 120);
	glVertex2i(100, 120);
	glVertex2i(100, 40);
//
	//Color3f(0.2, 0, 0);
	glVertex2i(80, -170);
	glVertex2i(80, 40);
	glVertex2i(130, 40);
	glVertex2i(130, -170);
	//
glColor3f(0.430, 0.380, 0.340);
glVertex2i(50, 120);
glVertex2i(60, 130);
glVertex2i(90, 130);
glVertex2i(100, 120);
//the yellow one
glColor3f(0.4, 0.2, 0.1);
glVertex2i(50, 120);
glVertex2i(60, 130);
glVertex2i(25, 110);
glVertex2i(20, 102);
//
glColor3f(0.430, 0.380, 0.340);
glVertex2i(80, 40);
glVertex2i(90, 50);
glVertex2i(120, 50);
glVertex2i(130, 40);
//the yellow seconds
glColor3f(0.4, 0.2, 0.1);
glVertex2i(80, 40);
glVertex2i(90, 50);
glVertex2i(60, 50);
glVertex2i(50, 40);

	//the field door second///////////////
	glColor3f(0.440, 0.387, 0.387);
	glVertex2i(690, -230);//start
	glVertex2i(680, 300);//top
	glVertex2i(770, 250);//2top
	glVertex2i(770, -300);//end

	//the front side look of the second door
	glColor3f(0.510, 0.439, 0.439);
	glVertex2i(770, -300);//start
	glVertex2i(770, 250);//top
	glVertex2i(790, 260);//2top
	glVertex2i(790, -280);//end
	//it's top view
	glColor3f(0.610, 0.537, 0.537);
	glVertex2i(695, 310);//start
	glVertex2i(790, 260);//top
	glVertex2i(770, 250);//2top
	glVertex2i(680, 300);//end
	glEnd();
	glPopMatrix();

	glFlush();

}
char ch;
int main(int argc, char** argv) {
	std::cout << "          \033[33m______________________________________________________________________________________\033[0m" << std::endl;
	std::cout << "          \033[33m|////////////////////////////////////GROUP MEMBERS////////////////////////////////////|\033[0m" << std::endl;
	std::cout << "          \033[33m|/////////////////**NAME*****************************ID********************///////////|\033[0m" << std::endl;
	std::cout << "          \033[33m|////////////////**1.MULUKEN GETAYE...............NSR/1584/13*************///////////|\033[0m" << std::endl;
	std::cout << "          \033[33m|////////////////**2.TILAHUN DRIBA................NSR/1584/13*************////////////|\033[0m" << std::endl;
	std::cout << "          \033[33m|////////////////**3.MALAEFIYASH BELETE...........NSR/1372/13*************////////////|\033[0m" << std::endl;
	std::cout << "          \033[33m|//////////////////////PROJECT TITLE GONDER FASILDES//////////////////////////////////|\033[0m" << std::endl;
	std::cout << "          \033[33m|_____________________________________________________________________________________|\033[0m" << std::endl;

	cout << "              \033[32m|PRESS s|S to Continue and PRESS Enter key!!!\033[0m" << endl;
	cout << "              \033[32m|PRESS b|B to About the Castel and PRESS Enter key!!!\033[0m" << endl;
	cout << "              \033[32m|PRESS d|D to Exit and PRESS Enter key!!!\033[0m" << endl;
	cin >> ch;
	switch (ch) {
	case 's':
	case 'S':
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1370, 700);
	glutCreateWindow("fasiledesGimb");
	init();
	glutDisplayFunc(display);
	//glutKeyboardFunc(keyboard);
	//glutReshapeFunc(reshape);
	glutTimerFunc(0, timer, 0);
	glutTimerFunc(0, timer2, 0);
	//glutKeyboardFunc(timer);
	glutMainLoop();
	break;
	case 'b':
	case 'B':
		cout << " \033[35mFasil Ghebbi, also known as the Fasilides Castle, is a fortress-enclosure located in the city of Gondar in Ethiopia.\n\033[0m";
		cout << " \033[35mIt was built by the Ethiopian emperor Fasilides in the 17th century.";
		cout << " \033[35mConstruction of the Fasil Ghebbi complex began during the reign of Fasilides in the early 17th century.\n\033[0m";
		cout << " \033[35mThe Fasilides Castle itself is a large stone structure with multiple levels, towers, and battlements.\n\033[0m";
		cout << " \033[35mIt is one of the most impressive buildings in the complex and is known for its unique architecture and intricate carvings.\n\033[0m";
		cout << " \033[35mThe palace was completed and expanded over several generations of Ethiopian emperors.\n\033[0m";

		break;
	case 'D':
	case 'd':
		exit(0);
		break;
	default:

		break;
		
	}
	return 0;
}