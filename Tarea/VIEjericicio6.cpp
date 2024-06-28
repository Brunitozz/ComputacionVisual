#include <GL/glut.h>
#include <cmath>
#include <iostream>

using namespace std;

float L; 

float radioPequena=(sqrt(3)-3)/2;

void inicializar() {
    glClearColor(1.0, 1.0, 1.0, 1.0);  
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-5,5,-5,5);
}

void dibujarTriangulo() {
    glColor3f(1.0, 0.0, 0.0);  // Color rojo para el triángulo

    glBegin(GL_LINE_LOOP);
    glVertex2f(0,2);//A
    glVertex2f(-sqrt(3),-1); //B
    glVertex2f(sqrt(3),-1); //C
    glEnd();
}

void dibujarCircunferencia(float radio, float cx, float cy) {
    glColor3f(0.0, 0.0, 1.0);  // Color azul para las circunferencias
    glBegin(GL_LINE_LOOP);
    for (int j = 0; j < 100; ++j) {
        float theta = 2.0f * M_PI * float(j) / float(100);
        float x = radio * cosf(theta);
        float y = radio * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

void pantalla() {
    glClear(GL_COLOR_BUFFER_BIT);
    dibujarTriangulo();
    dibujarCircunferencia(2,0,0);//Grande C
    dibujarCircunferencia(radioPequena,(sqrt(3)-3)/2,(-sqrt(3)+1)/2);//Pequeña 1 c1
    dibujarCircunferencia(radioPequena,(-sqrt(3)+3)/2,(-sqrt(3)+1)/2);//Pequeña 2 c2
    dibujarCircunferencia(radioPequena, 0,(sqrt(3)+1)/(sqrt(3)+2));//Pequeña 3 c3
    glFlush();
}

int main(int argc, char **argv) {
    cout << "Ingrese el valor de L: ";
    cin >> L;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("Triangulo Equilatero y Circunferencias");
    inicializar();
    glutDisplayFunc(pantalla);
    glutMainLoop();

    return 0;
}
