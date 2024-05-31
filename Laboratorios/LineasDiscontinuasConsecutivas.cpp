#include <windows.h>
#include <GL/glut.h>
void inicio()
{
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-50,100,-50,100);
    glClearColor(0.0,0.0,1.0,0.0);
}
void pantalla()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,0.0);
    glLineWidth(5);
    glBegin(GL_LINES);
        glVertex2f(0.0,0.0);
        glVertex2f(0.0,40.0);
        glVertex2f(0.0,80.0);
        glVertex2f(20.0,80.0);
        glVertex2f(40.0,80.0);
        glVertex2f(40.0,40.0);
        glVertex2f(40.0,0.0);
        glVertex2f(20.0,0.0);
    glEnd();
    glFlush();
}
int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(680, 480);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Lineas discontinuas consecutivas");
    inicio();
    glutDisplayFunc(pantalla);
    glutMainLoop();
    return EXIT_SUCCESS;
}