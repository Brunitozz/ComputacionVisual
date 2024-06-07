#include <GL/glut.h>
#include <cmath>

const int numPoints = 500; // Número de puntos para dibujar cada sector
const float radius1 = 1.0f; // Radio del primer sector
const float radius2 = 1.5f; // Radio del segundo sector
const float angleStep = M_PI / 4; // Ángulo de apertura de cada sector (en radianes)

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Fondo blanco
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-2, 2, -2, 2); 
}

void drawSector(float startAngle, float endAngle, float radius) {
    glBegin(GL_LINE_STRIP);
    glVertex2f(0.0, 0.0); // Vértice en el origen
    for (int i = 0; i <= numPoints; i++) {
        float theta = startAngle + (endAngle - startAngle) * i / numPoints;
        float x = radius * cos(theta);
        float y = radius * sin(theta);
        glVertex2f(x, y);
    }
    glVertex2f(0.0, 0.0); // Volver al origen
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0); // Color rojo

    // Primer sector desde 0 a 45 grados (0 a pi/4 radianes) con radio1
    drawSector(0.0f, angleStep, radius1);

    // Segundo sector desde 180 a 225 grados (pi a pi + pi/4 radianes) con radio2
    drawSector(M_PI, M_PI + angleStep, radius2);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Dos sectores circulares");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return EXIT_SUCCESS;
}