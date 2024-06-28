#include <GL/glut.h>
#include <cstdlib>
#include <cmath>


const int L = 200;

void drawCircleMidpoint(int xc, int yc, int r) {
    int x = 0, y = r;
    int d = 1 - r;
    while (y >= x) {
        glBegin(GL_POINTS);
        glVertex2f(xc + x, yc + y);
        glVertex2f(xc - x, yc + y);
        glVertex2f(xc + x, yc - y);
        glVertex2f(xc - x, yc - y);
        glVertex2f(xc + y, yc + x);
        glVertex2f(xc - y, yc + x);
        glVertex2f(xc + y, yc - x);
        glVertex2f(xc - y, yc - x);
        glEnd();
        x++;
        if (d <= 0) {
            d += 2 * x + 1;
        } else {
            y--;
            d += 2 * (x - y) + 1;
        }
    }
}

void drawLineMidpoint(int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = dx - dy;

    while (true) {
        glBegin(GL_POINTS);
        glVertex2f(x0, y0);
        glEnd();
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

void drawSquare(float cx, float cy, float side) {
    float halfSide = side / 2;
    glBegin(GL_LINE_LOOP);
    glVertex2f(cx - halfSide, cy - halfSide);
    glVertex2f(cx + halfSide, cy - halfSide);
    glVertex2f(cx + halfSide, cy + halfSide);
    glVertex2f(cx - halfSide, cy + halfSide);
    glEnd();
}


void drawFirstFigure() {
    drawCircleMidpoint(0, 0, L * sqrt(1.45));
    drawSquare(0, 0, L);

    drawCircleMidpoint(-L / 2, -L / 2, L / 2);
    drawCircleMidpoint(L / 2, -L / 2, L / 2);
    drawCircleMidpoint(-L / 2, L / 2, L / 2);
    drawCircleMidpoint(L / 2, L / 2, L / 2);

    drawLineMidpoint(0, 0, L * sqrt(0.72), L * sqrt(0.72));
    drawLineMidpoint(0, 0, -L * sqrt(0.72), L * sqrt(0.72));
}

void drawSecondFigure() {
    drawSquare(0, 0, 2 * L);

    drawCircleMidpoint(0, 0, L);
    drawCircleMidpoint(0, 0, L * 3 / 4);
    drawCircleMidpoint(0, 0, L / 2);
    drawCircleMidpoint(0, 0, L / 4);

    float offset = L / 7;
    drawSquare(-L + offset, -L + offset, L / 3.5);
    drawSquare(L - offset, -L + offset, L / 3.5);
    drawSquare(-L + offset, L - offset, L / 3.5);
    drawSquare(L - offset, L - offset, L / 3.5);

    float halfSide = L / 7;
    drawLineMidpoint(-L + offset + halfSide, -L, -L, -L + offset + halfSide);
    drawLineMidpoint(L - offset - halfSide, -L, L, -L + offset + halfSide);
    drawLineMidpoint(-L, L - offset - halfSide, -L + offset + halfSide, L);
    drawLineMidpoint(L - offset - halfSide, L , L, L - offset - halfSide);

    for (int i = 0; i < 4; i++) {
        float angle1 = i * M_PI / 2 + M_PI / 4; 
        float angle2 = i * M_PI / 2;           
        drawCircleMidpoint((L + L * 3 / 4) / 2 * cos(angle1), (L + L * 3 / 4) / 2 * sin(angle1), L / 8);
        drawCircleMidpoint((L * 3 / 4 + L / 2) / 2 * cos(angle2), (L * 3 / 4 + L / 2) / 2 * sin(angle2), L / 8);
        drawCircleMidpoint((L / 2 + L / 4) / 2 * cos(angle1), (L / 2 + L / 4) / 2 * sin(angle1), L / 8);
    }

    drawCircleMidpoint(L / 8, 0, L / 8);
    drawCircleMidpoint(-L / 8, 0, L / 8);
    drawCircleMidpoint(0, L / 8, L / 8);
    drawCircleMidpoint(0, -L / 8, L / 8);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Dibujar primera figura
    glPushMatrix();
    glTranslatef(-L * 1.5, 0, 0);
    drawFirstFigure();
    glPopMatrix();

    // Dibujar segunda figura
    glPushMatrix();
    glTranslatef(L * 1.5, 0, 0);
    drawSecondFigure();
    glPopMatrix();

    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.0, 0.0, 0.0);
    gluOrtho2D(-800, 800, -600, 600);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Figuras geometricas");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}


