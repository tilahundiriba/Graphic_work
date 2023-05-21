#include <GL/glut.h>

void init() {
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 100, 0, 200);
}
void Display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1, 0, 0);
    glVertex2f(0, 0.5);
    glVertex2f(-0.4, 0);
    glVertex2f(0.4, 0);
    glColor3f(0, 1, 0);
    glVertex2f(0, -0.5);
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("line");
    glutDisplayFunc(Display);
    init();
    glutMainLoop();

    return 0;
}