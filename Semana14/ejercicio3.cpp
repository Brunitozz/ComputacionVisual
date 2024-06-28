#include <GL/glut.h>
GLfloat xRotated, yRotated, zRotated;
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0, 0.0, -4.0);

    glPushMatrix();

    glTranslatef(0.0, -1.0, 0.0);
    glRotatef(-90, 1.0, .5, 0.0);

    glColor3f(0, 0, 0);

    glutWireCone(1.0, 2.0, 45, 3); // Parámetros: base, altura, slices, stacks

    glColor3f(0.5, 0.2, 0.5);

    glutSolidCone(1.0, 2.0, 45, 3);

    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w / (float)h, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Wireframe Cone");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    init();
    glutMainLoop();
    return 0;
}



/*cono alambrico  solido estatico 45 merdianos y 3 paralelas*/