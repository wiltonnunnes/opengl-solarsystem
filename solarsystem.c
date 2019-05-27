#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/freeglut_ext.h>

GLfloat angle, aspect;

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glutSolidSphere(1.0, 32, 16);
	glutSwapBuffers();
}

void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	angle = 5;
}

void reshape(int w, int h) {
	if (h == 0) 
		h = 1;

	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	aspect = (GLfloat) w / (GLfloat) h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(angle, aspect, 0.1, 500);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0, 80, 200, 0, 0, 0, 0, 1, 0);
}

void mouseWheel(int wheel, int direction, int x, int y) {
	angle += direction;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(angle, aspect, 0.1, 500);
}

void mouse(int button, int state, int x, int y) {
	switch (button) {
		case GLUT_LEFT_BUTTON:
			break;

		case GLUT_RIGHT_BUTTON:
			break;

		default:
	}
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseWheelFunc(mouseWheel);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}
