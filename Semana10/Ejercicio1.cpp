#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

void init(void);
void display(void);
void reshape(int, int);
void circulo(GLfloat, GLfloat, GLfloat);

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
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
    GLfloat L = 10.0f;
    GLfloat r = (sqrt(2) - 1) / 2 * L;
    GLfloat x1 = (sqrt(2) - 1) / 2 * L;
    GLfloat y1 = x1;
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();// guarda el estado actual de la matriz
    glLineWidth(2);

    glColor3f(0.0, 0.0, 1.0);
    circulo(0, 0, L);
    circulo(x1, y1, r);

    glPopMatrix(); // recupera el estado de la matriz
    glFlush();
}

void circulo(GLfloat h, GLfloat k, GLfloat r) {
    GLfloat x, y;
    glBegin(GL_LINE_LOOP);
    for (GLfloat ang = 0.0f; ang < 2 * M_PI; ang += 2 * M_PI / 1000) {
        x = r * cos(ang);
        y = r * sin(ang);
        glVertex2f(x + h, y + k);
    }
    glEnd();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-10.0, 10.0, -10.0 * (GLfloat)h / (GLfloat)w, 10.0 * (GLfloat)h / (GLfloat)w, -1.0, 1.0);
    else
        glOrtho(-10.0 * (GLfloat)w / (GLfloat)h, 10.0 * (GLfloat)w / (GLfloat)h, -10.0, 10.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
