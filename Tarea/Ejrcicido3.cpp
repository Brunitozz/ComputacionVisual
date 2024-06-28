#include <GL/glut.h>
#include <cmath>
#include <cstdio>

int radio = 100;

void plotOctants(int x, int y, int xo, int yo) {
    glVertex2f(x + xo, y + yo);
    glVertex2f(y + xo, x + yo);
    glVertex2f(y + xo, -x + yo);
    glVertex2f(x + xo, -y + yo);
    glVertex2f(-x + xo, -y + yo);
    glVertex2f(-y + xo, -x + yo);
    glVertex2f(-y + xo, x + yo);
    glVertex2f(-x + xo, y + yo);
}

void algoritmo_circunferencia_punto_medio(int r, int xo, int yo) {
    int x = 0;
    int y = r;
    int d = 1 - r;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POINTS);

    plotOctants(x, y, xo, yo);

    while (x < y) {
        if (d < 0) {
            d += 2 * x + 3;
        }
        else {
            d += 2 * (x - y) + 5;
            y--;
        }
        x++;
        plotOctants(x, y, xo, yo);
    }

    glEnd();
}

void algoritmo_circunferencia_explicita(int r, int xo, int yo) {
    float x, y;
    int r2 = r * r;

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POINTS);

    for (x = -r; x <= r; x += 0.1) {
        y = sqrt(r2 - x * x);
        glVertex2i(x + xo, y + yo);
        glVertex2i(x + xo, -y + yo);
    }

    glEnd();
}

void algoritmo_circunferencia_parametrica(int r, int xo, int yo) {
    float x, y;
    float teta = 0;
    float delta = 0.01;

    glColor3f(.0f, .0f, .0f);
    glBegin(GL_POINTS);
    while (teta < 2 * M_PI) {
        x = xo + r * cos(teta);
        y = yo + r * sin(teta);
        teta += delta;
        glVertex2i(ceil(x), ceil(y));
    }
    glEnd();
}


void init(void) {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    gluOrtho2D(-600 / 2, 600 / 2, -600 / 2, 600 / 2);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(2);
    algoritmo_circunferencia_parametrica(radio, -150, 180);
    algoritmo_circunferencia_explicita(radio, 150, 180);
    algoritmo_circunferencia_punto_medio(radio, -150, -180);

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    printf("Ingrese el valor del radio: ");
    if (scanf_s("%d", &radio) != 1 || radio <= 0) {
        printf("Valor de radio invalido. Usando valor por defecto de 100.\n");
        radio = 100;
    }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 10);
    glutCreateWindow("Circulos con los cuadrantes");

    init();

    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
