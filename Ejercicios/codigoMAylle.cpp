#include <GL/glut.h>
#include <cmath>

const int numPoints = 1000; // Número de puntos para dibujar el cardioide

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Fondo blanco
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-2, 2, -2, 2); // Define la vista ortogonal
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0); // Color rojo para el cardioide
    glBegin(GL_LINE_LOOP);
    
    for (int i = 0; i < numPoints; i++) {
        float theta = 2.0f * 3.1415926f * i / numPoints; // Ángulo en radianes
        float x = cos(theta) * (1.0f - cos(theta)); // Coordenada x del cardioide
        float y = sin(theta) * (1.0f - cos(theta)); // Coordenada y del cardioide
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
    glutCreateWindow("Cardioide");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}