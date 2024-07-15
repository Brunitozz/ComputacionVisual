#include <GL/glut.h>
#include <cmath>

#ifndef PI
#define PI 3.14159265358979323846
#endif

const int puntos = 1000;
const float escala = 0.5f;

void dibujarEjes() {
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(-10, 0.0);
    glVertex2f(10, 0.0);
    glVertex2f(0.0, -10);
    glVertex2f(0.0, 10);
    glEnd();
}

void dibujarCurva() {
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < puntos; ++i) {
        float angulo = i * 2 * PI / puntos;
        float radio = 2 * sin(3 * angulo);
        float x = escala * radio * sin(2 * angulo);
        float y = escala * radio * cos(5 * angulo);
        glVertex2f(x, y);
    }
    glEnd();
}

void renderizar() {
    glClear(GL_COLOR_BUFFER_BIT);
    dibujarEjes();
    glLineWidth(3);
    glColor3f(1.0, 0.0, 0.0);
    dibujarCurva();
    glFlush();
}

void configurar() {
    glClearColor(1, 1, 1, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.5, 1.5, -1.5, 1.5);
    glLineWidth(2);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(400, 100);
    glutCreateWindow("Figura 2");
    configurar();
    glutDisplayFunc(renderizar);
    glutMainLoop();
    return 0;
}