#include <GL/glut.h>
#include <cmath>

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 1, 0.1, 10);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);

    static float angle = 0.0f;  // Angle for rotation

    glRotatef(angle, 1.0f, 0.0f, 0.0f);  // Rotate around x-axis

    // Draw heart shape
    glColor3ub(255, 0, 0);  // Color Red
    glBegin(GL_TRIANGLES);
    for (float x = -1.139; x <= 1.139; x += 0.01) 
    {
        float delta = cbrt(x*x) * cbrt(x*x) - 4*x*x + 4;
        float y1 = (cbrt(x*x) + sqrt(delta)) / 2;
        float y2 = (cbrt(x*x) - sqrt(delta)) / 2;

        // Front face
        glVertex3f(x, y1, 0);
        glVertex3f(x, y2, 0);
        glVertex3f(0, 0, 0);

        // Back face
        glVertex3f(x, y1, -0.5);
        glVertex3f(x, y2, -0.5);
        glVertex3f(0, 0, -0.5);
    }
    glEnd();

    glFlush();
    glutSwapBuffers();

    angle += 0.5f;  // Increment rotation angle
    if (angle >= 360.0f)
        angle -= 360.0f;
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Heart Shape");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
