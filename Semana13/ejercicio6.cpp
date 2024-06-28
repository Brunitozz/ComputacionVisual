#include <GL/glut.h>

void inicio()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 1.0, 1000.0); // Proyección en perspectiva
    glMatrixMode(GL_MODELVIEW);
    glClearColor(1.0, 1.0, 1.0, 0);
    glEnable(GL_DEPTH_TEST); // Habilitar prueba de profundidad
}

void pantalla()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -50.0);
    glColor3f(.0, .0, .0);
    glScalef(10.0, 10.0, 10.0);
    glutWireCube(1);
    glColor3f(.0, .0, 1.0);
    glScalef(10.0, 10.0, 10.0);
    glutSolidCube(1);
    glFlush();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(680, 480);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH); // Incluir buffer de profundidad
    glutCreateWindow("Cubo estatico");
    inicio();
    glutDisplayFunc(pantalla);
    glutMainLoop();
    return EXIT_SUCCESS;
}
