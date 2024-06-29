#include <GL/glut.h>

GLfloat xRotated = 0.0f, yRotated = 0.0f, zRotated = 0.0f;
int lastMouseX, lastMouseY;
bool isDragging = false;

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0, 0.0, -4.0);

    glPushMatrix();
    glRotatef(xRotated, 1.0, 0.0, 0.0);
    glRotatef(yRotated, 0.0, 1.0, 0.0);
    glRotatef(zRotated, 0.0, 0.0, 1.0);

    glColor3f(0, 1, 1);

    glutWireTorus(.5, 1.0, 45, 15);

    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w / (float)h, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
}

void mouseMotion(int x, int y) {
    if (isDragging) {
        int dx = x - lastMouseX;
        int dy = y - lastMouseY;

        xRotated += dy * 0.5f;
        yRotated += dx * 0.5f;

        lastMouseX = x;
        lastMouseY = y;

        glutPostRedisplay();
    }
}

void mouseButton(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            isDragging = true;
            lastMouseX = x;
            lastMouseY = y;
        } else if (state == GLUT_UP) {
            isDragging = false;
        }
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Wireframe Teapot");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMotionFunc(mouseMotion);
    glutMouseFunc(mouseButton);
    glutMainLoop();
    return 0;
}
