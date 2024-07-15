#include <GL/glut.h>
#include <cmath>

const int puntos = 1000; 
const float PI = 3.14159265358979323846f;
const float escala = 0.5f;

void mostrar() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glColor3f(0, 0, 0);
    glLineWidth(2.0f); // Set line width to 2.0
    glBegin(GL_LINES);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(0.0f, -1.0f);
    glVertex2f(0.0f, 1.0f);
    glEnd();

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < puntos; ++i) {
        float angulo = i * 2 * PI / puntos;
        float radio = sin(4 * angulo);
        float x = escala * radio * sin(1 * angulo);
        float y = escala * radio * cos(3 * angulo);
        glVertex2f(x, y);
    }
    glEnd();
    glutSwapBuffers();
}

void iniciar() {
    glClearColor(1, 1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1); 
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Figura 1");
    iniciar();
    glutDisplayFunc(mostrar);
    glutMainLoop();
    return 0;
}
