#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

void init(void);
void display(void);
void reshape(int, int);

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    int screenWidth = glutGet(GLUT_SCREEN_WIDTH);
    int screenHeight = glutGet(GLUT_SCREEN_HEIGHT);
    int centerX = screenWidth / 2;
    int centerY = screenHeight / 2;
    glutInitWindowPosition(centerX - 400, centerY - 300);
    glutCreateWindow("Ventana centrada");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0); // parámetros: rojo, verde, azul, alfa
    glShadeModel(GL_SMOOTH);
}
/*
void display(void) {
    GLfloat L = 10.0f, a = -5, b = -5;
    GLint cuadrados = 20;
    
    // Coordenadas iniciales del cuadrado
    GLfloat vertices[4][2] = {
        {a, b},
        {a, b + L},
        {a + L, b + L},
        {a + L, b}
    };

    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix(); // Guarda el estado actual de la matriz

    for (int i = 0; i <= cuadrados; i++) {
        glBegin(GL_LINE_LOOP);
        for (int j = 0; j < 4; j++) {
            glVertex2f(vertices[j][0], vertices[j][1]);
        }
        glEnd();

        // Calcular nuevos vértices como puntos medios
        GLfloat newVertices[4][2];
        for (int j = 0; j < 4; j++) {
            newVertices[j][0] = (vertices[j][0] + vertices[(j + 1) % 4][0]) / 2;
            newVertices[j][1] = (vertices[j][1] + vertices[(j + 1) % 4][1]) / 2;
        }

        // Copiar nuevos vértices a vertices para la siguiente iteración
        for (int j = 0; j < 4; j++) {
            vertices[j][0] = newVertices[j][0];
            vertices[j][1] = newVertices[j][1];
        }
    }

    glPopMatrix(); // Recupera el estado de la matriz
    glFlush();
}*/

void display(void) {
    GLfloat L = 10.0f, a = -5, b = -5;
    GLint cuadrados = 5 ;
    GLfloat x1 = a;
    GLfloat y1 = b;
    GLfloat x2 = x1;
    GLfloat y2 = y1 + L;
    GLfloat x3 = x1 + L;
    GLfloat y3 = y2;
    GLfloat x4 = x3;
    GLfloat y4 = y1;
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix(); // guarda el estado actual de la matriz
    
    
    for (int i = 0; i <= cuadrados; i++)
    {
        glBegin(GL_LINE_LOOP);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
        glVertex2f(x4, y4);
        GLfloat x1Save = x1;
        GLfloat y1Save = y1;
        x1 = (x1 + x2) / 2;
        y1 = (y1 + y2) / 2;
        x2 = (x2 + x3) / 2;
        y2 = (y2 + y3) / 2;
        x3 = (x3 + x4) / 2;
        y3 = (y3 + y4) / 2;
        x4 = (x4 + x1Save) / 2;
        y4 = (y4 + y1Save) / 2;
        glEnd();
    }
    

    
    glPopMatrix(); // recupera el estado de la matriz
    glFlush();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}