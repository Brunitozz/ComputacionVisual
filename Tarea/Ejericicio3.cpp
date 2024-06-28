#include <iostream>
#include <GL/glut.h>
#include <cmath>
#include <cstdlib>



using namespace std;

int numLados, paso;

void dibujarEstrella(int numLados, int paso){
	float* verticesX = new float[numLados];
	float* verticesY = new float[numLados];

	for(int i=0; i<numLados; ++i){
		float angulo = 2*M_PI*i / numLados;
		verticesX[i] = cos(angulo);
		verticesY[i] = sin(angulo);
	}

	glBegin(GL_LINE_LOOP);
    for(int i=0; i<numLados; ++i){
        int indice = (i*paso) % numLados;
        glVertex2f(verticesX[indice], verticesY[indice]);
    }
	glEnd();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);
    glLineWidth(2);
    dibujarEstrella(numLados,paso);
    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-0.0, 0.0, -0.0, 0.0);
}

void teclado(unsigned char key, int x, int y) {
    switch (key) {
        case '+': 
            numLados++;
            break;
        case '-': 
            if (numLados > 3) numLados--;
            break;
        case 'p': 
            paso++;
            break;
        case 'o': 
            if (paso > 1) paso--;
            break;
        case 27:
            exit(0);
            break;
    }
    glutPostRedisplay(); // Redibujar la pantalla
}
int main(int argc, char** argv) {

	cout<<"Ingrese la cantidad de lados del poligono: ";
    cin>>numLados;

    cout<<"\nIngrese la cantidad de pasos: ";
    cin>>paso;

    cout<<"Con la tecla \'+\' incrementa y con \'-\' decrementa y Esc para salir"<<endl;
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(110, 110);
    glutCreateWindow("Polígono estrellado");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(teclado);
    glutMainLoop();

    return 0;
}
