#include <windows.h>
#include <GL/glut.h>
void inicio()
{
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-60,100,-50,100);
    glClearColor(0.0,0.0,1.0,0.0);
}
void pantalla()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,0.0);
    //glPointSize(2.0);
    glBegin(GL_LINE_LOOP);
        glVertex3f(0.0,0.0,0.0);
        glVertex3f(40.0,0.0,0.0);
        glVertex3f(40.0,80.0,0.0);
        glVertex3f(0.0,80.0,0.0);
    glEnd();
    glFlush();
}
int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(680, 480);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Polígono creado con la función GL_LINE_LOOP uniendo puntos aleatoriamente");
    inicio();
    glutDisplayFunc(pantalla);
    glutMainLoop();
    return EXIT_SUCCESS;
}