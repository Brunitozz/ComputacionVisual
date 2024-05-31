#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

void init(void);
void display(void);
void reshape(int, int);

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(250, 250);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}

void init(void) {
    glClearColor(1.0, 1.0, 1.0, 1.0); // parámetros: rojo, verde, azul, alfa
    glShadeModel(GL_SMOOTH);
}

void display(void) {
    GLfloat ang, radio = 8.0f, x, y;
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();// guarda el estado actual de la matriz

    glLineWidth(2);
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    for (ang = 0.0f; ang < 2 * M_PI; ang += 2 * M_PI / 10) {
        x = radio * sin(ang);
        y = radio * cos(ang);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix(); // recupera el estado de la matriz
    glFlush();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
