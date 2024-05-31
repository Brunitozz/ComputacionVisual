#include <windows.h>
#include <GL/glut.h>

void inicio()
{
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-40,100,-60,100);
    glClearColor(0.0,0.0,0.0,0.0);
}
void pantalla()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_LINE_STRIP);
        glVertex2f(0.0,0.0); //Observe que el siguiente vértice no sigue la secuencia recomendada
        glVertex2f(0.0,50.0);
        glVertex2f(30.0,0.0); //Esto se debe a que debe mantener los dos últimos vértices para generar un nuevo cuadrilátero si es necesario.
        glVertex2f(30.0,50.0);
    glEnd();
    
    glFlush();
}
int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(680, 480);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Cuadrilátero graficado con función QUAD_STRIP y relleno amarillo");
    inicio();
    glutDisplayFunc(pantalla);
    glutMainLoop();
    return EXIT_SUCCESS;
}