#include <windows.h>
#include <GL/glut.h>
void inicio()
{
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-50,150,-50,150);
    glClearColor(0.0,0.0,1.0,0.0);
}
void pantalla()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_LINES);
        glVertex2i(0,0);
        glVertex2i(100,0);
    glEnd();
    glBegin(GL_LINES);
        glVertex2i(100,0);
        glVertex2i(100,100);
    glEnd();
    glBegin(GL_LINES);
        glVertex2i(100,100);
        glVertex2i(0,100);
    glEnd();
    glBegin(GL_LINES);
        glVertex2i(0,100);
        glVertex2i(0,0);
    glEnd();
    glFlush();
}
int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(680, 480);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Cuadrado vacío");
    inicio();
    glutDisplayFunc(pantalla);
    glutMainLoop();
    return EXIT_SUCCESS;
}