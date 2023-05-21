#include<windows.h>
#include<gl/glut.h>
#include<stdio.h>
#include<stdlib.h>
int i = 0;
const char* filename[3] = { "teaser.bmp","teaser2.bmp" ,"wp6245385.bmp" };
void init() {
	glClearColor(1, 1, 1, 0);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(60, 1, 0.01, 100);
	gluLookAt(0, 0, 2, 0, 0, 0, 0, 1, 0);
}
//

GLuint LoadTexture(const char* filename, int width, int height)
{
	GLuint texture;
	unsigned char* data;
	FILE* file;
#pragma warning(suppress : 4996).
	file = fopen(filename, "rb");  //We need to open our file
	if (file == NULL) return 0;
	data = (unsigned char*)malloc(width * height * 3);
	fread(data, width * height * 3, 1, file); // read in our file
	fclose(file);
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	free(data);
	return texture;

}

//
void FreeTexture(GLuint texture)
{
	glDeleteTextures(1, &texture); // Delete our texture, simple enough.
}


//
void timer(unsigned char key, int x, int y) {
	
	if (key = 'C'||'c') {
		i = i++;
		glutPostRedisplay();//calling reagain display function
		if (i > 2) {
			i = 0;
		}
}
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	GLuint texture1 = LoadTexture(filename[i], 256, 256);//filename[i]
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture1);
	//glColor3f(1, 0, 0);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(-1, -1, 0);
	glTexCoord2f(0, 1);
	glVertex3f(-1, 1, 0);
	glTexCoord2f(1, 1);
	glVertex3f(1, 1, 0);
	glTexCoord2f(1, 0);
	glVertex3f(1, -1, 0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	FreeTexture(texture1);
	glFlush();

}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(600, 600);
	glutCreateWindow("TextureWithkeyBoard");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(timer);
	glutMainLoop();
	return 0;
}