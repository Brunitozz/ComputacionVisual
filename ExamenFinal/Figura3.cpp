#include <GL/glut.h>
#include <cmath>

void inicializar() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Blanco
    glColor3f(0.0, 0.0, 0.0); // Negro para las líneas
    glLineWidth(2.0); // Grosor de las líneas
}

void mostrar() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glColor3f(0.0, 0.0, 0.0); // Negro
    glBegin(GL_LINES);
    // Eje X
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    // Eje Y
    glVertex2f(0.0f, -1.0f);
    glVertex2f(0.0f, 1.0f);
    glEnd();

    glColor3f(1.0, 0.0, 0.0); // Rojo para la curva
    int puntos = 1000;
    float radio = 0.5f;

    glBegin(GL_LINE_LOOP);
    for (int i = 0; i <= puntos; ++i) {
        float angulo = 2.0f * 3.1415f * float(i) / float(puntos);
        float x = radio * (1 - cos(6 * angulo)) * sin(7 * angulo);
        float y = radio * (1 - cos(6 * angulo)) * cos(7 * angulo);
        glVertex2f(x, y);
    }
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Figura Combinada");
    inicializar();
    glutDisplayFunc(mostrar);
    glutMainLoop();
    return 0;
}
