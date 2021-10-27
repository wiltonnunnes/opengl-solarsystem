#include <GL/glut.h>
#include <stdlib.h>

int btnCurrState = GLUT_UP, btnPrevState = GLUT_UP, x0, y0;
double angle = 45, aspect;

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	aspect = 0;
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);

	glTranslatef(0, 0, 100);

	glutWireCube(0.5);

	glutSwapBuffers();
}

void onMouse(int button, int state, int x, int y) {
	if(button == GLUT_MIDDLE_BUTTON) {
		btnCurrState = state;
		if(btnCurrState == GLUT_DOWN) {
			if(btnPrevState == GLUT_UP) {
				x0 = x;
				y0 = y;
			} else {
				int dx, dy;
				dx = x - x0;
				dy = y - y0;
			}
		}
		btnPrevState = btnCurrState;
	}
}

void setDisplayParams() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(angle, aspect, 0.1, 500);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, 0, 0, 0, 100, 0, 0, 1);
}

void reshape(int width, int height) {
	if(height == 0)
		height = 1;

	glViewport(0, 0, width, height);
    aspect = (double)width / (float)height;
    setDisplayParams();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(256, 256);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Solar system");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(onMouse);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}
