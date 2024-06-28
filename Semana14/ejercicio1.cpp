#include <GL/glut.h>
GLfloat xRotated, yRotated, zRotated;
void redisplayFunc(void)
{
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    glTranslatef(0.0, 0.0, -4.0);
    glRotatef(xRotated, 1.0, 0.0, 0.0);
    glRotatef(yRotated, 0.0, 1.0, 0.0);
    glRotatef(zRotated, 0.0, 0.0, 1.0);
    
    // Configura el color para las paredes de la esfera
    glColor3f(0.8, 0.2, 0.1); // Color rojo, ajusta según sea necesario
    
    // Dibuja la esfera en modo de alambre
    glutWireSphere(1, 45, 3);
    
    glFlush();
}



void reshapeFunc(int x, int y)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, x, y);  
}

void idleFunc(void)
{

	yRotated += 0.01;

	redisplayFunc();
}


int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 350);
	glutCreateWindow("Sphere Rotating Animation");
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	xRotated = yRotated = zRotated = 30.0;
	xRotated = 33;
	yRotated = 40;
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glutDisplayFunc(redisplayFunc);
	glutReshapeFunc(reshapeFunc);
	glutIdleFunc(idleFunc);
	glutMainLoop();
	return 0;
}