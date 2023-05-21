#include <GL/glut.h>
#include <Math.h>
// Define global variables for tracking the state of lights
bool light0Enabled = false;
bool light1Enabled = false;
GLfloat angle = -90;
GLfloat tx = cos(angle);
void init(void)
{
    GLfloat mat_ambient[] = { 0.4, 0.4, 0.4, 1.0 };
    GLfloat mat_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat mat_shininess[] = { 100.0 };
    
 
  

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);



    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);

    glEnable(GL_LIGHT0);

  
    glDisable(GL_LIGHT0);


    glEnable(GL_DEPTH_TEST);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glScalef(0.25,0.25,0);
    glutSolidSphere(1.0, 20, 16);
    glPopMatrix();
    glFlush();
}

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
void timer(int w) {

    
  
   tx= cos(angle +=0.05);
   GLfloat light_position[] = { tx, 1.0, 1.0, 0.0 };
   glLightfv(GL_LIGHT0, GL_POSITION, light_position);
   glutTimerFunc(10, timer, 0);
    glutPostRedisplay();//calling reagain display function   
  
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == '1')
    {
        // Toggle the state of light 0
        light0Enabled = !light0Enabled;

        if (light0Enabled)
            glEnable(GL_LIGHT0);
        else
            glDisable(GL_LIGHT0);
        glutPostRedisplay(); // Mark the window for redisplay
        
    
    }
   
  
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    // Register the keyboard callback function
   // glutIdleFunc(timer);
    glutTimerFunc(10, timer, 0);
    glutMainLoop();
    return 0;
}