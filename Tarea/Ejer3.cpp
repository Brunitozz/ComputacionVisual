#include <GL/glut.h>
#include <cmath>
#include <iostream>

using namespace std;

int xc, yc, r;

void dibujarEjes(){
	glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    // Eje X
    glVertex2i(-50, 0);
    glVertex2i(50, 0);
    // Eje Y
    glVertex2i(0, -50);
    glVertex2i(0, 50);
    glEnd();
}

void parametricCircle(int xc, int yc, int r) {
    glBegin(GL_POINTS);
    for (float theta = 0; theta < 2 * M_PI; theta += 0.01) {
        int x = xc + r * cos(theta);
        int y = yc + r * sin(theta);
        glVertex2i(x, y);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    dibujarEjes();
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(5);
    parametricCircle(xc, yc, r);
    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-50, 50, -50, 50);
}

int main(int argc, char** argv) {
    cout << "Coordenada x: ";
    cin >> xc;
    cout << "Coordenada y: ";
    cin >>yc;
    cout << "Radio de la circunferencia: ";
    cin >> r;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Circunferencia usando Ecuación Paramétrica");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
