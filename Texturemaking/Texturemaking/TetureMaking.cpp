
/*
=============================================
GROUP MEMBER NAME...............ID NO.
1,Tilahun Diriba ................NSR/2063/13
2,Senessa Assfa..................NSR/1872/13
3,Woinshet Anteneh...............NSR/2140/13
4,Amanuel Degu ..................NSR/0210/13
5,Siraj Anise ...................NSR/1918/13
6,Tsilat Tizazu .................NSR/2098/13
7,Eden Teklil....................NSR/0705/13
8,Yabsira Alebachew .............NSR/2189/13
=============================================
*/


#include <GL/glew.h>
#include <GL/glut.h>
#include<soil/soil.h>
GLuint textureID; // texture object ID

void init(void)
{
    //string im = ("C:\Users\I CAN\Desktop\wired.bmp");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-12.0, 15.0, -10.0, 13.0);
    glEnable(GL_TEXTURE_2D); // Enables 2D Texture Mapping
    glGenTextures(1, &textureID); // Generate texture object ID
    glBindTexture(GL_TEXTURE_2D, textureID); // Bind texture to the 2D texture target
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); // Set texture environment parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // Set texture magnification filter
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR); // Set texture minification filter
    int width, height; // Texture image dimensions
    unsigned char* image = SOIL_load_image("bitmap1.bmp", &width, &height, 0, SOIL_LOAD_RGB); // Load the texture image
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image); // Specify the texture image
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, width, height, GL_RGB, GL_UNSIGNED_BYTE, image); // Build texture mipmaps
    SOIL_free_image_data(image); // Free image memory
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBindTexture(GL_TEXTURE_2D, textureID); // Bind the texture
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex2f(-8.5, -8.5);
    glTexCoord2f(1.0, 0.0); glVertex2f(0.5, -8.5);
    glTexCoord2f(1.0, 1.0); glVertex2f(0.5, -6.5);
    glTexCoord2f(0.0, 1.0); glVertex2f(-8.5, -6.5);
    //second
    glTexCoord2f(0.0, 0.0); glVertex2f(-8.5, -6.5);
    glTexCoord2f(1.0, 0.0); glVertex2f(0.5, -6.5);
    glTexCoord2f(1.0, 1.0); glVertex2f(1.5, -5.5);
    glTexCoord2f(0.0, 1.0); glVertex2f(-7.5, -5.5);
    //
    glTexCoord2f(0.0, 0.0); glVertex2f(-7.5, -5.5);
    glTexCoord2f(1.0, 0.0); glVertex2f(1.5, -5.5);
    glTexCoord2f(1.0, 1.0); glVertex2f(1.5, -4.5);
    glTexCoord2f(0.0, 1.0); glVertex2f(-7.5, -4.5);
    //
    glTexCoord2f(0.0, 0.0); glVertex2f(-7.5, -4.5);
    glTexCoord2f(1.0, 0.0); glVertex2f(1.5, -4.5);
    glTexCoord2f(1.0, 1.0); glVertex2f(2.5, -3.5);
    glTexCoord2f(0.0, 1.0); glVertex2f(-6.5, -3.5);
    //
    glTexCoord2f(0.0, 0.0); glVertex2f(-6.5, -3.5);
    glTexCoord2f(1.0, 0.0); glVertex2f(2.5, -3.5);
    glTexCoord2f(1.0, 1.0); glVertex2f(2.5, -2.5);
    glTexCoord2f(0.0, 1.0); glVertex2f(-6.5, -2.5);
    //
    glTexCoord2f(0.0, 0.0); glVertex2f(-6.5, -2.5);
    glTexCoord2f(1.0, 0.0); glVertex2f(2.5, -2.5);
    glTexCoord2f(1.0, 1.0); glVertex2f(3.5, -1.5);
    glTexCoord2f(0.0, 1.0); glVertex2f(-5.5, -1.5);
    //
    glTexCoord2f(0.0, 0.0); glVertex2f(-5.5, -1.5);
    glTexCoord2f(1.0, 0.0); glVertex2f(3.5, -1.5);
   glTexCoord2f(1.0, 1.0); glVertex2f(3.5, 0.0);
    glTexCoord2f(0.0, 1.0); glVertex2f(-5.5, 0.0);
    //
    glTexCoord2f(0.0, 0.0); glVertex2f(-5.5, 0.0);
    glTexCoord2f(1.0, 0.0); glVertex2f(3.5, 0.0);
    glTexCoord2f(1.0, 1.0); glVertex2f(4.5, 1.0);
    glTexCoord2f(0.0, 1.0); glVertex2f(-4.5, 1.0);
    //
    glTexCoord2f(0.0, 0.0); glVertex2f(-4.5, 1.0);
    glTexCoord2f(1.0, 0.0); glVertex2f(4.5, 1.0);
    glTexCoord2f(1.0, 1.0); glVertex2f(4.5, 2.5);
    glTexCoord2f(0.0, 1.0); glVertex2f(-4.5, 2.5);
    //
    glTexCoord2f(0.0, 0.0); glVertex2f(-4.5, 2.5);
    glTexCoord2f(1.0, 0.0); glVertex2f(4.5, 2.5);
    glTexCoord2f(1.0, 1.0); glVertex2f(5.5, 3.5);
    glTexCoord2f(0.0, 1.0); glVertex2f(-3.5, 3.5);
    //
    glTexCoord2f(0.0, 0.0); glVertex2f(-3.5, 3.5);
    glTexCoord2f(1.0, 0.0); glVertex2f(5.5, 3.5);
    glTexCoord2f(1.0, 1.0); glVertex2f(5.5, 5.0);
    glTexCoord2f(0.0, 1.0); glVertex2f(-3.5, 5.0);
    //

    glEnd();
    glBegin(GL_QUADS);
    //vertical quad vertex
    glTexCoord2f(0.0, 0.0); glVertex2f(0.5, -8.5);
    glTexCoord2f(1.0, 0.0); glVertex2f(5.5, -4.5);
    glTexCoord2f(1.0, 1.0); glVertex2f(5.5, 5.0);
    glTexCoord2f(0.0, 1.0); glVertex2f(0.5, -6.5);
    glEnd();

    glPushMatrix();
    int width, height; // Texture image dimensions
    unsigned char* image = SOIL_load_image("bitmap2.bmp", &width, &height, 0, SOIL_LOAD_RGB); // Load the texture image
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image); // Specify the texture image
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, width, height, GL_RGB, GL_UNSIGNED_BYTE, image); // Build texture mipmaps
    SOIL_free_image_data(image); // Free image memory
      
        glBegin(GL_QUADS);
        //door vertex
        glTexCoord2f(0.0, 0.0); glVertex2f(-1.5, 5.0);
        glTexCoord2f(1.0, 0.0); glVertex2f(3.5, 5.0);
        glTexCoord2f(1.0, 1.0); glVertex2f(3.5, 12.0);
        glTexCoord2f(0.0, 1.0); glVertex2f(-1.5, 12.0);
        glEnd();
    
        glPopMatrix();
      
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Texture Mapping");
    glewInit(); // Initialize GLEW library
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}


