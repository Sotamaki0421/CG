/* List: p3-planet.c
* The planet turns around the sun.
* Examination of world-local coordinates, modeling transfomation and
* operation of matrix stack.
*/
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/gl.h>

static double year = 0.0, day = 0.0;
static double Earthsize = 0.2;
static double Earthdis = 3.5;

void myInit(char *progname)
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(1400, 700);
	glutInitWindowPosition(0, 0);
	glutCreateWindow(progname);
	glClearColor(0.0, 0.0, 0.0, 0.0);
}


void myDisplay(void)
{
	
	glEnable(GL_DEPTH_TEST);

	float light0_position[4] = { 0.0, -2.1, 0.0, 1.0 };

	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
	glEnable(GL_LIGHT0);

	glColor3d(1.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutSolidSphere(2.0, 20, 20);  /* sun */

	glPushMatrix();
		glColor3d(0.8, 0.8, 0.8);
		glRotated((double)year/0.241, 0.0, 1.0, 0.0);
		glTranslated(2.5, 0.0, 0.0);
		glRotated((double)day/58.65, 0.0, 1.0, 0.0);
		glutSolidSphere(Earthsize*0.38, 10, 8);    /* Mercury */
	glPopMatrix();

	glPushMatrix();
		glColor3d(1.0, 0.6, 0.0);
		glRotated((double)year/0.615, 0.0, 1.0, 0.0);
		glTranslated(4.5, 0.0, 0.0);
		glRotated((double)day/243, 0.0, 1.0, 0.0);
		glutSolidSphere(Earthsize*0.95, 10, 8);    /* Venus */

	glPopMatrix();

	glPushMatrix();
		glColor3d(0.0, 0.0, 1.0);
		glRotated((double)year, 0.0, 1.0, 0.0);
		glTranslated(6.5, 0.0, 0.0);
		glRotated((double)day, 1.0, 3.0, 0.0);
		glutSolidSphere(Earthsize, 10, 8);    /* Earth */
		glPushMatrix();
			glColor3d(0.8, 0.8, 0.8);
			glRotated((double)day/27, 0.0, 1.0, 0.0);
			glTranslated(0.5, 0.0, 0.0);
			glRotated((double)day/27, 0.0, 1.0, 0.0);
			glutSolidSphere(Earthsize*0.27, 10, 8);    /* Moon */
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		glColor3d(0.6, 0.2, 0.0);
		glRotated((double)year/1.881, 0.0, 1.0, 0.0);
		glTranslated(8.5, 0.0, 0.0);
		glRotated((double)day/1.026, 0.0, 1.0, 0.0);
		glutSolidSphere(Earthsize*0.53, 10, 8);    /* Mars */

		glPushMatrix();
			glColor3d(1.0, 1.0, 1.0);
			glRotated((double)day/24*7.5, 0.0, 1.0, 0.0);
			glTranslated(0.3, 0.0, 0.0);
			glRotated((double)day / 24 * 7.5, 0.0, 1.0, 0.0);
			glutSolidSphere(Earthsize * 0.33, 10, 8);    /* Phobos */
		glPopMatrix();

		glPushMatrix();
			glColor3d(0.8, 0.8, 0.8);
			glRotated((double)day/24*30, 0.0, 1.0, 0.0);
			glTranslated(0.6, 0.0, 0.0);
			glRotated((double)day / 24 * 30, 0.0, 1.0, 0.0);
			glutSolidSphere(Earthsize * 0.23, 10, 8);    /* Deioms */
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		glColor3d(0.8, 0.7, 0.6);
		glRotated((double)year / 12, 0.0, 1.0, 0.0);
		glTranslated(10.5, 0.0, 0.0);
		glRotated((double)day*9.8/24, 0.0, 1.0, 0.0);
		glutSolidSphere(Earthsize*5.6, 20, 8);    /* Jupiter */

		glPushMatrix();
			glColor3d(1.0, 1.0, 0.0);
			glRotated((double)day / 0.005, 0.0, 1.0, 0.0);
			glTranslated(1.4, 0.0, 0.0);
			glRotated((double)day / 0.005, 0.0, 1.0, 0.0);
			glutSolidSphere(Earthsize * 0.33, 10, 8);    /* Io */
		glPopMatrix();

		glPushMatrix();
			glColor3d(0.8, 0.7, 0.6);
			glRotated((double)day / 0.01, 0.0, 1.0, 0.0);
			glTranslated(1.6, 0.0, 0.0);
			glRotated((double)day / 0.01, 0.0, 1.0, 0.0);
			glutSolidSphere(Earthsize * 0.23, 10, 8);    /* Europa */
		glPopMatrix();

		glPushMatrix();
		glColor3d(0.8, 0.8, 0.8);
			glRotated((double)day / 0.04, 0.0, 1.0, 0.0);
			glTranslated(1.8, 0.0, 0.0);
			glRotated((double)day / 0.04, 0.0, 1.0, 0.0);
			glutSolidSphere(Earthsize * 0.33, 10, 8);    /* Ganymede */
		glPopMatrix();

		glPushMatrix();
			glColor3d(0.2, 1.0, 0.2);
			glRotated((double)day / 0.045, 0.0, 1.0, 0.0);
			glTranslated(2.0, 0.0, 0.0);
			glRotated((double)day / 0.045, 0.0, 1.0, 0.0);
			glutSolidSphere(Earthsize * 0.23, 10, 8);    /* Callisto */
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		glColor3d(0.9, 0.8, 0.5);
		glRotated((double)year / 30, 0.0, 1.0, 0.0);
		glTranslated(14.5, 0.0, 0.0);
		glRotated((double)day*10.2/24, -2.0, 4.0, 0.0);
		glutSolidSphere(Earthsize*4.72, 20, 8);    /* Saturn */
		glPushMatrix();
			glColor3d(0.9, 0.8, 0.5);
			glRotated(90.0, 1.0, 0.0, 0.0);
			glRotated(30, -2.0, 4.0, 0.0);
			glScaled(1.0, 1.0, 0.05);
			glutSolidTorus(0.2, Earthsize* 7.0, 100.0, 100.0); /*トーラス環*/
		glPopMatrix();
		glPushMatrix();
			glColor3d(0.2, 1.0, 0.5);
			glRotated((double)day / 16.5, 0.0, 1.0, 0.0);
			glTranslated(1.4, 0.0, 0.0);
			glRotated((double)day / 16.5, 0.0, 1.0, 0.0);
			glutSolidSphere(Earthsize * 0.5, 10, 8);    /* Titan */
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		glColor3d(0.35, 0.7, 0.7);
		glRotated((double)year / 84, 0.0, 1.0, 0.0);
		glTranslated(17.5, 0.0, 0.0);
		glRotated((double)day*17.9/24, 0.0, 1.0, 0.0);
		glutSolidSphere(Earthsize*2.0, 10, 8);    /* Uranus */
		glPushMatrix();
			glColor3d(0.8, 0.8, 0.8);
			glRotated((double)day / 0.024, 0.0, 1.0, 0.0);
			glTranslated(1.0, 0.0, 0.0);
			glRotated((double)day / 0.024, 0.0, 1.0, 0.0);
			glutSolidSphere(Earthsize* 0.5, 10, 8);    /* Titania */
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		glColor3d(0.5, 0.5, 0.8);
		glRotated((double)year/165, 0.0, 1.0, 0.0);
		glTranslated(19.5, 0.0, 0.0);
		glRotated((double)day*19.1/24, -2.0, 4.0, 0.0);
		glutSolidSphere(Earthsize*1.9, 10, 8);    /* Neptune */

		glPushMatrix();
			glColor3d(0.8, 0.8, 0.8);
			glRotated((double)day / 0.016, 0.0, 1.0, 0.0);
			glTranslated(1.0, 0.0, 0.0);
			glRotated((double)day / 0.016, 0.0, 1.0, 0.0);
			glutSolidSphere(Earthsize* 0.5, 10, 8);    /* Triton */
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		glColor3d(0.8, 0.7, 0.6);
		glRotated((double)year / 248, 1.0, 4.0, 0.0);
		glTranslated(21.5, -4.0, 0.0);
		glRotated((double)day * 19.1 / 24, 0.0, 1.0, 0.0);
		glutSolidSphere(Earthsize * 0.19, 10, 8);    /* Pluto */
	glPopMatrix();
	
	glutSwapBuffers();
}

void myReshape(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (double)width / (double)height, 0.1, 120.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//gluLookAt(0.0, 50.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0); /* 真上 */
	gluLookAt(0.0, 15.0, 15.0, 0.0, 0.0, 0.0, 0.0, 10.0, 0.0); /* 斜め上 */
	//gluLookAt(0.0, 0.0, 30.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);/* 真横 */
}

void myIdle(void)
{
	year = year + 0.05;
	day = day + 0.1;
	glutPostRedisplay();
}

void myKeyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 'd':
		day = (day + 10.0);
		glutPostRedisplay();
		break;
	case 'D':
		day = (day - 10.0);
		glutPostRedisplay();
		break;
	case 'y':
		year = (year + 5.0);
		glutPostRedisplay();
		break;
	case 'Y':
		year = (year - 5.0);
		glutPostRedisplay();
		break;
	case 27:
		exit(0);
		break;
	default:
		break;
	}
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	myInit(argv[0]);
	glutKeyboardFunc(myKeyboard);
	glutIdleFunc(myIdle);
	glutReshapeFunc(myReshape);
	glutDisplayFunc(myDisplay);
	glutMainLoop();
	return 0;
}
