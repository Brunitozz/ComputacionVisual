#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Global variables for window width and height
GLint windowWidth, windowHeight;

// Array of bits for the character 'F'
GLubyte rasters[] = {
   0x03, 0xc0, 0, 0, /* **** */
   0x0f, 0xf0, 0, 0, /* ******** */
   0x1e, 0x78, 0, 0, /* **** ******* */
   0x77, 0xee, 0, 0, /* *** ****** *** */
   0x6f, 0xf6, 0, 0, /* ** ******** ** */
   0xff, 0xff, 0, 0, /* **************** */
   0xff, 0xff, 0, 0, /* **************** */
   0xff, 0xff, 0, 0, /* **************** */
   0xff, 0xff, 0, 0, /* **************** */
   0x73, 0xce, 0, 0, /* *** **** *** */
   0x73, 0xce, 0, 0, /* *** **** *** */
   0x3f, 0xfc, 0, 0, /* ************ */
   0x1f, 0xf8, 0, 0, /* ********** */
   0x0f, 0xf0, 0, 0, /* ******** */
   0x03, 0xc0, 0, 0  /* **** */
};

// Initialization function
void myinit(void) {
    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
    glClearColor(0.0, 0.0, 0.0, 0.0);
}

// Display function
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    // Set pixel zoom to make pixels larger
    glPixelZoom(100.0, 100.0); // Scaling factors for x and y directions

    glRasterPos2i(50, 50);
    glBitmap(16, 16, 8.0, 8.0, 0.0, 0.0, rasters);

    glFlush();
}

// Reshape function
void myReshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, w, 0, h, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Bitmapped 'F'");
    myinit();
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
