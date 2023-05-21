#include <GL/glew.h>
#include <GL/glut.h>
#include<soil/soil.h>
#include <iostream>
using namespace std;

GLuint textureID; // texture object ID

void init(void)
{
    //string im = ("C:\Users\I CAN\Desktop\wired.bmp");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glEnable(GL_TEXTURE_2D); // Enables 2D Texture Mapping
    glGenTextures(1, &textureID); // Generate texture object ID
    glBindTexture(GL_TEXTURE_2D, textureID); // Bind texture to the 2D texture target
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); // Set texture environment parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // Set texture magnification filter
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR); // Set texture minification filter
    int width, height; // Texture image dimensions
    unsigned char* image = SOIL_load_image("bitmap3.bmp", &width, &height, 0, SOIL_LOAD_RGB); // Load the texture image
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image); // Specify the texture image
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, width, height, GL_RGB, GL_UNSIGNED_BYTE, image); // Build texture mipmaps
    SOIL_free_image_data(image); // Free image memory
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBindTexture(GL_TEXTURE_2D, textureID); // Bind the texture
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex2f(-0.5, -0.5);
    glTexCoord2f(1.0, 0.0); glVertex2f(0.5, -0.5);
    glTexCoord2f(1.0, 1.0); glVertex2f(0.5, 0.5);
    glTexCoord2f(0.0, 1.0); glVertex2f(-0.5, 0.5);
    glEnd();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Texture Mapping Example");
    glewInit(); // Initialize GLEW library
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}


