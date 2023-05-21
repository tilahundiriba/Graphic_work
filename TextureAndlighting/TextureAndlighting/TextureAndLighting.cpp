#include <GL/glut.h>

void init() {
    glClearColor(1, 1, 1, 1);//seting backgroundcolor for window
    // glMatrixMode(GL_PROJECTION);
    // gluOrtho2D(-100, 100, 100,-100);

}
float x_postion = -20;
int state = 1;
void Display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glLineWidth(5);
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 0);
    glVertex2f(x_postion, 5.0);
    glColor3f(1, 0, 0);
    glVertex2f(x_postion, -5.0);
    glColor3f(0, 1, 0);
    glVertex2f(x_postion + 5.0, -5.0);
    glColor3f(0, 0, 1);
    glVertex2f(x_postion + 5.0, 5.0);
    glEnd();
    glutSwapBuffers();
}
void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-20, 20, 20, -20);
    glMatrixMode(GL_MODELVIEW);
}
void timer(int w) {
    glutTimerFunc(1000 / 60, timer, 0);
    glutPostRedisplay();//calling reagain display function
    switch (state) {
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
    }
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Simple Animation");
    glutDisplayFunc(Display);
    glutReshapeFunc(reshape);//for reshaping the size of the window
    glutTimerFunc(0, timer, 0);//timer function calling 
    init();
    glutMainLoop();

    return 0;
}