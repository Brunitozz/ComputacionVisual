#include <GL/glut.h>
#include <cmath>
#include <cstdlib>
#include <utility>

const GLfloat COLOR[] = { 0.0, 0.0, 0.0 };

#define glColor3fv(color) glColor3f(color[0], color[1], color[2])

struct Punto {
    int x;
    int y;
};

void pintarPunto(int x, int y, const GLfloat color[]) {
    glColor3fv(color);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

void LINEA(Punto p, Punto q) {
    int x0 = p.x;
    int y0 = p.y;
    int x1 = q.x;
    int y1 = q.y;

    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while (true) {
        pintarPunto(x0, y0, COLOR);
        if (x0 == x1 && y0 == y1) break;
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    LINEA({50, 100}, {250, 100});  
    LINEA({50, 150}, {250, 250});  
    LINEA({20, 50}, {20, 200});    

    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(2.0);
    gluOrtho2D(0.0, 300.0, 0.0, 300.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Lineas con Punto Medio");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
