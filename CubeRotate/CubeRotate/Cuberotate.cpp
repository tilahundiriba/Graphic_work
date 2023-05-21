#include <GL/glut.h>

void init() {
    glClearColor(1, 1, 1, 1);//seting backgroundcolor for window
  glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-100, 100, 100,-100);
    glEnable(GL_DEPTH_TEST);
}
//float x_postion = -20;
//int state = 1;
void Display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glLineWidth(5);
  //glTranslatef(0.0, 0.0, -180.0);//translate to the .....
  //  glRotatef(60,1,1,1);
    glutSolidCube(8);
    glBegin(GL_QUADS);
    //front
   /*  glColor3f(1.0, 1.0, 0.0);
    glVertex3f(-10.0, 10.0, 10.0);
    glVertex3f(10.0, 10.0, 10.0);
    glVertex3f(10.0, -10.0, 10.0);
    glVertex3f(-10.0, -10.0, 10.0);
  //back
  glColor3f(1.0, 0.0, 0.0);
    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, 1.0, -1.0);
    //right
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(1.0, 1.0, -1.0);
    //left
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    //top
    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, 1.0, -1.0);
    //bottom
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, -1.0);
    */ 
    glEnd();
    //glFlush();
   glutSwapBuffers();
}
void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-200, 200, 200, -200);
    glMatrixMode(GL_MODELVIEW);
}
void timer(int w) {
    glutTimerFunc(1000 / 60, timer, 0);
    glutPostRedisplay();//calling reagain display function
    /*switch (state) {
      case 1:
          if (x_postion < 10)
              x_postion += 0.15;
          else
              state = -1;
          break;
      case -1:
          if (x_postion > -10)
              x_postion -= 0.15;
          else
              state = 1;
          break;
      }*/
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Simple Animation");
    glutDisplayFunc(Display);
   // glutReshapeFunc(reshape);//for reshaping the size of the window
  //  glutTimerFunc(0, timer, 0);//timer function calling 
    init();
    glutMainLoop();

    return 0;
}