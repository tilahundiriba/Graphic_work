#include <GLFW/glfw3.h>
#include <glut.h>
void init() {
    glClearColor(1, 1, 1, 0);
    glMatrixMode(GL_PROJECTION);
    glOrtho(-10, 10, -10, 10, -10, 10);
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2i(-2, 2);
    glVertex2i(5, 5);
    glEnd();
    glFlush();

}
int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("simple");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

}