////////////////////////////////////////////////////          
// Türk Bayraðý Hilal Kýsmý
// 
// (Sumanta Guha Experiment Lines üzerinden geliþtirildi)
// 
////////////////////////////////////////////////////

#include <GL/glew.h>
#include <GL/freeglut.h> 
#include <math.h>
#define PI 3.14159
//const float pi = 3.14159;
const float gen = 240.0;
// Drawing routine.
float ww = 0.0;
float wh = 0.0;

void drawScene(void)
{
	float kirmizi = 83.0;//83-207
	float yesil = 176.0;//176-87
	float mavi = 174.0;//174-138
	float xmerkez = 200.0;
	float ymerkez = 200.0;
	float yaricap = 100.0;
	float derece = 0.0;
	float artim = 0.25;
	kirmizi = kirmizi / 255;
	yesil = yesil / 255;
	mavi = mavi / 255;
	
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(kirmizi, yesil, mavi);
	// Draw lines.
	glLineWidth(3.0); // Default line width.
	
	kirmizi = 1.0;
	yesil = 0.0;
	mavi = 0.0;

	glColor3f(kirmizi, yesil, mavi);
	glBegin(GL_QUADS);
	glVertex3f(100.0, 100.0, 0.0);
	glVertex3f(100.0+gen*1.5, 100.0, 0.0);
	glVertex3f(100.0 + gen * 1.5, 100.0+gen, 0.0);
	glVertex3f(100.0, 100.0 + gen, 0.0);
	
	glEnd();
	glFlush();

	kirmizi = 1.0;
	yesil = 1.0;
	mavi = 1.0;
	xmerkez = 100.0+gen/2;
	ymerkez = 100.0+gen/2;
	yaricap = gen/4;

glColor3f(kirmizi, yesil, mavi);
glBegin(GL_TRIANGLES);

for (derece = 0.0;derece < 360.0;derece = derece + artim) {
	glVertex3f(xmerkez, ymerkez, 0.0);
	glVertex3f(xmerkez + yaricap * cos(derece * PI / 180), ymerkez + yaricap * sin(derece * PI / 180), 0.0);
	glVertex3f(xmerkez + yaricap * cos((derece+artim) * PI / 180), ymerkez + yaricap * sin((derece + artim) * PI / 180), 0.0);
}
glEnd();
glFlush();

kirmizi = 1.0;
yesil = 0.0;
mavi = 0.0;

xmerkez = 100.0+gen/2+gen/16;
ymerkez = 100.0+gen/2;
yaricap = gen*0.2;

/*glColor3f(kirmizi, yesil, mavi);
glBegin(GL_TRIANGLES);

for (derece = 0.0;derece < 360.0;derece = derece + artim) {
	glVertex3f(xmerkez, ymerkez, 0.0);
	glVertex3f(xmerkez + yaricap * cos(derece * PI / 180), ymerkez + yaricap * sin(derece * PI / 180), 0.0);
	glVertex3f(xmerkez + yaricap * cos((derece + artim) * PI / 180), ymerkez + yaricap * sin((derece + artim) * PI / 180), 0.0);
}
glEnd();
glFlush();*/



	//glBegin(GL_LINE_STRIP);
	//glBegin(GL_LINE_LOOP);
	//glVertex3f(20.0, 20.0, 0.0);//1. Doðru A, Son DoðruB      --1. Doðru A -gllines
	//glVertex3f(80.0, 20.0, 0.0);//1. Doðru B, 2. Doðru A      --1. Doðru B
	//glVertex3f(80.0, 80.0, 0.0);//2. Doðru B, 3. Doðru A		--2. Doðru A
	//glVertex3f(20.0, 80.0, 0.0);//3. Doðru B, 4. Doðru A		--2. Doðru B
	//glVertex3f(10.0, 50.0, 0.0);//4. Doðru B, 5. Doðru A
	/*glVertex3f(20.0, 80.0, 0.0);//3. Doðru A
	glVertex3f(80.0, 20.0, 0.0);//3. Doðru B*/

}

// Initialization routine.
void setup(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	ww = w;
	wh = h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, ww, 0.0, wh, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(0);
		break;
	default:
		break;
	}
}

// Main routine.
int main(int argc, char **argv)
{
	glutInit(&argc, argv);

	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("ILK OPENGL UYGULAMAM");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);

	glewExperimental = GL_TRUE;
	glewInit();

	setup();

	glutMainLoop();
}