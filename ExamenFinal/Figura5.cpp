#include <iostream>
#include <cmath>
#include <GL/glut.h>

using namespace std;

void init(void);
void display(void);
void reshape(int, int);
void algoPuntoMedio(int, int, int, int);
void ingresoDatos(void);
void matriz();
void dibujarReflejos(int, int, int, int);

int px0, py0, px1, py1;

int main(int argc, char** argv) {
    ingresoDatos();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Algoritmo punto medio");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}

void init(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    matriz();
    glColor3f(1, 0, 0); // Color rojo para los puntos
    cout << "\tDibujo con Algoritmo DDA y reflejos" << endl;
    dibujarReflejos(px0, py0, px1, py1);  // Dibujar la línea y sus reflejos
    glPopMatrix();
    glFlush();
}

void matriz() {
    glColor3f(0, 0, 0);
    float minY = -50, maxY = 50;
    float minX = -50, maxX = 50;
    for (float i = minX; i <= maxX; i++) {
        glBegin(GL_LINES);
        // Eje X
        glVertex2f(minX, i);
        glVertex2f(maxX, i);
        // Eje Y
        glVertex2f(i, minY);
        glVertex2f(i, maxY);
        glEnd();
    }

    glLineWidth(5);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(minY, 0);
    glVertex2f(maxY, 0);
    glVertex2f(0, minX);
    glVertex2f(0, maxX);
    glEnd();
    glLineWidth(1.0);
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void algoPuntoMedio(int x0, int y0, int x1, int y1) {
    int steps, k;
    float dx, dy, xIncrement, yIncrement, x, y;
    int centerX = (x0 + x1) / 2;
    int centerY = (y0 + y1) / 2;

    dx = x1 - x0;
    dy = y1 - y0;

    if (abs(dx) > abs(dy)) {
        steps = abs(dx);
    } else {
        steps = abs(dy);
    }

    xIncrement = dx / static_cast<float>(steps);
    yIncrement = dy / static_cast<float>(steps);

    x = x0;
    y = y0;

    glBegin(GL_POINTS);
    for (k = 0; k < steps; k++) {
        if (round(x) == centerX && round(y) == centerY) {
            glEnd();
            glPointSize(10); // Tamaño mayor para el punto central
            glBegin(GL_POINTS);
            glVertex2i(round(x), round(y));
            glEnd();
            glPointSize(6); // Restaurar el tamaño de punto predeterminado
            glBegin(GL_POINTS);
        } else {
            glVertex2i(round(x), round(y));
        }
        x += xIncrement;
        y += yIncrement;
    }
    glEnd();
}

void dibujarReflejos(int x0, int y0, int x1, int y1) {
    algoPuntoMedio(x0, y0, x1, y1);
    algoPuntoMedio(-x0, y0, -x1, y1);
    algoPuntoMedio(x0, -y0, x1, -y1);
    algoPuntoMedio(-x0, -y0, -x1, -y1);
}

void ingresoDatos(void) {
    cout << "Ingrese x1: ";
    cin >> px0;
    cout << endl;
    cout << "Ingrese y1: ";
    cin >> py0;
    cout << endl;
    cout << "Ingrese x2: ";
    cin >> px1;
    cout << endl;
    cout << "Ingrese y2: ";
    cin >> py1;
    cout << endl;
}
