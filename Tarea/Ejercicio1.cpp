#include <iostream>
#include <cmath>
#include <GL/glut.h>

using namespace std;

void init(void);
void display(void);
void reshape(int, int);
void abasico(int, int, int, int);
void ingresoDatos(void);
void matriz();
void aBresenham(int, int, int, int);
void aDDA(int, int, int, int);

int px0, py0, px1, py1;

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Algoritmos de Dibujo");
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
    glColor3f(0, 0, 1);
    glPointSize(6);

    glColor3f(1, 0, 0);
    cout<<"\t con Algoritmo Basico"<<endl;
    abasico(2, 10, 15, 30);
    glColor3f(0, 1, 0);
    cout<<"\t con Algoritmo DDA"<<endl;
    aDDA(-2, 10, -15, 30);
    glColor3f(1, .7, 0.5);
    cout<<"\t con Algoritmo Bresenham"<<endl;
    aBresenham(-2, -10, -15, -30);

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

    // Establecer el ancho de la línea
    glLineWidth(5); // Si esto no tiene efecto, prueba con valores mayores como 1.0

    // Cambiar el color para la línea diagonal
    glColor3f(0.0, 0.0, 0.0); // Color amarillo claro

    // Dibujar la línea diagonal
    glBegin(GL_LINES);
    glVertex2f(minY, 0);
    glVertex2f(maxY, 0);

    glVertex2f(0, minX);
    glVertex2f(0, maxX);
    glEnd();

    // Restaurar el ancho de línea predeterminado si es necesario para otros dibujos
    glLineWidth(1.0); // Restaurar el ancho de línea predeterminado a 1.0 píxeles
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50.0, 50.0, -50.0, 50, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void aDDA(int x0, int y0, int x1, int y1){
    int steps, k;
    float dx, dy, xIncrement, yIncrement, x, y;

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
    glVertex2i(round(x), round(y));

    for (k = 0; k < steps; k++) {
        x += xIncrement;
        y += yIncrement;
        glVertex2i(round(x), round(y));
    }
    glEnd();
}

void aBresenham(int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = dx - dy;
    int e2;

    glBegin(GL_POINTS);
    while (true) {
        glVertex2i(x0, y0);
        if (x0 == x1 && y0 == y1) break;
        e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
    glEnd();
}

void abasico(int x0, int y0, int x1, int y1) {
    int x;
    float dx, dy, m, b, y;
    dx = x1 - x0;
    dy = y1 - y0;
    m = dy / dx;
    b = y0 - m * x0;
    y = y0;

    glBegin(GL_POINTS);
    for (x = x0; x <= x1; x++) {
        y = m * x + b;
        cout << x << " " << y << " " << static_cast<int>(ceil(y - 0.5)) << "\n";
        glVertex2f(x, static_cast<int>(ceil(y - 0.5)));
    }
    glEnd();
}

